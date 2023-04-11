#ifndef WINDOWMANAGER_H
#define WINDOWMANAGER_H

#include <QMainWindow>
#include <QString>
#include <QWidget>

#include "../TextButton/TextButton.h"
#include "../TextLabel/TextLabel.h"
#include "../HorizontalLayout/HorizontalLayout.h"
#include "../VerticalLayout/VerticalLayout.h"

class WindowManager : public QMainWindow {
Q_OBJECT

public:
    explicit WindowManager(QWidget *parent = nullptr, const QString& title = "App");
    ~WindowManager() override;

private:
    // Début de l'app
    VerticalLayout* mainLayout_start = new VerticalLayout(nullptr, Qt::AlignCenter);
    HorizontalLayout* buttonsLayout_start = new HorizontalLayout(nullptr, Qt::AlignCenter);
    TextLabel* title_start = new TextLabel(nullptr, "Bienvenue sur l'IDE de F.P.L", Qt::AlignCenter);
    TextButton* newFileButton_start = new TextButton(nullptr, "Nouveau");
    TextButton* openButton_start = new TextButton(nullptr, "Ouvrir");
};

#endif // WINDOWMANAGER_H
