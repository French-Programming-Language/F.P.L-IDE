#include <QFile>
#include "Editor.h"

Editor::Editor(QWidget *parent, const QString &title, const QString& filePath) {
    QString Window_StyleSheet = ""
                                "QMainWindow {"
                                "  background: rgb(51,54,56);"
                                "}"
    ;


    QString Editor_StyleSheet = ""
                                "QTextEdit {"
                                "  background : rgb(45,45,45);"
                                "  border: none;"
                                "  color: white;"
                                "  padding: 5px 5px;"
                                "  font-size: 13px;"
                                "}"
                                "QScrollBar:vertical {"
                                "    background-color: rgb(51,54,56);"
                                "    width: 16px;"
                                "    margin: 16px 0 16px 0;"
                                "}"
                                "QScrollBar::handle:vertical {"
                                "    background-color: rgb(70,70,70);"
                                "    min-height: 20px;"
                                "}"
                                "QScrollBar::add-line:vertical {"
                                "    border: none;"
                                "    background: none;"
                                "}"
                                "QScrollBar::sub-line:vertical {"
                                "    border: none;"
                                "    background: none;"
                                "}"
                                "QScrollBar::add-page:vertical, QScrollBar::sub-page:vertical {"
                                "    background: none;"
                                "}"
    ;

    QString Terminal_StyleSheet = ""
                                  "QPlainTextEdit {"
                                  "  background : rgb(40,40,40);"
                                  "  border-color: red;"
                                  "  border-radius: 5px;"
                                  "  font-size: 13px;"
                                  "  color: white;"
                                  "  padding: 5px 5px;"
                                  "}"
    ;

    this->setWindowTitle(title);
    this->resize(300, 500);
    this->setStyleSheet(Window_StyleSheet);
    this->setWindowIcon(QIcon("images/icon.png"));

    this->filePath = filePath;

    // Interface :

    this->editor_layout = new VerticalLayout(this, Qt::AlignCenter);
    this->editor_text = new QTextEdit(nullptr);
    this->editor_terminal = new QPlainTextEdit(nullptr);
    this->editor_text->setPlaceholderText("Ecrivez votre code ici.");
    this->editor_text->setStyleSheet(Editor_StyleSheet);
    this->editor_terminal->setStyleSheet(Terminal_StyleSheet);

    this->editor_layout->addWidget(this->editor_text);
    this->editor_layout->addWidget(this->editor_terminal);


    // Menu :

    this->editor_menu = new QMenuBar(this);
    this->menuEditor_files = new QMenu(tr("Fichier"), this);
    this->menuEditor_run = new QMenu(tr("Executer"), this);
    this->menuEditor_files_new = new QAction(tr("Nouveau"), this);;
    this->menuEditor_files_open = new QAction(tr("Ouvrir"), this);;
    this->menuEditor_files_save = new QAction(tr("Sauvegarder"), this);
    this->menuEditor_files_saveas = new QAction(tr("Sauvegarder sous"), this);
    this->menuEditor_run_run  = new QAction(tr("Executer..."), this);;
    this->menuEditor_run_settings  = new QAction(tr("Paramètres"), this);
    this->menuEditor_files->addAction(this->menuEditor_files_new);
    this->menuEditor_files->addAction(this->menuEditor_files_open);
    this->menuEditor_files->addAction(this->menuEditor_files_save);
    this->menuEditor_files->addAcztion(this->menuEditor_files_saveas);
    this->menuEditor_run->addAction(this->menuEditor_run_run);
    this->menuEditor_run->addAction(this->menuEditor_run_settings);
    this->editor_menu->addMenu(this->menuEditor_files);
    this->editor_menu->addMenu(this->menuEditor_run);

    QWidget* centralWidget = new QWidget(this);
    centralWidget->setLayout(this->editor_layout);
    this->setCentralWidget(centralWidget);
    this->setMenuBar(this->editor_menu);

    if (this->filePath != "N/A") {
        QFile file(filePath);
        QString fileContent;

        if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            QTextStream in(&file);
            while (!in.atEnd()) {
                QString line = in.readLine();
                fileContent += line + "\n";  // Ajouter la ligne au contenu du fichier avec un saut de ligne
            }
            file.close();
        }

        this->editor_text->setText(fileContent);
    }
}

Editor::~Editor() = default;
