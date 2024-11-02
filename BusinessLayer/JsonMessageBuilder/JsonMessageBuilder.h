#ifndef JSONMESSAGEBUILDER_H
#define JSONMESSAGEBUILDER_H

#include <QObject>
#include <QJsonObject>

#include "../../DataLayer/KeyMotorData/KeyMotorData.h"
#include "../../DataLayer/ProximitySensorsData/ProximitySensorsData.h"

class I_PacketChecksumChecker;

class JsonMessageBuilder : public QObject {
    Q_OBJECT
public:
    JsonMessageBuilder();
    JsonMessageBuilder(const I_PacketChecksumChecker& checksumChecker);
    virtual ~JsonMessageBuilder() {}

    QJsonObject buildKeyMotorMessage(const KeyMotorData& data);
    QJsonObject buildProximitySensorsMessage(const ProximitySensorsData& data);
};

#endif // JSONMESSAGEBUILDER_H
