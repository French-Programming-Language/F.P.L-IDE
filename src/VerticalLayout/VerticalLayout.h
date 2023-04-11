#ifndef F_P_L_IDE_VERTICALLAYOUT_H
#define F_P_L_IDE_VERTICALLAYOUT_H

#include <QLayout>
#include <QVBoxLayout>
#include <QFlag>

class VerticalLayout : public QVBoxLayout {
public:
    explicit VerticalLayout(QWidget *parent = nullptr);
    explicit VerticalLayout(QWidget *parent = nullptr, QFlag alignement = Qt::AlignAbsolute);
    ~VerticalLayout() override;
};


#endif //F_P_L_IDE_VERTICALLAYOUT_H
