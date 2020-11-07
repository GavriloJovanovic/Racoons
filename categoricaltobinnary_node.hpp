#ifndef CATEGORICALTOBINNARY_NODE_HPP
#define CATEGORICALTOBINNARY_NODE_HPP

#include "node.hpp"
#include <QLabel>
#include <QListWidget>
#include <QPushButton>
#include <QObject>

class categoricalToBinnary_node : public node
{
    Q_OBJECT
public:
    categoricalToBinnary_node(int width,int height);
private:
    QLabel selectLabel;
    QListWidget listWidget;
    QPushButton previewBtn;
public slots:
    void load();
    void browse();
    void preview();
};

#endif // CATEGORICALTOBINNARY_NODE_HPP
