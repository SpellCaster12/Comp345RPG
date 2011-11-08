#include <QDialog>
#include <QDebug>
#include "game.h"
#include "ui_game.h"
#include "charactergenerator.h"
#include "quitdialog.h"

Game::Game(QWidget *parent) :
    QStackedWidget(parent),
    ui(new Ui::Game)
{
    ui->setupUi(this);
    QObject::connect(ui->characterGenButton, SIGNAL(clicked()), SLOT(setWidget()));
    this->setCurrentIndex(0);
}

Game::~Game()
{
    delete ui;
}

void Game::setWidget()
{
    this->setCurrentIndex(1);
    ((CharacterGenerator*)this->currentWidget())->show();
    this->resize(this->currentWidget()->size());
}

void Game::closeEvent(QCloseEvent *event)
{
    QuitDialog *quitDialog = new QuitDialog;
    int quit = quitDialog->exec();
    delete quitDialog;
    if (quit == 1)
    {
        qApp->quit();
    }
    else
    {
        event->ignore();
    }
}
