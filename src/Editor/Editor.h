#ifndef Editor_H
#define Editor_H

#include <iostream>
#include <fstream>
#include <QMainWindow>
#include <QString>
#include <QWidget>
#include <QPushButton>
#include <QSpacerItem>
#include <QPixmap>
#include <QIcon>
#include <QTextEdit>
#include <QPlainTextEdit>
#include <QMenuBar>
#include <QTextStream>

#include "../TextButton/TextButton.h"
#include "../TextLabel/TextLabel.h"
#include "../HorizontalLayout/HorizontalLayout.h"
#include "../VerticalLayout/VerticalLayout.h"

class Editor : public QMainWindow {
Q_OBJECT

public:
    explicit Editor(QWidget *parent = nullptr, const QString& title = "App", const QString& filePath = "N/A");
    ~Editor() override;

    QString filePath;

private:
    // Global :

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
    QAction* menuEditor_run_settings;
};

#endif // Editor_H
