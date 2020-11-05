#ifndef NODE_HPP
#define NODE_HPP

#include<QWidget>
#include<QFrame>
#include<iostream>
#include<QMouseEvent>
#include<QApplication>
#include<QGraphicsEllipseItem>
#include <QGraphicsScene>
#include<QLabel>
#include<QObject>
#include "table.hpp"

extern QGraphicsScene *globalScene;

class node;

class edge {
public:
    edge(node *n1,node *n2);
    void updateBegin(QPoint q);
    void updateEnd(QPoint q);
private:
    node *outputNode;
    node *inputNode;
    int inputIndex;
    int outputIndex;
    QGraphicsLineItem *line;
};



class node : public QWidget
{

public:
    node(int width, int height);
    void setName(std::string name);
    virtual void dragEnterEvent(QDragEnterEvent *event);
    virtual void mousePressEvent(QMouseEvent *event);
    virtual void mouseMoveEvent(QMouseEvent *event);
    virtual void mouseDoubleClickEvent(QMouseEvent *event);
    QPoint dragStart;
    virtual void run();
protected:
    table t;
    std::string name;
    QFrame *header;
    QFrame *body;
    QPoint input;
    QPoint output;
    QGraphicsEllipseItem * inputCircle;
    QGraphicsEllipseItem * outputCircle;
    bool dragged;
    std::vector<edge *> inputs;
    int inputMax;
    int outputMax;
    std::vector<edge *> outputs;
    friend class edge;
    QLabel *headerText;
};

#endif // NODE_HPP
