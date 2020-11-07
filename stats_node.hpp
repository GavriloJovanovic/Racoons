#ifndef STATS_NODE_HPP
#define STATS_NODE_HPP
#include "node.hpp"
#include <QListWidget>
#include <QPushButton>
#include <QLineEdit>

class stats_node : public node
{
    Q_OBJECT
public:
    stats_node(int width, int height);
public slots:
    void preview();
private:
    QLabel stats_lbl;
    QListWidget stats;
    QPushButton preview_btn;
};

#endif // STATS_NODE_HPP
