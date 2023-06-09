#ifndef Editor_H
#define Editor_H

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <QMainWindow>
#include <QLineEdit>
#include <QString>
#include <QWidget>
#include <QPushButton>
#include <QFileDialog>
#include <QSpacerItem>
#include <QPixmap>
#include <QIcon>
#include <QTextEdit>
#include <QPlainTextEdit>
#include <QMenuBar>
#include <QTextStream>
#include <QProcess>
#include <QScrollBar>
#include <QThread>

#include "../TextButton/TextButton.h"
#include "../TextLabel/TextLabel.h"
#include "../HorizontalLayout/HorizontalLayout.h"
#include "../VerticalLayout/VerticalLayout.h"

class Editor : public QMainWindow {
Q_OBJECT

public:
    explicit Editor(const QString &title, const QString &filePath);
    ~Editor() override;

    QString filePath;
    QString currentEditFile_Path = "N/A";

private slots:
    void editor_inputs_btn();
    void menu_file_new();
    void menu_file_open();
    void menu_file_save();
    void menu_file_saveas();
    void menu_run_run();
    void menu_run_stop();
    void menu_run_settings();

private:
    // Global :
    void actualiserTextEditor(const QString& path);
    QString titleApp = "App";
    QProcess* process{};

    // Editeur :
    VerticalLayout* editor_layout;
    QTextEdit* editor_text;
    QPlainTextEdit* editor_terminal;
    QMenuBar* editor_menu;
    QMenu* menuEditor_files;
    QMenu* menuEditor_run;
    QAction* menuEditor_files_new;
    QAction* menuEditor_files_open;
    QAction* menuEditor_files_save;
    QAction* menuEditor_files_saveas;
    QAction* menuEditor_run_run;
    QAction* menuEditor_run_stop;
    QAction* menuEditor_run_settings;
    // Pour les inputs:
    HorizontalLayout* editor_inputsLayout{};
    TextLabel* editor_inputsTitle{};
    QLineEdit* editor_inputs{};
    TextButton* editor_inputsBtn{};

    // Paramètres (Widget pour les paramètres) :
    QWidget* settings_W{};
    VerticalLayout* layout_settings{};
    TextLabel* title_settings{};
    TextLabel* title_pathInter{};
    QLineEdit* pathLineEdit{};
    TextButton* selectFileButton{};
    HorizontalLayout* layout_selectfile{};
    QString possiblePathInterpreter;
};

#endif // Editor_H
