#ifndef BATTERYMESSAGE_H
#define BATTERYMESSAGE_H

#include <QByteArray>

class BatteryMessage{
public:
    BatteryMessage(const QByteArray& message);

    unsigned char bmuAlive() const;
    unsigned char bmsRelayStatus() const;
    unsigned char populatedCells() const;
    float input12V() const;
    float fanVoltage() const;
    float packCurrent() const;
    float packVoltage() const;
    float packStateOfCharge() const;
    float packAmphours() const;
    float packDepthOfDischarge() const;
    unsigned char highTemperature() const;
    unsigned char highThermistorId() const;
    unsigned char lowTemperature() const;
    unsigned char lowThermistorId() const;
    unsigned char averageTemperature() const;
    unsigned char internalTemperature() const;
    unsigned char fanSpeed() const;
    unsigned char requestedFanSpeed() const;
    short int lowCellVoltage() const;
    unsigned char lowCellVoltageId() const;
    short int highCellVoltage() const;
    unsigned char highCellVoltageId() const;
    short int averageCellVoltage() const;

private:
    const QByteArray message_;
};

#endif // BATTERYMESSAGE_H
