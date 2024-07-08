#if !defined(GRAPHENE_HORIZONTAL_LAYOUT_H)
#define GRAPHENE_HORIZONTAL_LAYOUT_H

#include "../../interfaces/IContainer.h"

namespace Graphene {

class HorizontalLayout : public IContainer {
   public:
	HorizontalLayout(Graphene::Color bgColor, IContainer *parent = nullptr) : IContainer(bgColor, parent) {
	}

	HorizontalLayout(int padding, int spacing, Graphene::Color bgColor, IContainer *parent = nullptr)
		: IContainer(bgColor, parent) {
		this->topPadding = padding;
		this->rightPadding = padding;
		this->bottomPadding = padding;
		this->leftPadding = padding;
		this->spacing = spacing;
	}

	// Inherited via IContainer
	virtual void updateLayout() override;
};

}  // namespace Graphene

#endif	// GRAPHENE_HORIZONTAL_LAYOUT_H
