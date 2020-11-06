#ifndef PARTITION_NODE_HPP
#define PARTITION_NODE_HPP
#include "node.hpp"
#include <QSpinBox>
#include <QPushButton>

class partition_node : public node
{
    Q_OBJECT
public:
    partition_node(int width, int height);

private:
    QSpinBox sb_percent;
    QSpinBox sb_random;
    QPushButton preview_btn;
    QLabel lbl_percent;
    QLabel lbl_random;

public slots:
    void preview();

};

#endif // PARTITION_NODE_HPP
