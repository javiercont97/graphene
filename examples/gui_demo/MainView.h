#if !defined(MAIN_VIEW_H)
#define MAIN_VIEW_H

#include <Graphene.h>

class MainView : public Graphene::HorizontalLayout {
   public:
	MainView(Graphene::Rect bounds);
	~MainView();

	void setupUI();

	// Graphene::Button *button1;
	// Graphene::Button *button2;
	// Graphene::Button *button3;

   private:
	Graphene::VerticalLayout *controllersLayout;
	Graphene::Button *increaseBtn;
	Graphene::Button *decreaseBtn;

	Graphene::Label *counterLabel;

	int counter = 0;
};

#endif	// MAIN_VIEW_H
