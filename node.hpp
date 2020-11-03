#ifndef NODE_HPP
#define NODE_HPP

#include<QWidget>
#include<QFrame>
#include<iostream>
#include<QMouseEvent>
#include<QApplication>
#include<QGraphicsEllipseItem>
#include <QGraphicsScene>

extern QGraphicsScene *globalScene;


class node : public QWidget
{
public:
    node(int width, int height);
    void setName(std::string name);
    virtual void dragEnterEvent(QDragEnterEvent *event);
    virtual void mousePressEvent(QMouseEvent *event);
    virtual void mouseMoveEvent(QMouseEvent *event);
    QPoint dragStart;

protected:
    std::string name;
    QFrame *header;
    QFrame *body;
    QPoint input;
    QPoint output;
    QGraphicsEllipseItem * inputCircle;
    QGraphicsEllipseItem * outputCircle;

};

#endif // NODE_HPP
