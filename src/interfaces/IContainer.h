#if !defined(GRAPHENE_LAYOUT_INTERFACE_H)
#define GRAPHENE_LAYOUT_INTERFACE_H

#include "../core/Color.h"
#include "IDrawable.h"

namespace Graphene {
class IContainer : public IDrawable {
   public:
	IContainer(Graphene::Color bgColor, IContainer *parent = nullptr) : IDrawable(parent), children({}), backgroundColor(bgColor) {};
	~IContainer() {
	}

	void add(IDrawable *drawable);
	void remove(IDrawable *drawable);
	void clear();

	IDrawable *getChildAt(int index) {
		return children.at(index);
	}

	virtual void updateLayout();

	// Inherited via IDrawable
	virtual void draw(AbstractCanvas &canvas) override;
	virtual bool needsRedraw() const override;
	virtual void forceRedraw() override;

	virtual void onTouchEvent(TouchEvent *event) override;

	virtual void setBounds(Rect bounds) override;
	virtual void setStretchX(uint8_t stretchX) override;
	virtual void setStretchY(uint8_t stretchY) override;

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
	Graphene::Color getBackgroundColor() const;
	void setBackgroundColor(Graphene::Color color);

   protected:
	std::vector<IDrawable *> children;
   	Graphene::Color backgroundColor;

	int topPadding = 0;
	int rightPadding = 0;
	int bottomPadding = 0;
	int leftPadding = 0;

	int spacing = 0;
};
}  // namespace Graphene

#endif	// GRAPHENE_LAYOUT_INTERFACE_H
