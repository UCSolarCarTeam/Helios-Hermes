
QT += serialport widgets network svg
CONFIG += c++11 debug console static

!win32 {
   QMAKE_CXXFLAGS += -Werror
}

INCLUDEPATH += ..

OBJECTS_DIR = ../../build/.obj
MOC_DIR = ../../build/.moc
RCC_DIR = ../../build/.rcc
UI_DIR = ../../build/.ui

LIBS += -lSimpleAmqpClient -lrabbitmq
