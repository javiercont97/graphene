#include "MainView.h"

MainView::MainView(Graphene::Rect bounds) : Graphene::HorizontalLayout() {
	this->setBounds(bounds);

	// set spacing and padding
	this->setSpacing(10);
	this->setTopPadding(120);
	this->setBottomPadding(120);
	this->setLeftPadding(50);
	this->setRightPadding(50);

	setupUI();
}

MainView::~MainView() {
	delete controllersLayout;
	delete increaseBtn;
	delete decreaseBtn;
	delete counterLabel;
}

void MainView::setupUI() {
	controllersLayout = new Graphene::VerticalLayout(this);

	increaseBtn = new Graphene::Button(controllersLayout);
	increaseBtn->setText("+");
	increaseBtn->setBackgroundColor(Graphene::WHITE);
	increaseBtn->setTextColor(Graphene::BLACK);
	controllersLayout->add(increaseBtn);

	decreaseBtn = new Graphene::Button(controllersLayout);
	decreaseBtn->setText("-");
	decreaseBtn->setBackgroundColor(Graphene::WHITE);
	decreaseBtn->setTextColor(Graphene::BLACK);
	controllersLayout->add(decreaseBtn);

	counterLabel = new Graphene::Label(this);
	counterLabel->setText("0");
	counterLabel->setBackgroundColor(Graphene::DARK_GRAY);
	counterLabel->setTextColor(Graphene::WHITE);

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
