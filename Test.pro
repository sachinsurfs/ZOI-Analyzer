#-------------------------------------------------
#
# Project created by QtCreator 2014-08-25T19:57:10
#
#-------------------------------------------------

QT       += core gui
QT       += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = test2
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    guideline.cpp \
    newexp.cpp \
    cvbody.cpp \
    errordialog.cpp \
    valuetable.cpp \
    dataentry.cpp

HEADERS  += mainwindow.h \
    guideline.h \
    newexp.h \
    cvbody.h \
    errordialog.h \
    valuetable.h \
    dataentry.h

FORMS    += mainwindow.ui \
    guideline.ui \
    newexp.ui \
    cvbody.ui \
    errordialog.ui \
    valuetable.ui \
    dataentry.ui


INCLUDEPATH += /usr/local/include/opencv2
INCLUDEPATH += /usr/local/include/opencv

LIBS += -L/usr/local/lib
LIBS += -lopencv_core
LIBS += -lopencv_imgproc
LIBS += -lopencv_highgui
LIBS += -lopencv_ml
LIBS += -lopencv_video
LIBS += -lopencv_features2d
LIBS += -lopencv_calib3d
LIBS += -lopencv_objdetect
LIBS += -lopencv_contrib
LIBS += -lopencv_legacy
LIBS += -lopencv_flann

RESOURCES += \
    Resources.qrc
