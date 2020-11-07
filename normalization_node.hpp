#ifndef NORMALIZATION_NODE_HPP
#define NORMALIZATION_NODE_HPP
#include "node.hpp"
#include <QListWidget>
#include <QPushButton>
#include <QLineEdit>

class normalization_node : public node
{
    Q_OBJECT
public:
    normalization_node(int width, int height);
public slots:
    void preview();
private:
      QListWidget columns;
      QPushButton preview_btn;
};

#endif // NORMALIZATION_NODE_HPP
