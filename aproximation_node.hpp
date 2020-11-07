#ifndef APROXIMATION_NODE_HPP
#define APROXIMATION_NODE_HPP

#include "node.hpp"
#include <QComboBox>
#include <QLabel>
#include <QListWidget>
#include <QPushButton>
#include <QObject>
#include <QLineEdit>

class aproximation_node : public node
{
    Q_OBJECT
public:
    aproximation_node(int width,int height);
private:
    QComboBox aproximationCombo;
    QLabel aproximationLabel;
    QListWidget listWidget;
    QPushButton previewBtn;
    QLineEdit editAprox;
public slots:
    void load();
    void browse();
    void preview();
};

#endif // APROXIMATION_NODE_HPP
