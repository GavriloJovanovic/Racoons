#include "aproximation_node.hpp"

aproximation_node::aproximation_node(int width,int height) : node(width,height)
{
    headerText->setText("APROXIMATION NODE");

    aproximationCombo.setParent(body);
    aproximationLabel.setParent(body);
    listWidget.setParent(body);
    previewBtn.setParent(body);
    editAprox.setParent(body);

    listWidget.setSelectionMode(QAbstractItemView::MultiSelection);
    aproximationLabel.setText("Choose method and attribute:");
    aproximationCombo.addItem("By mean");
    aproximationCombo.addItem("By user adding");
    editAprox.setPlaceholderText("enter value for n/a");
    previewBtn.setText("preview");

    aproximationLabel.setGeometry(geometry().x() + 10,geometry().y() + 10,230,20);
    aproximationCombo.setGeometry(geometry().x() + 10,geometry().y() + 40,110,20);
    editAprox.setGeometry(geometry().x() + 130,geometry().y() + 40,110,20);
    listWidget.setGeometry(geometry().x() + 10,geometry().y() + 70,230,120);
    previewBtn.setGeometry(geometry().x() + 190,geometry().y() + 200,50,20);
}


void aproximation_node::load() {}
void aproximation_node::browse() {}
void aproximation_node::preview() {}

