#ifndef FILTER_NODE_HPP
#define FILTER_NODE_HPP
#include "node.hpp"
#include <QListWidget>
#include <QPushButton>
#include <QLineEdit>

class filter_node : public node
{
    Q_OBJECT
public:
    filter_node(int width, int height);
public slots:
    void preview();
private:
      QLabel columns_lbl;
      QListWidget columns;
      QPushButton preview_btn;

};

#endif // FILTER_NODE_HPP
