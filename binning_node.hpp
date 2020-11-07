#ifndef BINNING_NODE_HPP
#define BINNING_NODE_HPP

#include "node.hpp"
#include <QComboBox>
#include <QLabel>
#include <QListWidget>
#include <QPushButton>
#include <QObject>

class binning_node : public node
{
    Q_OBJECT
private:
    QListWidget listWidget;
    QComboBox binningMethod;
    QComboBox binningShuffle;
    QLabel binningMethodLabel;
    QLabel binningShuffleLabel;
    QPushButton previewBtn;
public:
    binning_node(int width, int height);
public slots:
    void load();
    void browse();
    void preview();
};

#endif // BINNING_NODE_HPP
