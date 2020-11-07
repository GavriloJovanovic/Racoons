#include "outputtable_node.hpp"

outputTable_node::outputTable_node(int width,int height) : node(width,height)
{
    headerText->setText("OUTPUT NODE");

    previewBtn.setParent(body);

    previewBtn.setText("preview");

    previewBtn.setGeometry(geometry().x() + 190,geometry().y() + 200,50,20);
}

void outputTable_node::load() {}
void outputTable_node::browse() {}
void outputTable_node::preview() {}
