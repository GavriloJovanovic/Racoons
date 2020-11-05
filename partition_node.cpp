#include "partition_node.hpp"
#include <QDialog>
#include<QHBoxLayout>
#include<QTableWidget>

partition_node::partition_node(int width, int height) : node(width, height)
{
    headerText->setText("PARTITION");

    connect(&preview_btn,SIGNAL(clicked()),this,SLOT(preview()));
}

void partition_node::preview() {
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
