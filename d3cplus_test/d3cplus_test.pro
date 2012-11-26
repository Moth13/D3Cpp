#-------------------------------------------------
#
# Project created by QtCreator 2012-11-07T13:47:46
#
#-------------------------------------------------
VERSION         = 0.0.1
DEFINES         += MSEngine_VERSION=\'\"$$VERSION\"\'

D3CPLUS_DIR     = ../d3cplus
D3CPLUS_OUT_DIR = $$D3CPLUS_DIR/out

QT              += core
QT              += network
QT              -= gui

TARGET          = d3cplus_test
CONFIG          += console
CONFIG          -= app_bundle

TEMPLATE        = app

OBJECTS_DIR     = ./build/objectfile/
MOC_DIR         = ./build/moc/
DESTDIR         = ../out

# include qjson dependences
INCLUDEPATH     += ../out/include
INCLUDEPATH     += ./out/include
DEPENDPATH      += ../out/lib
DEPENDPATH      += ./out/lib

LIBS            += -L../out/lib -ld3cplus
LIBS            += -L./out/lib -ld3cplus
LIBS            += -L./out/lib -lqjson
LIBS            += -L../out/lib -lqjson

SOURCES         += main.cpp
