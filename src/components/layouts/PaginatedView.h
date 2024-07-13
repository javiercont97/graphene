#if !defined(GRAPHENE_STACK_VIEW_H)
#define GRAPHENE_STACK_VIEW_H

#include "../../interfaces/IContainer.h"

namespace Graphene {

class PaginatedView : public IContainer {
   public:
	PaginatedView(Color bgColor, IContainer *parent) : IContainer(bgColor, parent) {
	}

	PaginatedView(int padding, Color bgColor, IContainer *parent = nullptr) : IContainer(bgColor, parent) {
		this->topPadding = padding;
		this->rightPadding = padding;
		this->bottomPadding = padding;
		this->leftPadding = padding;
	}
	
	void addPage(IContainer *view);
	void setPage(int index);
	int getCurrentPage() const {
		return this->currentPage;
	}

	// Inherited via IContainer
	virtual void draw(AbstractCanvas &canvas) override;
	virtual bool needsRedraw() const override;

   private:
	int currentPage = -1;
};

}  // namespace Graphene

#endif	// GRAPHENE_STACK_VIEW_H
