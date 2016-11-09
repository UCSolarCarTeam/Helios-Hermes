#pragma once

#include <QScopedPointer>
#include <QTimer>

#include "I_JsonForwarder.h"

class BatteryJsonForwarder;
class FaultsJsonForwarder;
class PowerJsonForwarder;
class VehicleJsonForwarder;

class I_BatteryData;
class I_FaultsData;
class I_PowerData;
class I_VehicleData;
class I_MessageForwarder;
class I_Settings;

class JsonForwarder : public I_JsonForwarder
{
    Q_OBJECT
public:
    JsonForwarder(I_BatteryData& batteryData,
                  I_FaultsData& faultsData,
                  I_PowerData& powerData,
                  I_VehicleData& vehicleData,
                  I_MessageForwarder& messageForwarder,
                  I_Settings& settings);
    virtual ~JsonForwarder();
    void startForwardingData();

private slots:
    void forwardData();

private:
    QScopedPointer<BatteryJsonForwarder> batteryJsonForwarder_;
    QScopedPointer<FaultsJsonForwarder> faultsJsonForwarder_;
    QScopedPointer<PowerJsonForwarder> powerJsonForwarder_;
    QScopedPointer<VehicleJsonForwarder> vehicleJsonForwarder_;
    QScopedPointer<QTimer> readTimer_;
    int dataToReadCount_;
    int forwardPeriod_;
    const QString PACKET_TITLE_;
};
