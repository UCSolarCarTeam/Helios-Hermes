#include "GPIOReader.h"
#include <QDebug>

GPIOReader::GPIOReader(QObject* parent) : QThread(parent), serialPort(new QSerialPort(this)) {
    connect(serialPort, &QSerialPort::readyRead, this, &GPIOReader::handleReadyRead);
}

GPIOReader::~GPIOReader() {
    stop();
    delete serialPort;
}

void GPIOReader::begin(const QString& portName) {
    serialPort->setPortName(portName);
    serialPort->setBaudRate(QSerialPort::Baud9600);
    serialPort->setDataBits(QSerialPort::Data8);
    serialPort->setParity(QSerialPort::NoParity);
    serialPort->setStopBits(QSerialPort::OneStop);
    serialPort->setFlowControl(QSerialPort::NoFlowControl);

    if (serialPort->open(QIODevice::ReadOnly)) {
        qDebug() << "Serial port opened successfully.";
    } else {
        qWarning() << "Failed to open serial port.";
        return;
    }

    running = true;
    start();
}

void GPIOReader::run() {
    while (running) {
        QThread::msleep(10);
    }
}

void GPIOReader::stop() {
    running = false;
    if (serialPort->isOpen()) {
        serialPort->close();
    }
    wait();
}

void GPIOReader::reset() {
    _bitCnt = 0;
    buffer.clear();
    std::fill(std::begin(_bitData), std::end(_bitData), false);
}

void GPIOReader::processBuffer() {
    while (buffer.size() > 0 && _bitCnt < MAX_BITS) {
        char byte = buffer.at(0);
        buffer.remove(0, 1);

        if (byte == '0') {
            _bitData[_bitCnt++] = false;
        } else if (byte == '1') {
            _bitData[_bitCnt++] = true;
        }

        if (_bitCnt >= MAX_BITS) {
            unsigned long data = 0;
            for (int i = 1; i < MAX_BITS - 1; i++) {
                if (_bitData[i]) {
                    data |= (1UL << (i - 1));
                }
            }
            emit onData(data);
            reset();
        }
    }
}

void GPIOReader::handleReadyRead() {
    buffer.append(serialPort->readAll());
    processBuffer();
}
