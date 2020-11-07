#include "knn_node.hpp"

knn_node::knn_node(int width, int height) : node(width,height,2){
    headerText->setText("KNN NODE");

    previewBtn.setText("preview");
    k_neighbours.setMinimum(1);

    distance_label.setText("distance function");
    k_neighbours_label.setText("k neighbours");
    distance_box.addItem("");
    previewBtn.setText("preview");
    distance_box.addItem("Manhattan distance");
    distance_box.addItem("Euclidean distance");
    distance_box.addItem("SMC distance");
    distance_box.addItem("Zakard distance");
    distance_box.addItem("Cos distance");

    distance_box.setParent(body);
    distance_label.setParent(body);
    k_neighbours.setParent(body);
    k_neighbours_label.setParent(body);
    previewBtn.setParent(body);

    distance_box.setGeometry(geometry().x() + 10,geometry().y() + 10,110,30);
    distance_label.setGeometry(geometry().x() + 130,geometry().y() + 10,110,30);
    k_neighbours.setGeometry(geometry().x() + 10,geometry().y() + 50,110,30);
    k_neighbours_label.setGeometry(geometry().x() + 130,geometry().y() + 50,110,30);
    previewBtn.setGeometry(geometry().x() + 190,geometry().y() + 200,50,20);

}

void knn_node::load() {}
void knn_node::browse() {}
void knn_node::preview() {}
