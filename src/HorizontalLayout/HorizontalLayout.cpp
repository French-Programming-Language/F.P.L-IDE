#include "HorizontalLayout.h"

HorizontalLayout::HorizontalLayout(QWidget *parent) : QHBoxLayout(parent) {

}

HorizontalLayout::HorizontalLayout(QWidget *parent, QFlag alignement) {
    this->setAlignment(alignement);
}

HorizontalLayout::~HorizontalLayout() = default;
