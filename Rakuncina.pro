QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    edge.cpp \
    entry.cpp \
    file_reader.cpp \
    knn.cpp \
    main.cpp \
    mainwindow.cpp \
    node.cpp \
    stats.cpp \
    table.cpp \
    transformations.cpp

HEADERS += \
    edge.hpp \
    entry.hpp \
    file_reader.hpp \
    knn.hpp \
    mainwindow.h \
    node.hpp \
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
    Rakun_gki.pro

RESOURCES += \
    resources.qrc

DISTFILES += \
    README.md \
    Rakun_gki.pro.user \
    Rakuncina.pro.user \
    csv_icon.png \
    iris.csv \
    test.csv
