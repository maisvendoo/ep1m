QT -= gui

QT += core
QT += gui
QT += widgets
QT += opengl
QT += xml

TEMPLATE = lib
DEFINES += MSUD_DISPLAY_LIBRARY

CONFIG += c++11

DESTDIR = $$(RRS_DEV_ROOT)/modules/ep1m

LIBS += -L$$(RRS_DEV_ROOT)/bin -ldisplay

LIBS += -lgcov
CONFIG += force_debug_info

INCLUDEPATH += ./include
INCLUDEPATH += $$(RRS_DEV_ROOT)/sdk/include
INCLUDEPATH += ../ep1m/include
INCLUDEPATH += ../ep1m-equipment/include

HEADERS += $$files(./include/*.h)
HEADERS += $$files(../ep1m/include/*.h)
SOURCES += $$files(./src/*.cpp)
RESOURCES += $$files(./resources/*.qrc)
