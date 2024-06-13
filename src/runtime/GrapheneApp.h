#if !defined(GRAPHENE_APP_INTERFACE_H)
#define GRAPHENE_APP_INTERFACE_H

#include "../interfaces/AbstractCanvas.h"
#include "../interfaces/AbstractTouchInput.h"
#include "../interfaces/IContainer.h"

namespace Graphene {

class GrapheneApp {
   public:
	GrapheneApp(AbstractCanvas *canvas, AbstractTouchInput *touchInput, IContainer *rootContainer);
	virtual ~GrapheneApp();
	void eventLoop();

	std::vector<TouchEvent> processTouchEvents(std::vector<Point> points);

   protected:
	AbstractCanvas *canvas;
	AbstractTouchInput *touchInput;
	IContainer *rootContainer;

	std::vector<TouchEvent> prevTouchEvents;
};

}  // namespace Graphene

#endif	// GRAPHENE_APP_INTERFACE_H
