#pragma once

#include <QObject>

class QJsonObject;

class I_BatteryData;
class I_MessageForwarder;

class BatteryJsonForwarder : public QObject
{
    Q_OBJECT
public:
    BatteryJsonForwarder(I_BatteryData& batteryData,
                         I_MessageForwarder& messageForwarder);
    virtual ~BatteryJsonForwarder() {}

public slots:
    void forwardBatteryData(const QJsonObject& baseJson);

private:
    I_BatteryData& batteryData_;
    I_MessageForwarder& messageForwarder_;
};
