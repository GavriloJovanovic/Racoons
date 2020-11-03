#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QGraphicsProxyWidget>

QGraphicsScene *globalScene;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    globalScene = new QGraphicsScene();
    ui->agraphicsView->setScene(globalScene);
    globalScene->setSceneRect(QRect(0,0,1920,1080));

    node * cvor = new node(200, 200);
    globalScene->addWidget(cvor);

}

MainWindow::~MainWindow()
{
    delete ui;
}

