#include "GPIOReader.h"
#include <QDebug>
#include <unistd.h>

// Constructor
GPIOReader::GPIOReader(QObject* parent) : QThread(parent) {
    begin(20, 21);
}

// Destructor
GPIOReader::~GPIOReader() {
    stop();
    gpioTerminate();
}

// Begin function to initialize GPIO pins
void GPIOReader::begin(int pinData0, int pinData1) {
    _pinData0 = pinData0;
    _pinData1 = pinData1;

    if (gpioInitialise() < 0) {
        qWarning() << "pigpio initialization failed.";
        return;
    }

    gpioSetMode(_pinData0, PI_INPUT);
    gpioSetMode(_pinData1, PI_INPUT);

    gpioSetAlertFuncEx(_pinData0, data0ISR, this);
    gpioSetAlertFuncEx(_pinData1, data1ISR, this);

    reset();
    running = true;
    start();
}

// Stop function to clean up
void GPIOReader::stop() {
    running = false;
    wait();
    gpioSetAlertFunc(_pinData0, nullptr);
    gpioSetAlertFunc(_pinData1, nullptr);
    gpioTerminate();
}

// Reset the internal state
void GPIOReader::reset() {
    _bitCnt = 0;
    _data = 0;
    std::fill(std::begin(_bitData), std::end(_bitData), false);
}

// Emit data after full 26 bits received
void GPIOReader::emitData() {
    for (int i = 1; i < MAX_BITS - 1; ++i) {
        if (_bitData[i]) {
            _data |= (1UL << (i - 1));
        }
    }
    // emit onData(_data);
    QByteArray dataArray = QByteArray::number(_data);
    packetFactory_->getPiPacket().populatePacket(dataArray);
    reset();
}

// ISR for Data0 (logical 0)
void GPIOReader::data0ISR(int gpio, int level, uint32_t tick, void* userdata) {
    GPIOReader* instance = static_cast<GPIOReader*>(userdata);
    if (level == 0) { // Falling edge
        instance->_bitData[instance->_bitCnt++] = false;
        if (instance->_bitCnt >= MAX_BITS) {
            instance->emitData();
        }
    }
}

// ISR for Data1 (logical 1)
void GPIOReader::data1ISR(int gpio, int level, uint32_t tick, void* userdata) {
    GPIOReader* instance = static_cast<GPIOReader*>(userdata);
    if (level == 0) { // Falling edge
        instance->_bitData[instance->_bitCnt++] = true;
        if (instance->_bitCnt >= MAX_BITS) {
            instance->emitData();
        }
    }
}

// Main run loop (can be used for additional logic)
void GPIOReader::run() {
    while (running) {
        usleep(10000); // Polling interval (10ms)
    }
}
