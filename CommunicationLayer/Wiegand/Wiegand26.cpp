#include "Wiegand26.h"
#include <QDebug>
#include <QThread>

// Constructor
Wiegand26::Wiegand26(QObject *parent) : QThread(parent), _bitCnt(0), _swapData(false) {
    _bitData.fill(false, MAX_BITS);
    connect(&_timeoutTimer, &QTimer::timeout, this, &Wiegand26::reset);
}

// Begin function initializes pins
void Wiegand26::begin(int pinData0, int pinData1, bool swapData) {
    _pinData0 = pinData0;
    _pinData1 = pinData1;
    _swapData = swapData;

    // Assuming a GPIO abstraction layer, you can initialize GPIO here.
    // Replace with actual GPIO handling for your system, e.g., wiringPi, or custom wrapper.
    qDebug() << "Initializing Wiegand on pins" << _pinData0 << "and" << _pinData1;

    // Setup debounce timer for timeouts
    _timeoutTimer.setInterval(20); // Adjust timeout as needed
}

// Reset state
void Wiegand26::reset() {
    _bitCnt = 0;
    _bitData.fill(false, MAX_BITS);
    _timeoutTimer.stop();
}

// Process received bit
void Wiegand26::processBit(int bitValue) {
    if (_bitCnt >= MAX_BITS) return; // Ignore extra bits

    _bitData[_bitCnt++] = (bitValue > 0);
    _timeoutTimer.start();  // Restart timeout

    if (_bitCnt == MAX_BITS) {
        emitData();
    }
}

// Emit data if 26 bits received
void Wiegand26::emitData() {
    _timeoutTimer.stop();

    unsigned long data = 0;
    for (int i = 0; i < MAX_BITS; ++i) {
        if (_bitData[i]) {
            data |= (1UL << (MAX_BITS - i - 1));
        }
    }

    if (!checkParity()) {
        emit errorOccurred("Parity check failed");
        reset();
        return;
    }

    emit dataReceived(data);
    reset();
}

// Simple parity check for 26-bit Wiegand
bool Wiegand26::checkParity() {
    // Adjust parity validation logic here
    return true;  // Placeholder: actual parity logic implementation
}

// Main run loop to monitor GPIO pins
void Wiegand26::run() {
    while (true) {
        // Simulate GPIO readings, replace with actual reads
        QThread::msleep(5); // Adjust to debounce

        int data0 = 0; // Read GPIO value (dummy)
        int data1 = 0; // Read GPIO value (dummy)

        if (data0 == 0) {
            processBit(0);
        } else if (data1 == 0) {
            processBit(1);
        }
    }
}
