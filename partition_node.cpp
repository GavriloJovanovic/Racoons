#include "partition_node.hpp"
#include "transformations.hpp"
#include <QDialog>
#include<QHBoxLayout>
#include<QTableWidget>

partition_node::partition_node(int width, int height) : node(width, height, 1)
{
    headerText->setText("PARTITION NODE");
    preview_btn.setParent(body);
    preview_btn.setText("preview");
    preview_btn.setGeometry(5, 75, 60, 30);

    lbl_percent.setParent(body);
    lbl_percent.setText("Train/test ratio:");
    lbl_percent.setGeometry(5,5,100,30);
    sb_percent.setParent(body);
    sb_percent.setGeometry(105, 5, 40, 30);

    lbl_random.setParent(body);
    lbl_random.setText("Randomness seed:");
    lbl_random.setGeometry(5, 40, 120, 30);
    sb_random.setParent(body);
    sb_random.setGeometry(125, 40, 40, 30);
    sb_random.setMinimum(0);

    sb_percent.setMinimum(0);
    sb_percent.setMaximum(100);

    connect(&preview_btn,SIGNAL(clicked()),this,SLOT(preview()));
    connect(&sb_percent, QOverload<int>::of(&QSpinBox::valueChanged),
        [=](int i){ needsUpdate = true; });

    connect(&sb_random, QOverload<int>::of(&QSpinBox::valueChanged),
        [=](int i){ needsUpdate = true; });

}

void partition_node::preview() {
    t = inputTables[0];
    partition(t, (float)sb_percent.value()/100.0f, sb_random.value());
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
