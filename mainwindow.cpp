#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QGraphicsProxyWidget>
#include "csv_node.hpp"
std::vector<node*> gNodes;


QGraphicsScene *globalScene;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    globalScene = new QGraphicsScene();
    ui->agraphicsView->setScene(globalScene);
    globalScene->setSceneRect(QRect(0,0,1920,1080));

    csv_node * cvor = new csv_node(250, 250);
    globalScene->addWidget(cvor);
    node * cvor2 = new node(250,250);
    globalScene->addWidget(cvor2);
    edge *e1 = new edge(cvor,cvor2);
    node *cvor3 = new node(250,250);
    globalScene->addWidget(cvor3);
    edge *e2 = new edge(cvor2,cvor3);

}

MainWindow::~MainWindow()
{
    delete ui;
}

