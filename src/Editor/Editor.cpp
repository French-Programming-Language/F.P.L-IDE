#include "Editor.h"

void Editor::actualiserTextEditor(const QString& path) {
    QFile file(path);
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

Editor::Editor(const QString &title, const QString &filePath) {
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

    QString TerminalScrollBar_StyleSheet =  "QScrollBar:vertical {"
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

    QString Title_Sec_StyleSheet = ""
                                   "QLabel {"
                                   "  border: none;"
                                   "  color: rgb(190,190,190);"
                                   "  font-size: 13px;"
                                   "  text-align: center;"
                                   "  padding: 10px 0;"
                                   "}"
    ;

    QString input_zone_StyleSheet = ""
                                    "QLineEdit {"
                                    "  background: rgb(30,30,30);"
                                    "  color: rgb(230,230,230);"
                                    "  font-size: 12px;"
                                    "  border: 0.5px solid rgb(100,100,100);"
                                    "}"
    ;

    QString input_btn_StyleSheet = ""
                                "QPushButton {"
                                "  border: none;"
                                "  background: rgb(20,20,20);"
                                "  color: rgb(200,200,200);"
                                "  font-size: 13px;"
                                "  text-align: center;"
                                "  border-radius: 5px;"
                                "  padding: 5px 7px;"
                                "}"
                                "QPushButton:hover {"
                                "  color: white;"
                                "  border-radius: 10px;"
                                "}"
                                "QPushButton:pressed {"
                                   "  color: #0061D1;"
                                "}"
    ;


    // Window :

    this->setWindowTitle(title);
    this->resize(600, 500);
    this->setStyleSheet(Window_StyleSheet);
    this->setWindowIcon(QIcon("images/icon.png"));

    this->titleApp = title;
    this->filePath = filePath;
    this->possiblePathInterpreter = "N/A";



    // Interface :

    this->editor_layout = new VerticalLayout(this, Qt::AlignCenter);
    this->editor_text = new QTextEdit(nullptr);
    this->editor_terminal = new QPlainTextEdit(nullptr);
    this->editor_text->setPlaceholderText("Ecrivez votre code ici.");
    this->editor_text->setStyleSheet(Editor_StyleSheet);
    this->editor_terminal->setStyleSheet(Terminal_StyleSheet);
    QScrollBar* scrollBar = this->editor_terminal->verticalScrollBar();
    scrollBar->setStyleSheet(TerminalScrollBar_StyleSheet);

    this->editor_inputsLayout = new HorizontalLayout(this, Qt::AlignCenter);
    this->editor_inputsTitle = new TextLabel(this, "Entrées claviers: ", Qt::AlignAbsolute);
    this->editor_inputsBtn = new TextButton(this, "Envoyer au programme.");
    this->editor_inputs = new QLineEdit(this);
    this->editor_inputsTitle->setStyleSheet(Title_Sec_StyleSheet);
    this->editor_inputs->setStyleSheet(input_zone_StyleSheet);
    this->editor_inputsBtn->setStyleSheet(input_btn_StyleSheet);
    this->editor_inputsLayout->addWidget(this->editor_inputsTitle);
    this->editor_inputsLayout->addItem(new QSpacerItem(5, 0, QSizePolicy::Minimum, QSizePolicy::Minimum));
    this->editor_inputsLayout->addWidget(this->editor_inputs);
    this->editor_inputsLayout->addItem(new QSpacerItem(15, 0, QSizePolicy::Minimum, QSizePolicy::Minimum));
    this->editor_inputsLayout->addWidget(this->editor_inputsBtn);
    this->editor_inputsLayout->addItem(new QSpacerItem(15, 0, QSizePolicy::Minimum, QSizePolicy::Minimum));

    this->editor_layout->addWidget(this->editor_text);
    this->editor_layout->addWidget(this->editor_terminal);
    this->editor_layout->addItem(this->editor_inputsLayout);

    connect(this->editor_inputsBtn, &QPushButton::clicked, this, &Editor::editor_inputs_btn);

    this->process = new QProcess(this);
    this->editor_terminal->setReadOnly(true);



    // Menu :

    this->editor_menu = new QMenuBar(this);
    this->menuEditor_files = new QMenu(tr("Fichier"), this);
    this->menuEditor_run = new QMenu(tr("Executer"), this);
    this->menuEditor_files_new = new QAction(tr("Nouveau"), this);
    this->menuEditor_files_open = new QAction(tr("Ouvrir"), this);
    this->menuEditor_files_save = new QAction(tr("Sauvegarder"), this);
    this->menuEditor_files_saveas = new QAction(tr("Sauvegarder sous"), this);
    this->menuEditor_run_run  = new QAction(tr("Executer..."), this);
    this->menuEditor_run_stop = new QAction(tr("Arrêter..."), this);
    this->menuEditor_run_settings  = new QAction(tr("Paramètres"), this);
    this->menuEditor_files_new->setShortcut(QKeySequence::New);
    this->menuEditor_files_open->setShortcut(QKeySequence::Open);
    this->menuEditor_files_save->setShortcut(QKeySequence::Save);
    this->menuEditor_files_saveas->setShortcut(QKeySequence(Qt::CTRL | Qt::Key_A));
    this->menuEditor_run_run->setShortcut(QKeySequence(Qt::CTRL | Qt::Key_F5));
    this->menuEditor_run_stop->setShortcut(QKeySequence(Qt::CTRL | Qt::Key_F6));
    this->menuEditor_run_settings->setShortcut(QKeySequence(Qt::CTRL | Qt::Key_F7));
    this->menuEditor_files->addAction(this->menuEditor_files_new);
    this->menuEditor_files->addAction(this->menuEditor_files_open);
    this->menuEditor_files->addAction(this->menuEditor_files_save);
    this->menuEditor_files->addAction(this->menuEditor_files_saveas);
    this->menuEditor_run->addAction(this->menuEditor_run_run);
    this->menuEditor_run->addAction(this->menuEditor_run_stop);
    this->menuEditor_run->addAction(this->menuEditor_run_settings);
    this->editor_menu->addMenu(this->menuEditor_files);
    this->editor_menu->addMenu(this->menuEditor_run);

    auto* centralWidget = new QWidget(this);
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



    // Connections globales :

    connect(this->menuEditor_files_new, &QAction::triggered, this, &Editor::menu_file_new);
    connect(this->menuEditor_files_open, &QAction::triggered, this, &Editor::menu_file_open);
    connect(this->menuEditor_files_save, &QAction::triggered, this, &Editor::menu_file_save);
    connect(this->menuEditor_files_saveas, &QAction::triggered, this, &Editor::menu_file_saveas);

    connect(this->menuEditor_run_run, &QAction::triggered, this, &Editor::menu_run_run);
    connect(this->menuEditor_run_stop, &QAction::triggered, this, &Editor::menu_run_stop);
    connect(this->menuEditor_run_settings, &QAction::triggered, this, &Editor::menu_run_settings);
}

void Editor::menu_file_open()
{
    QString fileName = QFileDialog::getOpenFileName(
            this,
            tr("Sélectionner un fichier"),
            "",
            tr("Fichiers (*.*)")
    );

    if (!fileName.isEmpty()) {
        actualiserTextEditor(fileName);
        this->currentEditFile_Path = fileName;
    }
}

void Editor::menu_file_new() {
    std::ofstream newF {"unknown.fpl"};
    if (newF.is_open()) {
        newF << "envoyer \"Bienvenue !\";" << std::endl;
        newF.close();
    }

    actualiserTextEditor("unknown.fpl");
    this->currentEditFile_Path = "unknown.fpl";
}

void Editor::menu_run_run() {
    if (this->process->state() == QProcess::NotRunning) {
        this->editor_terminal->clear();
        this->editor_terminal->setPlainText("Interprétation en cours... \n");

        if (this->currentEditFile_Path != "N/A") {
            QString program;
            QStringList arguments;
            if (this->possiblePathInterpreter == "N/A") {
                program = "interpreters\\V2-FPL.exe";
            } else {
                program = this->possiblePathInterpreter;
            }
            arguments << this->currentEditFile_Path;

            this->process->setProgram(program);
            this->process->setArguments(arguments);
            this->process->setProcessChannelMode(QProcess::MergedChannels);

            this->process->start();

            connect(this->process, &QProcess::readyReadStandardOutput, this, [=, this](){
                QByteArray output = this->process->readAllStandardOutput();
                this->editor_terminal->appendPlainText(QString(output));
            });

            connect(this->process, &QProcess::readyReadStandardError, this, [=, this](){
                QByteArray error = this->process->readAllStandardError();
                this->editor_terminal->appendPlainText(QString(error));
            });
        }
    } else {
        this->editor_terminal->setPlainText("Veuillez stopper le programme.");
    }
}

void Editor::menu_run_settings() {
    QString Window_StyleSheet = ""
                                "QWidget {"
                                "  background: rgb(51,54,56);"
                                "}"
    ;


    QString Title_StyleSheet = ""
                               "QLabel {"
                               "  border: none;"
                               "  color: white;"
                               "  font-size: 15px;"
                               "  text-align: center;"
                               "  padding: 10px 0;"
                               "}"
    ;

    QString Title_Sec_StyleSheet = ""
                               "QLabel {"
                               "  border: none;"
                               "  color: rgb(190,190,190);"
                               "  font-size: 15px;"
                               "  text-align: center;"
                               "  padding: 10px 0;"
                               "}"
    ;

    QString Button_StyleSheet = ""
                                "QPushButton {"
                                "  width: 150px;"
                                "  font-weight: italic;"
                                "  height: auto;"
                                "  border: none;"
                                "  background: rgb(50, 92, 134);"
                                "  color: rgb(200,200,200);"
                                "  font-size: 13px;"
                                "  text-align: center;"
                                "  border-radius: 5px;"
                                "}"
                                "QPushButton:hover {"
                                "  color: white;"
                                "  border-radius: 10px;"
                                "  background: rgb(50, 111, 193);"
                                "}"
    ;

    QString Path_StyleSheet = ""
                                "QLineEdit {"
                                "  background: rgb(30,30,30);"
                                "  color: rgb(230,230,230);"
                                "  font-size: 12px;"
                                "  border: 1.5px solid rgb(200,200,200);"
                                "}"
    ;

    this->settings_W = new QWidget(nullptr);
    this->layout_settings = new VerticalLayout(nullptr, Qt::AlignCenter);
    this->title_settings = new TextLabel(nullptr, "Paramètres de l'IDE", Qt::AlignCenter);
    this->settings_W->resize(500,150);
    this->settings_W->setMaximumSize(settings_W->size());
    this->settings_W->setMinimumSize(settings_W->size());
    this->settings_W->setWindowTitle(this->titleApp + QString(" (Paramètres)"));
    this->settings_W->setStyleSheet(Window_StyleSheet);

    this->title_settings->setStyleSheet(Title_StyleSheet);

    this->title_pathInter = new TextLabel(nullptr, "Interpréteur : ", Qt::AlignTop);
    this->title_pathInter->setStyleSheet(Title_Sec_StyleSheet);
    this->pathLineEdit = new QLineEdit();
    this->pathLineEdit->setStyleSheet(Path_StyleSheet);
    this->selectFileButton = new TextButton(nullptr, "Sélectionner un fichier");
    this->selectFileButton->setStyleSheet(Button_StyleSheet);
    this->layout_selectfile = new HorizontalLayout(nullptr, Qt::AlignLeft);
    this->layout_selectfile->addWidget(title_pathInter);
    this->layout_selectfile->addItem(new QSpacerItem(5, 0, QSizePolicy::Minimum, QSizePolicy::Minimum));
    this->layout_selectfile->addWidget(pathLineEdit);
    this->layout_selectfile->addItem(new QSpacerItem(20, 0, QSizePolicy::Minimum, QSizePolicy::Minimum));
    this->layout_selectfile->addWidget(selectFileButton);

    this->layout_settings->addWidget(title_settings);
    this->layout_settings->addItem(layout_selectfile);

    this->settings_W->setLayout(layout_settings);
    this->settings_W->show();



    connect(selectFileButton, &QPushButton::clicked, [=, this]() {
        QString fileP = QFileDialog::getOpenFileName(this, "Sélectionner un fichier", "", "Fichiers exécutables (*.exe)");
        if (!fileP.isEmpty()) {
            this->pathLineEdit->setText(fileP);
            this->possiblePathInterpreter = fileP;
        }
    });
}

void Editor::menu_file_save() {
    QFile file {this->currentEditFile_Path};
    if (file.open(QIODevice::WriteOnly | QIODevice::Truncate)) {
        QTextStream out(&file);
        out << this->editor_text->toPlainText();
        file.close();
    }
}

void Editor::menu_file_saveas() {
    QString fileName = QFileDialog::getSaveFileName(this,
                                                    tr("Enregistrer sous"), QDir::currentPath(), tr("Fichiers texte (*.txt);;Tous les fichiers (*.*)"));
    if (!fileName.isEmpty()) {
        std::ofstream newF {fileName.toStdString()};
        if (newF.is_open()) {
            newF << this->editor_text->toPlainText().toStdString() << std::endl;
            newF.close();
        }

        actualiserTextEditor(fileName);
        this->currentEditFile_Path = fileName;
    }
}

void Editor::editor_inputs_btn() {
    if (this->process != nullptr && this->process->state() == QProcess::Running && this->editor_inputs != nullptr && !this->editor_inputs->text().isEmpty()) {
        std::string content = this->editor_inputs->text().toStdString() + "\n";
        this->process->write(content.c_str());
    }
}

void Editor::menu_run_stop() {
    if (this->process->state() == QProcess::Running) {
        this->process->close();
    }
    this->editor_terminal->clear();
    this->editor_terminal->setPlainText("Interpréteur éteint.");
}


Editor::~Editor() = default;
