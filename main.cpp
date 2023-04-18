#include <QApplication>

#include "src/WindowManager/WindowManager.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    WindowManager w(nullptr, "F.P.L IDE - Version 0");
    w.setWindowIcon(QIcon("images/icon.png"));
    w.show();

    return QApplication::exec();
}