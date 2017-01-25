#pragma once

#include <QObject>

class QJsonObject;
class I_FaultsData;
class I_MessageForwarder;

class FaultsJsonForwarder : public QObject
{
    Q_OBJECT
public:
    FaultsJsonForwarder(/*I_FaultsData& faultsData,*/
        I_MessageForwarder& messageForwarder);
    virtual ~FaultsJsonForwarder() {}

public slots:
    void forwardFaultsData(const QJsonObject& baseJson);

private:
//    I_FaultsData& faultsData_;
    I_MessageForwarder& messageForwarder_;
};
