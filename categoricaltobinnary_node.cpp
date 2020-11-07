#include "categoricaltobinnary_node.hpp"

categoricalToBinnary_node::categoricalToBinnary_node(int width,int height) : node(width,height,1)
{
    headerText->setText("CAT. TO BINNARY NODE");

    selectLabel.setParent(body);
    listWidget.setParent(body);
    previewBtn.setParent(body);

    selectLabel.setText("Select attribute:");
    previewBtn.setText("preview");
    listWidget.setSelectionMode(QAbstractItemView::MultiSelection);

    selectLabel.setGeometry(geometry().x() + 10,geometry().y() + 10,100,20);
    listWidget.setGeometry(geometry().x() + 10,geometry().y() + 40,230,150);
    previewBtn.setGeometry(geometry().x() + 190,geometry().y() + 200,50,20);
}


void categoricalToBinnary_node::load() {}
void categoricalToBinnary_node::browse() {}
void categoricalToBinnary_node::preview() {}
