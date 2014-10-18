#-------------------------------------------------
#
# Project created by QtCreator 2014-10-13T12:01:32
#
#-------------------------------------------------

QT       += core gui serialport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SolarCarTelemetry
TEMPLATE = app


SOURCES += main.cpp\
    DataPopulator.cpp \
    SolarCarTelemetry.cpp \
    DataParser.cpp \
    TelemetryData.cpp \
    SerialPortConnectionService.cpp

HEADERS  += \
    DataPopulator.h \
    SolarCarTelemetry.h \
    I_DataParser.h \
    I_TelemetryData.h \
    TelemetryData.h \
    I_ConnectionService.h \
    SerialPortConnectionService.h


FORMS    +=