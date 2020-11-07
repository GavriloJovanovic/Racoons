QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    aproximation_node.cpp \
    binning_node.cpp \
    categoricaltobinnary_node.cpp \
    csv_node.cpp \
    entry.cpp \
    file_reader.cpp \
    knn.cpp \
    knn_node.cpp \
    main.cpp \
    mainwindow.cpp \
    node.cpp \
    outputtable_node.cpp \
    partition_node.cpp \
    stats.cpp \
    table.cpp \
    transformations.cpp

HEADERS += \
    aproximation_node.hpp \
    binning_node.hpp \
    categoricaltobinnary_node.hpp \
    csv_node.hpp \
    entry.hpp \
    file_reader.hpp \
    knn.hpp \
    knn_node.hpp \
    mainwindow.h \
    mainwindow.hpp \
    node.hpp \
    outputtable_node.hpp \
    partition_node.hpp \
    stats.hpp \
    table.hpp \
    transformations.hpp

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

SUBDIRS += \
    Rakun_gki.pro \
    Rakun_gki.pro \
    Rakuncina.pro \
    Rakuncina.pro

RESOURCES += \
    resources.qrc \
    resources.qrc

DISTFILES += \
    README.md \
    Rakun_gki.pro.user \
    Rakuncina.pro.user \
    Rakunko.pro.user \
    csv_icon.png \
    iris.csv \
    iris.csv.csv \
    test.csv
