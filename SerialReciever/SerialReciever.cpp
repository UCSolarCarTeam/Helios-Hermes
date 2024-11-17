#include "SerialReciever.h"
#include "../Config/ConfigManager.h"

#include <QDebug>

SerialReciever::SerialReciever() {
    serialPort_ = new QSerialPort(this);

    ConfigManager& config = ConfigManager::instance();

    serialPort_->setPortName(config.getPortName());
    serialPort_->setBaudRate(config.getBaudrate());
    serialPort_->setDataBits(QSerialPort::Data8);
    serialPort_->setParity(QSerialPort::NoParity);
    serialPort_->setStopBits(QSerialPort::OneStop);

    //TODO: add retry period/detection mechinism for serial device
    if (serialPort_->open(QIODevice::ReadOnly)) {
        qDebug() << "Serial Port Opened: " << config.getPortName();
        connect(serialPort_, &QSerialPort::readyRead, this, &SerialReciever::handleReadyRead);
    } else {
        qWarning() << "EXITING - Failed to open serial port (" << config.getPortName() << "): " << serialPort_->errorString();
        exit(1);
    }
}

SerialReciever::~SerialReciever() {
    if(serialPort_->isOpen()) {
        serialPort_->close();
    }
}

void SerialReciever::handleReadyRead() {
    QByteArray data = serialPort_->readAll();

    qDebug() << "Data Recieved: " << data;

    if(data.isEmpty()) {
        qDebug() << "Incoming data is empty";
        return;
    }

    emit dataRecieved(data);
}