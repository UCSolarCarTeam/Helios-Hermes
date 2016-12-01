#pragma once

#include <QObject>

class I_VehicleData;
class I_MessageForwarder;

class VehicleJsonForwarder : public QObject
{
    Q_OBJECT
public:
    VehicleJsonForwarder(/*I_VehicleData& vehicleData,*/
                         I_MessageForwarder& messageForwarder);
    virtual ~VehicleJsonForwarder() {}

public slots:
    void forwardVehicleData(const QJsonObject& baseJson);

private:
//    I_VehicleData& vehicleData_;
    I_MessageForwarder& messageForwarder_;
};
