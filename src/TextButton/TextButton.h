#ifndef F_P_L_IDE_TEXTBUTTON_H
#define F_P_L_IDE_TEXTBUTTON_H

#include <QPushButton>

class TextButton : public QPushButton {
    explicit TextButton(QWidget *parent = nullptr);
    explicit TextButton(QWidget *parent = nullptr, const QString& text = "");
    ~TextButton() override;
};


#endif //F_P_L_IDE_TEXTBUTTON_H