#include <Graphene.h>

#include "MainView.h"

class NoTouchScreenDriver : public Graphene::AbstractTouchInput {
   public:
	// Inherited from AbstractTouchInput
	virtual std::vector<Graphene::Point> getTouchPoints() {
		return {};
	};
};

int main() {
	Graphene::Image screenDriver(800, 480);
	NoTouchScreenDriver touchScreenDriver;

	MainView mainView(screenDriver.getBounds());

	Graphene::GrapheneApp app(&screenDriver, &touchScreenDriver, &mainView);

	screenDriver.clear(Graphene::DARK_GRAY);
	app.eventLoop();  // Render the UI

	screenDriver.exportTo("gui.ppm", Graphene::ImageFormat::PPM_P3);
	return 0;
}