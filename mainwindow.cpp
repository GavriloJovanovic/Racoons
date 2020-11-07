#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QGraphicsProxyWidget>
#include "csv_node.hpp"
#include "partition_node.hpp"
#include "knn_node.hpp"
#include "binning_node.hpp"
#include "categoricaltobinnary_node.hpp"
#include "aproximation_node.hpp"
#include "outputtable_node.hpp"
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

