#ifndef F_P_L_IDE_HORIZONTALLAYOUT_H
#define F_P_L_IDE_HORIZONTALLAYOUT_H

#include <QLayout>
#include <QHBoxLayout>
#include <QFlag>

class HorizontalLayout : public QHBoxLayout {
public:
    explicit HorizontalLayout(QWidget *parent = nullptr);
    explicit HorizontalLayout(QWidget *parent = nullptr, QFlag alignement = Qt::AlignAbsolute);
    ~HorizontalLayout() override;
};


#endif //F_P_L_IDE_HORIZONTALLAYOUT_H
