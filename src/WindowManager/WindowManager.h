#ifndef WINDOWMANAGER_H
#define WINDOWMANAGER_H

#include <iostream>
#include <QMainWindow>
#include <QString>
#include <QWidget>
#include <QPushButton>
#include <QSpacerItem>
#include <QPixmap>

#include "../Data/Data.h"
#include "../TextButton/TextButton.h"
#include "../TextLabel/TextLabel.h"
#include "../HorizontalLayout/HorizontalLayout.h"
#include "../VerticalLayout/VerticalLayout.h"

class WindowManager : public QMainWindow {
Q_OBJECT

public:
    explicit WindowManager(QWidget *parent = nullptr, const QString& title = "App");
    ~WindowManager() override;

private slots:
    void newFileButton(bool b);
    void openFileButton(bool b);

private:
    void settings(const QString &title);
    void setUpWelcome();
    void setUpEditor();

    // Global
    Data* data;
    QString titleApp = "App";


    // Début de l'app
    QWidget* widget_start;
    QLayout* existingLayout_start;
    HorizontalLayout* main_layout_start = new HorizontalLayout(nullptr, Qt::AlignCenter);
    TextLabel* title_start = new TextLabel(nullptr, "Bienvenue", Qt::AlignAbsolute);
    QLabel* recentF_BG_start = new QLabel(nullptr);
    HorizontalLayout* recentFiles_layout_start = new HorizontalLayout(nullptr, Qt::AlignLeft);
    HorizontalLayout* classic_layout_start = new HorizontalLayout(nullptr, Qt::AlignRight);
    VerticalLayout* classicContent_layout_start = new VerticalLayout(nullptr, Qt::AlignAbsolute);
    HorizontalLayout* classicButtons_layout = new HorizontalLayout(nullptr, Qt::AlignAbsolute);
    TextButton* newFile_btn_start = new TextButton(nullptr, "");
    TextButton* openFile_btn_start = new TextButton(nullptr, "");
};

#endif // WINDOWMANAGER_H
