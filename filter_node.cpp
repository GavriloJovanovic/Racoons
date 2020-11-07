#include "filter_node.hpp"

filter_node::filter_node(int width, int height) : node(width, height, 1)
{
    headerText->setText("FILTER COLUMNS");

    columns_lbl.setParent(body);
    columns_lbl.setGeometry(10, 0, 200, 30);
    columns_lbl.setText("Select columns to remove:");

    columns.setParent(body);
    columns.setGeometry(10, 30, 230, 140);
    columns.setSelectionMode(QAbstractItemView::MultiSelection);

    preview_btn.setParent(body);
    preview_btn.setGeometry(180, 180, 60, 30);
    preview_btn.setText("preview");

    connect(&preview_btn, SIGNAL(clicked()), this, SLOT(preview()));
}

void filter_node::preview() {
    //TODO
}
