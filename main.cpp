#include <QApplication>

#include "src/WindowManager/WindowManager.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    WindowManager windowManager;

    return QApplication::exec();
}