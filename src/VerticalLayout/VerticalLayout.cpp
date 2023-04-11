#include "VerticalLayout.h"

VerticalLayout::VerticalLayout(QWidget *parent) {

}

VerticalLayout::VerticalLayout(QWidget *parent, QFlag alignement) {
    this->setAlignment(alignement);
}

VerticalLayout::~VerticalLayout() = default;