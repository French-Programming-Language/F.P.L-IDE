#ifndef F_P_L_IDE_WINDOWMANAGER_H
#define F_P_L_IDE_WINDOWMANAGER_H

#include <QMainWindow>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QString>

class WindowManager : public QMainWindow {
Q_OBJECT

public:
    explicit WindowManager(QWidget *parent = nullptr, const QString& title = "Qt Application");
    ~WindowManager() override;
};


#endif