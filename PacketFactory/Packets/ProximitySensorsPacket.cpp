#include "ProximitySensorsPacket.h"
#include "../../Config/JsonDefinitions.h"

namespace {
    const int PROXIMITY_SENSOR_1_OFFSET = 1;
    const int PROXIMITY_SENSOR_2_OFFSET = 3;
    const int PROXIMITY_SENSOR_3_OFFSET = 5;
    const int PROXIMITY_SENSOR_4_OFFSET = 7;
}

ProximitySensorsPacket::ProximitySensorsPacket(){
    proximitySensor1_ = 0;
    proximitySensor2_ = 0;
    proximitySensor3_ = 0;
    proximitySensor4_ = 0;
}

void ProximitySensorsPacket::populatePacket(const QByteArray& data) {
    proximitySensor1_ = getValue<unsigned short>(data, PROXIMITY_SENSOR_1_OFFSET);
    proximitySensor2_ = getValue<unsigned short>(data, PROXIMITY_SENSOR_2_OFFSET);
    proximitySensor3_ = getValue<unsigned short>(data, PROXIMITY_SENSOR_3_OFFSET);
    proximitySensor4_ = getValue<unsigned short>(data, PROXIMITY_SENSOR_4_OFFSET);
}

QJsonObject ProximitySensorsPacket::toJson() {
    QJsonObject json;
    
    json[JsonDefinitions::PROXIMITY_SENSOR_1] = proximitySensor1_;
    json[JsonDefinitions::PROXIMITY_SENSOR_2] = proximitySensor2_;
    json[JsonDefinitions::PROXIMITY_SENSOR_3] = proximitySensor3_;
    json[JsonDefinitions::PROXIMITY_SENSOR_4] = proximitySensor4_;

    return json;
}
