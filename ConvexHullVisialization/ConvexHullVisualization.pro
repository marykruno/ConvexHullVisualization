QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    ConvexHullModelFabric.cpp \
    ConvexHullModelGraham.cpp \
    ConvexHullModelJarvis.cpp \
    ConvexHullModelQuick.cpp \
    ConvexHullModelVectorContainer.cpp \
    ConvexHullRenderer.cpp \
    algorithmSelectionDialog.cpp \
    customGraphicsView.cpp \
    main.cpp \
    mainwindow.cpp \
    utilities.cpp

HEADERS += \
    ConvexHullGraham.h \
    ConvexHullJarvis.h \
    ConvexHullModelBase.h \
    ConvexHullModelFabric.h \
    ConvexHullModelGraham.h \
    ConvexHullModelJarvis.h \
    ConvexHullModelQuick.h \
    ConvexHullModelVectorContainers.h \
    ConvexHullQuick.h \
    ConvexHullRendrer.h \
    algorithmSelectionDialog.h \
    customGraphicsView.h \
    mainwindow.h \
    utilities.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
