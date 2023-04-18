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
    this->resize(800, 600);
    this->setMaximumSize(this->size());
    this->setStyleSheet(Window_StyleSheet);
    this->titleApp = title;
}

void WindowManager::setUpWelcome() {
    this->widget_start = new QWidget(this);
    this->setCentralWidget(this->widget_start);
    this->existingLayout_start = this->widget_start->layout();
    if (existingLayout_start != nullptr) {
        delete existingLayout_start;
    }

    QString Title_StyleSheet = ""
                               "QLabel {"
                               "  width: auto;"
                               "  height: 50px;"
                               "  border: none;"
                               "  color: white;"
                               "  font-size: 35px;"
                               "  text-align: center;"
                               "  padding: 10px 0;"
                               "}"
    ;

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

    QString recentF_BG_start_Stylesheet = ""
                               "QLabel {"
                               "  border-radius: 20px;"
                               "  background-color: rgb(40,40,40);"
                               "}"
    ;

    this->recentF_BG_start->setFixedSize(250, 450);
    this->recentF_BG_start->setStyleSheet(recentF_BG_start_Stylesheet);

    this->recentFiles_layout_start->addWidget(this->recentF_BG_start);

    this->title_start->setStyleSheet(Title_StyleSheet);
    this->title_start->setAlignment(Qt::AlignCenter);
    this->newFile_btn_start->setStyleSheet(Button_StyleSheet);
    this->openFile_btn_start->setStyleSheet(Button_StyleSheet);

    QPixmap logo_newfile("images/new_logo.png");
    QPixmap logo_openfile("images/file_logo.png");
    this->newFile_btn_start->setIcon(QIcon(logo_newfile));
    this->newFile_btn_start->setIconSize(QSize(50,50));
    this->openFile_btn_start->setIcon(QIcon(logo_openfile));
    this->openFile_btn_start->setIconSize(QSize(50,50));

    this->classicContent_layout_start->addWidget(this->title_start);
    this->classicContent_layout_start->addItem(new QSpacerItem(0, 30));
    this->classicButtons_layout->addWidget(this->newFile_btn_start);
    this->classicButtons_layout->addItem(new QSpacerItem(50, 0));
    this->classicButtons_layout->addWidget(this->openFile_btn_start);
    this->classicContent_layout_start->addItem(classicButtons_layout);
    this->classicContent_layout_start->addItem(new QSpacerItem(0, 150));
    this->classic_layout_start->addItem(classicContent_layout_start);


    this->main_layout_start->addItem(new QSpacerItem(50, 0));
    this->main_layout_start->addItem(this->recentFiles_layout_start);
    this->main_layout_start->addItem(new QSpacerItem(200, 0));
    this->main_layout_start->addItem(this->classic_layout_start);
    this->main_layout_start->addItem(new QSpacerItem(50, 0));

    this->widget_start->setLayout(this->main_layout_start);
    this->widget_start->show();


    connect(this->newFile_btn_start, SIGNAL(clicked(bool)), this, SLOT(newFileButton(bool)));
    connect(this->openFile_btn_start, SIGNAL(clicked(bool)), this, SLOT(openFileButton(bool)));
}


void WindowManager::setUpEditor(QString filePath) {
    this->editor = new Editor(nullptr, this->titleApp, filePath);
    this->editor->show();

    this->close();
}

void WindowManager::newFileButton(bool b) {
    setUpEditor("N/A");
}

void WindowManager::openFileButton(bool b) {
    QString fileName = QFileDialog::getOpenFileName(
            this,
            tr("Sélectionner un fichier"),
            "",
            tr("Fichiers (*.*)")
    );

    if (!fileName.isEmpty()) {
        setUpEditor(fileName);
    } else {
        setUpEditor("N/A");
    }
}

WindowManager::~WindowManager() = default;