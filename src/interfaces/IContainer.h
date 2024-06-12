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

   protected:
	std::vector<IDrawable *> children;
};
}  // namespace Graphene

#endif	// GRAPHENE_LAYOUT_INTERFACE_H
