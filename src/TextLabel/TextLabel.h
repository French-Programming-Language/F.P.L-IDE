#ifndef F_P_L_IDE_TEXTLABEL_H
#define F_P_L_IDE_TEXTLABEL_H

#include <QLabel>
#include <QFlag>

class TextLabel : public QLabel {
public:
    explicit TextLabel(QWidget *parent = nullptr);
    explicit TextLabel(QWidget *parent = nullptr, const QString& text = "");
    explicit TextLabel(QWidget *parent = nullptr, const QString& text = "", QFlag alignment = Qt::AlignCenter);
    ~TextLabel() override;
};


#endif //F_P_L_IDE_TEXTLABEL_H
