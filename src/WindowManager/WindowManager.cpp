#include "WindowManager.h"

WindowManager::WindowManager(QWidget *parent, const QString &title) : QMainWindow(parent) {
    this->setWindowTitle(title);
    this->resize(600, 300);

    QWidget* centralWidget = new QWidget(this);
    this->setCentralWidget(centralWidget);
    QLayout* existingLayout = centralWidget->layout();
    if (existingLayout != nullptr) {
        delete existingLayout;
    }

    this->buttonsLayout_start->addWidget(this->newFileButton_start);
    this->buttonsLayout_start->addWidget(this->openButton_start);
    this->mainLayout_start->addWidget(this->title_start);
    this->mainLayout_start->addItem(this->buttonsLayout_start);
    centralWidget->setLayout(this->mainLayout_start);
}

WindowManager::~WindowManager() = default;
