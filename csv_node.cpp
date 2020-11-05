#include "csv_node.hpp"
#include <QFileDialog>
#include <QDialog>
#include <QHBoxLayout>
#include "transformations.hpp"

csv_node::csv_node(int width, int height) : node(width,height){
    headerText->setText("CSV NODE");
    edit.setParent(body);
    edit.setGeometry(geometry().x() + 10,geometry().y() + 10,150,30);
    loadBtn.setParent(body);
    browseBtn.setParent(body);
    browseBtn.setGeometry(geometry().x() + 165,geometry().y() + 10,30,30);
    loadBtn.setGeometry(geometry().x() + 200,geometry().y() + 10,30,30);
    loadBtn.setText("load");
    colomns.setParent(body);
    colomns.setGeometry(geometry().x() + 10, geometry().y() + 50, 220, 150);
    previewBtn.setParent(body);
    runBtn.setParent(body);
    previewBtn.setGeometry(geometry().x() + 140,geometry().y() + 205, 50,20);
    runBtn.setGeometry(geometry().x() + 200,geometry().y() + 205, 30,20);
    runBtn.setText("run");
    previewBtn.setText("preview");



    connect(&browseBtn,SIGNAL(clicked()),this,SLOT(browse()));
    connect(&previewBtn,SIGNAL(clicked()),this,SLOT(preview()));
    connect(&loadBtn,SIGNAL(clicked()),this,SLOT(load()));

}

void csv_node::load() {
    std::string path = edit.text().toStdString();
    t = loadFromFile(path);
}

void csv_node::preview() {

    QDialog tablePreview;
    tablePreview.setModal(true);
    QHBoxLayout hBox;
    tablePreview.setLayout(&hBox);
    tablePreview.setGeometry(500,500,500,500);
    QTableWidget qTable{};
    hBox.addWidget(&qTable);
    auto colomns = t.col_names();
    qTable.setRowCount(t.row_n());
    qTable.setColumnCount(t.col_n());

    for(int i = 0; i < colomns.size(); i++){
        qTable.setHorizontalHeaderItem(i,new QTableWidgetItem(QString::fromStdString(colomns[i])));
        for(int j = 0; j < t.row_n();j++) {
            qTable.setItem(j,i,new QTableWidgetItem(QString::fromStdString(t[colomns[i]][j].get_string())));
        }

    }

    for(int j = 0; j < t.row_n();j++) {
        qTable.setVerticalHeaderItem(j,new QTableWidgetItem(QString::fromStdString(std::to_string(j) + " " + t[j].r_name())));
    }

    tablePreview.exec();
}

void csv_node::browse() {

    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"),
                                                    "",
                                                    tr("CSV files (*.csv)"));
    edit.setText(fileName);
}

void csv_node::run() {

}
