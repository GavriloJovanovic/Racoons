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
    void pass(const table & t);
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
    node(int width, int height, int inputSize = 1);
    void setName(std::string name);
    virtual void dragEnterEvent(QDragEnterEvent *event);
    virtual void mousePressEvent(QMouseEvent *event);
    virtual void mouseMoveEvent(QMouseEvent *event);
    virtual void mouseDoubleClickEvent(QMouseEvent *event);
    QPoint dragStart;
    QPoint findPoint(int idx);
    QPoint findPointOutput(int idx);
    int firstFree();
    virtual void run();
protected:
    bool needsUpdate;
    table t;
    std::string name;
    QFrame *header;
    QFrame *body;
    std::vector<QGraphicsEllipseItem *> inputCircles;
    std::vector<QGraphicsEllipseItem *> outputCircles;
    bool dragged;
    std::vector<edge *> inputs;
    std::vector<edge *> outputs;
    std::vector<table> inputTables;
    friend class edge;
    QLabel *headerText;
};

#endif // NODE_HPP
