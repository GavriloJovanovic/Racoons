#ifndef PARTITION_NODE_HPP
#define PARTITION_NODE_HPP
#include "node.hpp"
#include <QSpinBox>
#include <QPushButton>

class partition_node : public node
{

public:
    partition_node(int width, int height);

private:
    QSpinBox *sb_percent;
    QSpinBox *sb_random;
    QPushButton preview_btn;

public slots:
    void preview();

};

#endif // PARTITION_NODE_HPP
