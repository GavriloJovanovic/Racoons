#include "node.hpp"

extern node * fstSelected, *sndSelected;

edge::edge(node *n1,node *n2) {
    inputNode = n2;
    outputNode = n1;
    inputIndex = inputNode->firstFree();
    inputNode->inputs[inputIndex] = this;
    outputNode->outputs.push_back(this);
    outputNode->outputCircles.push_back(new QGraphicsEllipseItem(0, 0, 10, 10));

    outputIndex = outputNode->outputs.size() - 1;
    globalScene->addItem(outputNode->outputCircles[outputIndex]);
    outputNode->outputCircles[outputIndex]->setPos(outputNode->findPointOutput(outputIndex));

    QPoint begin = inputNode->findPoint(inputIndex);
    QPoint end = outputNode->findPointOutput(outputIndex);

    line = new QGraphicsLineItem(0, 0, 0, 0);
    globalScene->addItem(line);
    line->setLine(begin.x(), begin.y(), end.x(), end.y());

}

void edge::pass(const table & t) {
   if(inputNode && outputNode) {
        inputNode->inputTables[inputIndex] = t;
   }
}

void edge::updateBegin(QPoint q) {
    line->setLine(q.x(),q.y(),line->line().p2().x(),line->line().p2().y());

}
void edge::updateEnd(QPoint q) {
    line->setLine(line->line().p1().x(),line->line().p1().y(),q.x(),q.y());
}

node::node(int width, int height, int inputSize) : QWidget()
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
    inputs.resize(inputSize, nullptr);
    inputTables.resize(inputSize);

    needsUpdate = true;

    int h = (height-20)/2;
    for(int i = 0; i<inputs.size(); i++) {
        QPoint pt = findPoint(i);
        inputCircles.push_back(new QGraphicsEllipseItem(0, 0, 10, 10));
        globalScene->addItem(inputCircles[i]);
        inputCircles[i]->setPos(pt);
    }

   /* input = QPoint(-5,h);
    output = QPoint(width+5, h);
    inputCircle = new QGraphicsEllipseItem(input.x(), -5, 10, 10);
    outputCircle = new QGraphicsEllipseItem(output.x(), -5, 10, 10);


    globalScene->addItem(inputCircle);
    globalScene->addItem(outputCircle);
    inputCircle->setPos(QPoint(geometry().x() - 5, geometry().y() + (geometry().height()/2)));
    outputCircle->setPos(QPoint(geometry().topLeft().x() - 5,  geometry().y() + (geometry().height()/2)));*/

}

QPoint node::findPointOutput(int idx) {
    int segment = geometry().height()/(outputs.size() + 1);

    return QPoint(geometry().topRight().x(), geometry().y() + segment*(idx+1));
}

int node::firstFree() {
    int i = 0;
    for(i; i < inputs.size(); i++)
        if(inputs[i] == nullptr)
            return i;

    return -1;
}

QPoint node::findPoint(int idx) {
    int segment = geometry().height()/(inputs.size() + 1);

    return QPoint(geometry().x() - 10, geometry().y() + segment*(idx+1));
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

        for(int i = 0; i<inputCircles.size(); i++) {
            QPoint pt = findPoint(i);
            inputCircles[i]->setPos(pt);
            if(inputs[i] != nullptr)
                inputs[i]->updateBegin(pt);
        }

        for(int i = 0; i<outputCircles.size(); i++) {
            QPoint pt = findPointOutput(i);
            outputCircles[i]->setPos(pt);
            outputs[i]->updateEnd(pt);
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

