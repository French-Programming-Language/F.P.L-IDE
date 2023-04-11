#include "WindowManager.h"

WindowManager::WindowManager(QWidget *parent, const QString &title) : QMainWindow(parent) {
    QString Window_StyleSheet = ""
                                "QMainWindow {"
                                "  background: rgb(51,54,56);"
                                "}"
    ;

    this->setWindowTitle(title);
    this->resize(600, 300);
    this->setMaximumSize(this->size());
    this->setStyleSheet(Window_StyleSheet);

    this->widget_start = new QWidget(this);
    this->setCentralWidget(widget_start);
    this->existingLayout = widget_start->layout();
    if (existingLayout != nullptr) {
        delete existingLayout;
    }


    auto* mainLogoLabel = new QLabel(this);
    QPixmap mainLogo("images/fpl_logo.png");
    QPixmap scaledImage = mainLogo.scaled(QSize(300, 100), Qt::KeepAspectRatio);
    mainLogoLabel->setPixmap(scaledImage);
    mainLogoLabel->setAlignment(Qt::AlignCenter);

    this->mainLayout_start->addWidget(mainLogoLabel);
    this->mainLayout_start->addWidget(this->title_start);

    QString Button_StyleSheet = ""
                         "QPushButton {"
                         "  width: 70px;"
                         "  height: 70px;"
                         "  border: none;"
                         "  background: rgb(50, 92, 134);"
                         "  color: rgb(118, 146, 183);"
                         "  font-size: 15px;"
                         "  text-align: center;"
                         "  border-radius: 10px;"
                         "}"
                         "QPushButton:hover {"
                         "  color: white;"
                         "  border-radius: 15px;"
                         "  background: rgb(50, 111, 193);"
                         "}"
                         ;

    this->openButton_start->setStyleSheet(Button_StyleSheet);
    this->newFileButton_start->setStyleSheet(Button_StyleSheet);
    this->buttonsLayout_start->addItem(new QSpacerItem(0, this->height(), QSizePolicy::Expanding, QSizePolicy::Minimum));
    this->buttonsLayout_start->addWidget(this->newFileButton_start);
    this->buttonsLayout_start->addItem(new QSpacerItem(10, 30, QSizePolicy::Expanding, QSizePolicy::Minimum));
    this->buttonsLayout_start->addWidget(this->openButton_start);
    this->buttonsLayout_start->addItem(new QSpacerItem(10, 30, QSizePolicy::Expanding, QSizePolicy::Minimum));
    this->mainLayout_start->addItem(this->buttonsLayout_start);
    widget_start->setLayout(this->mainLayout_start);
}

WindowManager::~WindowManager() = default;