#include "VerticalLayout.h"

void Graphene::VerticalLayout::updateLayout() {
	// calculate the total stretch value
	int totalStretch = 0;
	for (auto child : children) {
		totalStretch += child->getStretchY();
	}

	// remaining space after padding and spacing
	int remainingSpace = bounds.getHeight() - topPadding - bottomPadding - spacing * (children.size() - 1);

	// calculate and apply the height of each child
	int y = bounds.getY() + topPadding;
	for (auto child : children) {
		int childHeight = remainingSpace * child->getStretchY() / totalStretch;
		child->setBounds(
			Rect(bounds.getX() + leftPadding, y, bounds.getWidth() - rightPadding - leftPadding, childHeight));
		y += childHeight + spacing;
	}
}