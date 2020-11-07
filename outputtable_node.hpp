#ifndef OUTPUTTABLE_NODE_HPP
#define OUTPUTTABLE_NODE_HPP

#include "node.hpp"
#include <QPushButton>
#include <QObject>

class outputTable_node : public node
{
    Q_OBJECT
public:
    outputTable_node(int width,int height);
private:
    QPushButton previewBtn;
public slots:
    void load();
    void browse();
    void preview();
};

#endif // OUTPUTTABLE_NODE_HPP
