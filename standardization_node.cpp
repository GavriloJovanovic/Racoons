#include "standardization_node.hpp"

standardization_node::standardization_node(int width, int height) : node(width, height, 1)
{
    headerText->setText("STANDARDIZE");
    columns.setParent(body);
    columns.setGeometry(10, 10, 230, 150);
    columns.setSelectionMode(QAbstractItemView::MultiSelection);

    preview_btn.setParent(body);
    preview_btn.setGeometry(180, 180, 60, 30);
    preview_btn.setText("preview");

    connect(&preview_btn, SIGNAL(clicked()), this, SLOT(preview()));
}

void standardization_node::preview() {
    //TODO
}
