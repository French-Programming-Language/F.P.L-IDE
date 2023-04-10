#include "WindowManager.h"

WindowManager::WindowManager(QWidget *parent, const QString &title) : QMainWindow(parent) {
    this->setWindowTitle(title);
    this->resize(600, 300);

    // Splitter :
    this->splitter_ide = new QSplitter(Qt::Horizontal, this);
    this->setCentralWidget(splitter_ide);

    // Zone 1 : Fichiers
    this->files_view = new QTreeView(this);
    this->files_view->setHeaderHidden(true);
    this->files_model = new QFileSystemModel(this);
    this->files_model->setRootPath("");
    this->files_view->setModel(files_model);
    this->files_view->hideColumn(1);
    this->files_view->hideColumn(2);
    this->files_view->hideColumn(3);
    this->splitter_ide->addWidget(files_view);

    // Zone 2 : Code Edit
    this->text_edit_view = new QTextEdit(this);
    this->splitter_ide->addWidget(text_edit_view);

    // Sizes
    this->splitter_ide->setStretchFactor(0, 1);
    this->splitter_ide->setStretchFactor(1, 3);

    // Menu (Fichier, Edit, etc.)
    this->contentFile = new QMenu(tr("Fichier"), this);
    this->ac_file_new = new QAction(tr("Nouveau"), this);
    this->ac_file_new->setShortcut(QKeySequence::New);
    this->ac_file_open = new QAction(tr("Ouvrir"), this);
    this->ac_file_open->setShortcut(QKeySequence::Open);
    this->ac_file_save = new QAction(tr("Enregistrer"), this);
    this->ac_file_save->setShortcut(QKeySequence::Save);
    this->ac_file_saveas = new QAction(tr("Enregistrer sous"), this);
    this->ac_file_saveas->setShortcut(QKeySequence::SaveAs);
    this->contentFile->addAction(ac_file_new);
    this->contentFile->addAction(ac_file_open);
    this->contentFile->addAction(ac_file_save);
    this->contentFile->addAction(ac_file_saveas);

    this->contentEdit = new QMenu(tr("Editer"), this);
    this->ac_edit_undo = new QAction(tr("Arrière"), this);
    this->ac_edit_undo->setShortcut(QKeySequence::Undo);
    this->ac_edit_redo = new QAction(tr("Avant"), this);
    this->ac_edit_redo->setShortcut(QKeySequence::Redo);
    this->ac_edit_find = new QAction(tr("Chercher"), this);
    this->ac_edit_find->setShortcut(QKeySequence::Find);
    this->contentEdit->addAction(ac_edit_undo);
    this->contentEdit->addAction(ac_edit_redo);
    this->contentEdit->addAction(ac_edit_find);

    // Ajout de la barre de menu au widget
    this->MainMenu = new QMenuBar(this);
    this->setMenuBar(MainMenu);
    this->MainMenu->addMenu(contentFile);
    this->MainMenu->addMenu(contentEdit);
}

WindowManager::~WindowManager() = default;
