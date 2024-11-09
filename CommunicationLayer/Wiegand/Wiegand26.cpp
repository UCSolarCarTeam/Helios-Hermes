#include "Wiegand26.h"
#include <QDebug>

Wiegand26::Wiegand26(QObject *parent) : QThread(parent), serialPort(new QSerialPort(this)) {
    connect(serialPort, &QSerialPort::readyRead, this, &Wiegand26::handleReadyRead);
}

void Wiegand26::begin(const QString &portName) {
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

    start();
}

void Wiegand26::run() {
    while (running) {
        QThread::msleep(10);
    }
}

void Wiegand26::stop() {
    running = false;
    serialPort->close();
    wait();
}

void Wiegand26::reset() {
    _bitCnt = 0;
    buffer.clear();
    std::fill(std::begin(_bitData), std::end(_bitData), false);
}

void Wiegand26::processBuffer() {
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

void Wiegand26::handleReadyRead() {
    buffer.append(serialPort->readAll());
    processBuffer();
}
