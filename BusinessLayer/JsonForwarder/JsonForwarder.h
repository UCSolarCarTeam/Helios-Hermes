#ifndef JSONFORWARDER_H
#define JSONFORWARDER_H

#include <QObject>
#include <QTimer>

#include "../../DataLayer/KeyMotorData/KeyMotorData.h"
#include "../JsonMessageBuilder/JsonMessageBuilder.h"

class I_MessageForwarder;
class I_Settings;

class JsonForwarder : public QObject{
    Q_OBJECT
public:
    JsonForwarder(JsonMessageBuilder& builder, KeyMotorData& keyMotorData, I_MessageForwarder& forwarder, I_Settings& settings);
    virtual ~JsonForwarder();

    void startForwardingData();
    void forwardData(QDateTime& currentTime);

private slots:
    void handleTimeout();

private:
    JsonMessageBuilder& builder_;
    KeyMotorData& keyMotorData_;
    I_MessageForwarder& forwarder_;
    QScopedPointer<QTimer> readTimer_;
    int forwardPeriod_;
    const QString packetTitle_;
};

#endif // JSONFORWARDER_H
