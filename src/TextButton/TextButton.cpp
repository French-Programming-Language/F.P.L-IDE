#include "TextButton.h"

TextButton::TextButton(QWidget *parent) : QPushButton(parent) {
    setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
}

TextButton::TextButton(QWidget *parent, const QString& text) {
    this->setText(text);
    setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
}

TextButton::~TextButton() = default;
