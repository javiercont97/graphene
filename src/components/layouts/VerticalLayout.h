#if !defined(GRAPHENE_VERTICAL_LAYOUT_H)
#define GRAPHENE_VERTICAL_LAYOUT_H

#include "../../interfaces/IContainer.h"

namespace Graphene {
class VerticalLayout : public IContainer {
   public:
	VerticalLayout(IContainer *parent = nullptr) : IContainer(parent){};

	// Inherited via IContainer
	virtual void updateLayout() override;

   protected:
};
}  // namespace Graphene

#endif	// GRAPHENE_VERTICAL_LAYOUT_H
