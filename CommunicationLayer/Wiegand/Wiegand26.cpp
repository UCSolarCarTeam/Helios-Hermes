#include "Wiegand26.h"
#include <QDebug>
#include <QThread>

Wiegand26::Wiegand26(QObject *parent)
    : QThread(parent), _bitCnt(0), _swapData(false) {
    _bitData.fill(false, MAX_BITS);
    connect(&_timeoutTimer, &QTimer::timeout, this, &Wiegand26::reset);
}

void Wiegand26::begin(int pinData0, int pinData1, bool swapData) {
    _pinData0 = pinData0;
    _pinData1 = pinData1;
    _swapData = swapData;

    qDebug() << "Initializing Wiegand on pins" << _pinData0 << "and" << _pinData1;

    _timeoutTimer.setInterval(20);
}

void Wiegand26::reset() {
    _bitCnt = 0;
    _bitData.fill(false, MAX_BITS);
    _timeoutTimer.stop();
}

void Wiegand26::processBit(int bitValue) {
    if (_bitCnt >= MAX_BITS) return;

    _bitData[_bitCnt++] = (bitValue > 0);
    _timeoutTimer.start();

    if (_bitCnt == MAX_BITS) {
        emitData();
    }
}

void Wiegand26::emitData() {
    _timeoutTimer.stop();

    QByteArray rawData;
    for (bool bit : _bitData) {
        rawData.append(bit ? '1' : '0');
    }

    if (!checkParity(_bitData)) {
        emit errorOccurred("Parity check failed");
        reset();
        return;
    }

    emit dataReceived(rawData.toULongLong(nullptr, 2));
    reset();
}

bool Wiegand26::checkParity(const QVector<bool>& bits) {
    // Implement parity checks (Placeholder logic)
    return true;
}

QByteArray Wiegand26::readData() {
    QByteArray data;
    // Logic to convert _bitData to QByteArray
    for (int i = 0; i < _bitCnt; ++i) {
        data.append(_bitData[i] ? '1' : '0');
    }
    return data;
}

QByteArray Wiegand26::parse(const QByteArray& rawData) {
    // Implement parsing logic here
    QByteArray parsedData = rawData.mid(1, 24);  // Example: Extract data bits
    return parsedData;
}

void Wiegand26::run() {
    while (true) {
        QThread::msleep(5);

        int data0 = 0;  // Simulate GPIO value
        int data1 = 0;  // Simulate GPIO value

        if (data0 == 0) {
            processBit(0);
        } else if (data1 == 0) {
            processBit(1);
        }
    }
}
