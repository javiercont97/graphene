#if !defined(GRAPHENE_HORIZONTAL_LAYOUT_H)
#define GRAPHENE_HORIZONTAL_LAYOUT_H

#include "../../interfaces/IContainer.h"

namespace Graphene {

class HorizontalLayout : public IContainer {
   public:
	HorizontalLayout(IContainer *parent = nullptr) : IContainer(parent) {
	}

	HorizontalLayout(int padding, int spacing, IContainer *parent = nullptr)
		: IContainer(parent), padding(padding), spacing(spacing) {
	}

	// getters and setters
	int getPadding() const {
		return padding;
	}

	void setPadding(int padding) {
		this->padding = padding;
		updateLayout();
	}

	int getSpacing() const {
		return spacing;
	}

	void setSpacing(int spacing) {
		this->spacing = spacing;
		updateLayout();
	}

	// Inherited via IContainer
	virtual void updateLayout() override;

   protected:
	int padding = 0;
	int spacing = 0;
};

}  // namespace Graphene

#endif	// GRAPHENE_HORIZONTAL_LAYOUT_H
