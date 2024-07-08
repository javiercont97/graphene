#include "HorizontalLayout.h"

void Graphene::HorizontalLayout::updateLayout() {
	// calculate the total stretch value
	int totalStretch = 0;
	for (auto child : children) {
		totalStretch += child->getStretchX();
	}

	// remaining space after padding and spacing
	int remainingSpace = bounds.getWidth() - leftPadding - rightPadding - spacing * (children.size() - 1);

	// calculate and apply the width of each child
	int x = bounds.getX() + leftPadding;
	for (auto child : children) {
		int childWidth = remainingSpace * child->getStretchX() / totalStretch;
		child->setBounds(
			Rect(x, bounds.getY() + topPadding, childWidth, bounds.getHeight() - topPadding - bottomPadding));
		x += childWidth + spacing;
	}

	Graphene::IContainer::updateLayout();
}