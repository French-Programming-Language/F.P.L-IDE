#include "TextLabel.h"

TextLabel::TextLabel(QWidget *parent) {

}

TextLabel::TextLabel(QWidget *parent, const QString &text) {
    this->setText(text);
}

TextLabel::TextLabel(QWidget *parent, const QString &text, QFlag alignment) {
    this->setText(text);
    this->setAlignment(alignment);
}

TextLabel::~TextLabel() = default;
