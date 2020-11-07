#include "stats_node.hpp"

stats_node::stats_node(int width, int height) : node(width, height, 1)
{
    headerText->setText("TABLE STATS");

    stats_lbl.setParent(body);
    stats_lbl.setGeometry(10, 0, 200, 30);
    stats_lbl.setText("Select stats to view:");

    stats.setParent(body);
    stats.setGeometry(10, 30, 230, 140);
    stats.setSelectionMode(QAbstractItemView::MultiSelection);
    stats.addItem("min. element");
    stats.addItem("max. element");
    stats.addItem("sum");
    stats.addItem("mean");
    stats.addItem("range");
    stats.addItem("standard deviation");
    stats.addItem("variance");
    stats.addItem("unique");
    stats.addItem("valid");

    preview_btn.setParent(body);
    preview_btn.setGeometry(180, 180, 60, 30);
    preview_btn.setText("preview");

    connect(&preview_btn, SIGNAL(clicked()), this, SLOT(preview()));
}

void stats_node::preview() {}
