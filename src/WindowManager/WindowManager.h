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
    QWidget* widget_start{};
    QLayout* existingLayout{};
    VerticalLayout* mainLayout_start = new VerticalLayout(nullptr, Qt::AlignCenter);
    HorizontalLayout* buttonsLayout_start = new HorizontalLayout(nullptr, Qt::AlignCenter);
    TextLabel* title_start = new TextLabel(nullptr, "Bienvenue sur l'IDE de F.P.L", Qt::AlignCenter);
    TextButton* newFileButton_start = new TextButton(nullptr, "Nouveau");
    TextButton* openButton_start = new TextButton(nullptr, "Open");


    // Editeur
    QWidget* widget_editor{};
    VerticalLayout* mainLayout_editor = new VerticalLayout(nullptr, Qt::AlignCenter);
};

#endif // WINDOWMANAGER_H
