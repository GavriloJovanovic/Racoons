#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QGraphicsProxyWidget>
#include "csv_node.hpp"
#include "partition_node.hpp"
#include "standardization_node.hpp"
#include "normalization_node.hpp"
#include "delete_na.hpp"
#include "filter_node.hpp"
#include "stats_node.hpp"
std::vector<node*> gNodes;


QGraphicsScene *globalScene;

node *fstSelected = nullptr, *sndSelected = nullptr;
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
    partition_node * cvor2 = new partition_node(250,250);
    globalScene->addWidget(cvor2);

   }

void MainWindow::keyPressEvent(QKeyEvent *event) {
    if(event->key() == Qt::Key_Space && fstSelected && sndSelected && (fstSelected != sndSelected)) {

        if(sndSelected->firstFree() != -1) {
            activeEdges.push_back(new edge(fstSelected, sndSelected));

            fstSelected->setStyleSheet("");
            sndSelected->setStyleSheet("");
            fstSelected = nullptr;
            sndSelected = nullptr;
        }
    }

}
MainWindow::~MainWindow()
{
    delete ui;
}

