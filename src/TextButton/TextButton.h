#ifndef F_P_L_IDE_TEXTBUTTON_H
#define F_P_L_IDE_TEXTBUTTON_H

#include <QPushButton>

class TextButton : public QPushButton {
public:
    explicit TextButton(QWidget *parent = nullptr);

    ~TextButton() override;
    explicit TextButton(QWidget *parent = nullptr, const QString& text = "");
};


#endif //F_P_L_IDE_TEXTBUTTON_H