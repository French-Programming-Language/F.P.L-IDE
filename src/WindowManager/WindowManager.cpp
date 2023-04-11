#include "WindowManager.h"

WindowManager::WindowManager(QWidget *parent, const QString &title) : QMainWindow(parent) {
    settings(title);
    setUpWelcome();
}

void WindowManager::settings(const QString &title) {
    QString Window_StyleSheet = ""
                                "QMainWindow {"
                                "  background: rgb(51,54,56);"
                                "}"
    ;

    this->setWindowTitle(title);
    this->resize(600, 300);
    this->setMaximumSize(this->size());
    this->setStyleSheet(Window_StyleSheet);
    this->titleApp = title;
}

void WindowManager::setUpWelcome() {
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

    QString Title_StyleSheet = ""
                                "QLabel {"
                                "  width: auto;"
                                "  height: 50px;"
                                "  border: none;"
                                "  color: white;"
                                "  font-size: 35px;"
                                "  text-align: center;"
                                "}"
    ;
    this->title_start->setStyleSheet(Title_StyleSheet);
    this->mainLayout_start->addWidget(this->title_start);

    QString Button_StyleSheet = ""
                                "QPushButton {"
                                "  width: 70px;"
                                "  font-weight: bold;"
                                "  height: 70px;"
                                "  border: none;"
                                "  background: rgb(50, 92, 134);"
                                "  color: rgb(200,200,200);"
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
    this->widget_start->setLayout(this->mainLayout_start);

    connect(this->newFileButton_start, SIGNAL(clicked(bool)), this, SLOT(newFileButton(bool)));
    connect(this->openButton_start, SIGNAL(clicked(bool)), this, SLOT(openFileButton(bool)));
}

void WindowManager::setUpEditor() {
    QString Window_StyleSheet = ""
                                "QWidget {"
                                "  background: rgb(51,54,56);"
                                "}"
    ;

    this->widget_editor = new QWidget(nullptr);
    this->widget_editor->setWindowTitle(this->titleApp);
    this->widget_editor->setStyleSheet(Window_StyleSheet);
    this->widget_editor->setWindowIcon(QIcon("images/fpl_logo.png"));

    this->close();
    this->widget_editor->show();
}

void WindowManager::newFileButton(bool b) {
    setUpEditor();
}

void WindowManager::openFileButton(bool b) {
    setUpEditor();
}

WindowManager::~WindowManager() = default;