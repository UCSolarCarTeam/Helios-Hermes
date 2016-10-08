#pragma once

#include <QObject>

class I_PowerData;
class I_MessageForwarder;

class PowerJsonForwarder : public QObject
{
    Q_OBJECT
public:
    PowerJsonForwarder(I_PowerData& powerData,
                       I_MessageForwarder& messageForwarder);
    virtual ~PowerJsonForwarder() {}

public slots:
    void forwardPowerData(const QJsonObject& baseJson);

private:
    I_PowerData& powerData_;
    I_MessageForwarder& messageForwarder_;
};
