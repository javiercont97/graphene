#if !defined(GRAPHENE_APP_INTERFACE_H)
#define GRAPHENE_APP_INTERFACE_H

#include <map>

#include "../core/Font.h"
#include "../core/String.h"
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

	std::vector<Graphene::String> getSystemFonts() {
		std::vector<Graphene::String> fontNames = {};
		for (auto &pair : GrapheneSystemFonts) {
			fontNames.push_back(pair.first);
		}
		return fontNames;
	}

	Graphene::Font &getSystemFont(Graphene::String fontName) {
		return GrapheneSystemFonts[fontName];
	}

   protected:
	AbstractCanvas *canvas;
	AbstractTouchInput *touchInput;
	IContainer *rootContainer;

	bool hasPrevTouchEvent = false;
	Graphene::TouchEvent prevTouchEvent;

   private:
	std::map<Graphene::String, Graphene::Font> GrapheneSystemFonts;
};

}  // namespace Graphene

#endif	// GRAPHENE_APP_INTERFACE_H
