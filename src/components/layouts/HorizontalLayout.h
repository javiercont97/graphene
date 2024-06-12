#if !defined(GRAPHENE_HORIZONTAL_LAYOUT_H)
#define GRAPHENE_HORIZONTAL_LAYOUT_H

#include "../../interfaces/IContainer.h"

namespace Graphene {

class HorizontalLayout : public IContainer {
   public:
	HorizontalLayout(IContainer *parent = nullptr) : IContainer(parent) {
	}

	HorizontalLayout(int padding, int spacing, IContainer *parent = nullptr) : IContainer(parent) {
		this->padding = padding;
		this->spacing = spacing;
	}

	// Inherited via IContainer
	virtual void updateLayout() override;
};

}  // namespace Graphene

#endif	// GRAPHENE_HORIZONTAL_LAYOUT_H
