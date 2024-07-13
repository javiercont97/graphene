#include "PaginatedView.h"

void Graphene::PaginatedView::addPage(IContainer* view) {
	view->setBounds(Rect(0 + this->leftPadding,
						 0 + this->topPadding,
						 this->bounds.getWidth() - this->leftPadding - this->rightPadding,
						 this->bounds.getHeight() - this->topPadding - this->bottomPadding));
	this->children.push_back(view);
	if (this->children.size() == 1) {
		this->setPage(0);
	}
	this->updateLayout();
}

void Graphene::PaginatedView::setPage(int index) {
	if (index < 0 || index >= (int)this->children.size()) {
		return;
	}

	for(auto child : this->children) {
		child->setVisible(false);
	}
	this->children.at(index)->setVisible(true);

	this->currentPage = index;
	this->updateLayout();
}

void Graphene::PaginatedView::draw(AbstractCanvas& canvas) {
	if (this->currentPage == -1) {
		return;
	}
	this->children.at(this->currentPage)->draw(canvas);
}

bool Graphene::PaginatedView::needsRedraw() const {
	if (this->currentPage == -1) {
		return false;
	}
	return this->children.at(this->currentPage)->needsRedraw();
}
