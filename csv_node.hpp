#ifndef CSV_NODE_HPP
#define CSV_NODE_HPP

#include "node.hpp"
#include "file_reader.hpp"
#include <QLineEdit>
#include <QPushButton>
#include <QTableWidget>

class csv_node : public node
{
    Q_OBJECT
private:
    QLineEdit edit;
    QPushButton browseBtn;
    QPushButton loadBtn;
    QTableWidget colomns;
    QPushButton previewBtn;
    QPushButton runBtn;



public:
    csv_node(int width, int height);
    void run() override;
public slots:
    void load();
    void browse();
    void preview();
};

#endif // CSV_NODE_HPP
