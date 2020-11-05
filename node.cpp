#include "node.hpp"

extern node * fstSelected, *sndSelected;

edge::edge(node *n1,node *n2) {
    inputNode = n2;
    outputNode = n1;
    inputNode->inputs.push_back(this);
    outputNode->outputs.push_back(this);
    inputIndex = inputNode->inputs.size() - 1;
    outputIndex = outputNode->outputs.size() - 1;
    line = new QGraphicsLineItem(n1->geometry().topRight().x(),n1->geometry().topRight().y() + n1->geometry().width()/2,
        n2->geometry().topLeft().x(),n2->geometry().topRight().y() + n2->geometry().width()/2);
    globalScene->addItem(line);
}

void edge::updateBegin(QPoint q) {
    line->setLine(q.x(),q.y(),line->line().p2().x(),line->line().p2().y());

}
void edge::updateEnd(QPoint q) {
    line->setLine(line->line().p1().x(),line->line().p1().y(),q.x(),q.y());
}

node::node(int width, int height) : QWidget()
{
    dragged = false;
    header = new QFrame(this);
    body = new QFrame(this);
    setGeometry(0, 0, width, height);
    header->setGeometry(0,0,width,20);
    body->setGeometry(0, 20, width, height - 20);
    body->setStyleSheet("QFrame {border: 1px solid black}");
    headerText = new QLabel("node",header);
    headerText->setGeometry(0,0,width,20);
    headerText->setAlignment(Qt::AlignCenter);

    int h = (height-20)/2;
    input = QPoint(-5,h);
    output = QPoint(width+5, h);
    inputCircle = new QGraphicsEllipseItem(input.x(), -5, 10, 10);
    outputCircle = new QGraphicsEllipseItem(output.x(), -5, 10, 10);


    globalScene->addItem(inputCircle);
    globalScene->addItem(outputCircle);
    inputCircle->setPos(QPoint(geometry().x() - 5, geometry().y() + (geometry().height()/2)));
    outputCircle->setPos(QPoint(geometry().topLeft().x() - 5,  geometry().y() + (geometry().height()/2)));

}

void node::dragEnterEvent(QDragEnterEvent *event)
{

}

void node::mousePressEvent(QMouseEvent *event)
{
    if(event->button() & Qt::LeftButton) {
        dragStart = event->pos();
        dragged = true;
    }
}
void node::mouseMoveEvent(QMouseEvent *event)
{
    if(!(event->buttons() & Qt::LeftButton)) {
        return;
        dragged = false;
    }
    if((event->pos() - dragStart).manhattanLength() < QApplication::startDragDistance())
        return;
    if(dragged || header->geometry().contains(event->pos())) {
        QPoint temp = geometry().topLeft() + event->pos() - dragStart;
        setGeometry(QRect(temp, rect().size()));
        input = QPoint(temp.x() - 5, geometry().y() + (geometry().height()/2));
        output = QPoint(geometry().topLeft().x() - 5,  geometry().y() + (geometry().height()/2));
        inputCircle->setPos(input);
        outputCircle->setPos(output);
        for(int i = 0; i < outputs.size();i++) {
            outputs[i]->updateBegin(QPoint(geometry().topRight().x(),geometry().topRight().y() + geometry().height() / 2));
        }
        for(int i = 0; i < inputs.size();i++) {
            inputs[i]->updateEnd(input);
        }
    }
}

void node::mouseDoubleClickEvent(QMouseEvent *event) {
    if(event->button() == Qt::LeftButton) {
        if(fstSelected == nullptr) {
            fstSelected = this;
            setStyleSheet("QWidget{border: 2px dotted green}");
        }
        else if(sndSelected == nullptr && fstSelected != this) {
            sndSelected = this;
            setStyleSheet("QWidget{border: 2px dotted red}");
        }
    }
}

void node::run() {

}

