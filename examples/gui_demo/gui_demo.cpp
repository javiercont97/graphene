#include <Graphene.h>
#include <mbed.h>

class MainView : public Graphene::HorizontalLayout {
   public:
	MainView(Graphene::Rect bounds) {
		this->setBounds(bounds);

		// set spacing and padding
		this->setSpacing(10);
		this->setTopPadding(120);
		this->setBottomPadding(120);
		this->setLeftPadding(50);
		this->setRightPadding(50);

		setupUI();
	}

	~MainView() {
		delete controllersLayout;
		delete increaseBtn;
		delete decreaseBtn;
		delete counterLabel;
	}

	void setupUI() {
		controllersLayout = new Graphene::VerticalLayout(this);
		controllersLayout->setSpacing(10);

		increaseBtn = new Graphene::Button("+",
										   Graphene::Font(Graphene::ubuntu_light_16_table, 16, 16),
										   Graphene::BLACK,
										   Graphene::WHITE,
										   Graphene::WHITE,
										   controllersLayout);
		controllersLayout->add(increaseBtn);

		decreaseBtn = new Graphene::Button("-",
										   Graphene::Font(Graphene::ubuntu_light_16_table, 16, 16),
										   Graphene::BLACK,
										   Graphene::WHITE,
										   Graphene::WHITE,
										   controllersLayout);
		controllersLayout->add(decreaseBtn);

		counterLabel = new Graphene::Label(
			"0", Graphene::Font(Graphene::ubuntu_light_16_table, 16, 16), Graphene::WHITE, Graphene::DARK_GRAY, this);

		this->add(controllersLayout);
		this->add(counterLabel);

		increaseBtn->onTap([&]() {
			counter++;
			Graphene::String str = Graphene::String::fromInt(counter);
			counterLabel->setText(str);
		});

		decreaseBtn->onTap([&]() {
			counter--;
			Graphene::String str = Graphene::String::fromInt(counter);
			counterLabel->setText(str);
		});
	}

   private:
	Graphene::VerticalLayout *controllersLayout;
	Graphene::Button *increaseBtn;
	Graphene::Button *decreaseBtn;

	Graphene::Label *counterLabel;

	int counter = 0;
};

void splashScreen(GrapheneDrivers::STM32F769I_Canvas screenDriver) {
	screenDriver.clear(Graphene::NAVY);
	screenDriver.drawString(screenDriver.getBounds().getCenter(),
							"STM32F769I-DISCO",
							Graphene::WHITE,
							Graphene::NAVY,
							Graphene::Font(Graphene::ubuntu_light_16_table, 16, 16),
							Graphene::TextAlignment::CENTER);

	screenDriver.drawString(
		{screenDriver.getBounds().getCenter().getX(), screenDriver.getBounds().getCenter().getY() + 35},
		"Graphene",
		Graphene::WHITE,
		Graphene::NAVY,
		Graphene::Font(Graphene::ubuntu_light_16_table, 16, 16),
		Graphene::TextAlignment::CENTER);
}

void uiThread() {
	GrapheneDrivers::STM32F769I_Canvas screenDriver;
	GrapheneDrivers::STM32F769I_Touch touchScreenDriver;
	splashScreen(screenDriver);
	ThisThread::sleep_for(2500);  // show splash screen for 2.5 seconds

	MainView mainView(screenDriver.getBounds());

	Graphene::GrapheneApp app(&screenDriver, &touchScreenDriver, &mainView);

	while (1) {
		screenDriver.clear(Graphene::DARK_GRAY);
		app.eventLoop();
		ThisThread::sleep_for(33);	// 30 fps (33ms per frame)
	}
}

int main() {
	Thread uiThreadHandle(osPriorityNormal, 4096, nullptr, "uiThread");
	uiThreadHandle.start(uiThread);

	while (true) {
		ThisThread::yield();
	}
}