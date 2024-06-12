#if !defined(GRAPHENE_LAYOUT_INTERFACE_H)
#define GRAPHENE_LAYOUT_INTERFACE_H

#include "IDrawable.h"

namespace Graphene {
class IContainer : public IDrawable {
   public:
	IContainer(IContainer *parent = nullptr) : IDrawable(parent){};

	void add(IDrawable *drawable);
	void remove(IDrawable *drawable);
	void clear();

	IDrawable *getChildAt(int index) {
		return children.at(index);
	}

	virtual void updateLayout() = 0;

	// Inherited via IDrawable
	virtual void draw(AbstractCanvas &canvas) override;

	virtual void onTouchEvent(TouchEvent *event) override;

	void setBounds(Rect bounds) override;
	void setStretchX(uint8_t stretchX) override;
	void setStretchY(uint8_t stretchY) override;

	// getters and setters
	int getSpacing() const;
	void setSpacing(int spacing);
	int getTopPadding() const;
	void setTopPadding(int topPadding);
	int getRightPadding() const;
	void setRightPadding(int rightPadding);
	int getBottomPadding() const;
	void setBottomPadding(int bottomPadding);
	int getLeftPadding() const;
	void setLeftPadding(int leftPadding);

   protected:
	std::vector<IDrawable *> children;

	int topPadding = 0;
	int rightPadding = 0;
	int bottomPadding = 0;
	int leftPadding = 0;

	int spacing = 0;
};
}  // namespace Graphene

#endif	// GRAPHENE_LAYOUT_INTERFACE_H
