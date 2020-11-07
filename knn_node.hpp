#ifndef KNN_NODE_HPP
#define KNN_NODE_HPP


#include "node.hpp"
#include "file_reader.hpp"
#include <QLineEdit>
#include <QPushButton>
#include <QTableWidget>
#include <QSpinBox>
#include <QLabel>
#include <QComboBox>

class knn_node : public node
{
    Q_OBJECT
private:
    QComboBox distance_box;
    QPushButton previewBtn;
    QSpinBox k_neighbours;
    QLabel distance_label;
    QLabel k_neighbours_label;



public:
    knn_node(int width, int height);
public slots:
    void load();
    void browse();
    void preview();
};

#endif // KNN_NODE_HPP
