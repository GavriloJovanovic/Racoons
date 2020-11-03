#include "node.hpp"


node::node(int width, int height) : QWidget()
{
    header = new QFrame(this);
    body = new QFrame(this);
    setGeometry(0, 0, width, height);
    header->setGeometry(0,0,width,20);
    body->setGeometry(0, 20, width, height - 20);
    body->setStyleSheet("QFrame {border: 1px solid black}");

    int h = (height-20)/2;
    input = QPoint(-5,h);
    output = QPoint(width+5, h);
    inputCircle = new QGraphicsEllipseItem(input.x(), input.y(), 5, 5);
    outputCircle = new QGraphicsEllipseItem(output.x(), output.y(), 5, 5);

    globalScene->addItem(inputCircle);
    globalScene->addItem(outputCircle);

}

void node::dragEnterEvent(QDragEnterEvent *event)
{

}

void node::mousePressEvent(QMouseEvent *event)
{
    if(event->button() & Qt::LeftButton)
        dragStart = event->pos();

}
void node::mouseMoveEvent(QMouseEvent *event)
{
    if(!(event->buttons() & Qt::LeftButton))
        return;
    if((event->pos() - dragStart).manhattanLength() < QApplication::startDragDistance())
        return;
    if(header->geometry().contains(event->pos())) {
        QPoint temp = geometry().topLeft() + event->pos() - dragStart;
        setGeometry(QRect(temp, rect().size()));
        input = QPoint(temp.x() - 5, (temp.y() - 20)/2);
        output = QPoint(temp.x() + 5 + rect().size().width(), (temp.y() - 20)/2);
        inputCircle->setPos(input);
        outputCircle->setPos(output);
    }
}

