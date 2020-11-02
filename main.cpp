#include "table.hpp"
#include "file_reader.hpp"
#include "transformations.hpp"
#include "knn.hpp"
#include "stats.hpp"
#include "mainwindow.h"
#include <QApplication>

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);
    MainWindow window;

    window.show();


    return app.exec();
}
