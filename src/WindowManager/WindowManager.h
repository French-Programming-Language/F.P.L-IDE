#ifndef WINDOWMANAGER_H
#define WINDOWMANAGER_H

#include <QMainWindow>
#include <QString>
#include <QMenuBar>
#include <QSplitter>
#include <QTreeView>
#include <QTextEdit>
#include <QFileSystemModel>
#include <QDir>
#include <QStandardPaths>

class WindowManager : public QMainWindow {
Q_OBJECT

public:
    explicit WindowManager(QWidget *parent = nullptr, const QString& title = "App");
    ~WindowManager() override;

private:
    QSplitter* splitter_ide;
    QTreeView* files_view;
    QFileSystemModel* files_model;
    QTextEdit* text_edit_view;
    QMenuBar* MainMenu;
    QMenu* contentFile;
    QAction* ac_file_new;
    QAction* ac_file_open;
    QAction* ac_file_save;
    QAction* ac_file_saveas;
    QMenu* contentEdit;
    QAction* ac_edit_undo;
    QAction* ac_edit_redo;
    QAction* ac_edit_find;
};

#endif // WINDOWMANAGER_H
