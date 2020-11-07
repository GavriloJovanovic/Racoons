#include "binning_node.hpp"

binning_node::binning_node(int width, int height) : node(width,height,1)
{
    headerText->setText("BINNING NODE");

    listWidget.setParent(body);
    binningMethod.setParent(body);
    binningShuffle.setParent(body);
    binningMethodLabel.setParent(body);
    binningShuffleLabel.setParent(body);
    previewBtn.setParent(body);

    listWidget.setSelectionMode(QAbstractItemView::MultiSelection);
    binningMethodLabel.setText("Method:");
    binningShuffleLabel.setText("Representation:");
    binningMethod.addItem("binning width");
    binningMethod.addItem("binning frequency");
    previewBtn.setText("preview");
    binningShuffle.addItem("By mean");
    binningShuffle.addItem("By border");

    listWidget.setGeometry(geometry().x() + 10,geometry().y() + 10,230,130);
    binningMethodLabel.setGeometry(geometry().x() + 10,geometry().y() + 150,110,20);
    binningShuffleLabel.setGeometry(geometry().x() + 130,geometry().y() + 150,110,20);
    binningMethod.setGeometry(geometry().x() + 10,geometry().y() + 180,110,20);
    binningShuffle.setGeometry(geometry().x() + 130,geometry().y() + 180,110,20);
    previewBtn.setGeometry(geometry().x() + 190,geometry().y() + 205,50,20);
}

void binning_node::load() {}
void binning_node::browse() {}
void binning_node::preview() {}
