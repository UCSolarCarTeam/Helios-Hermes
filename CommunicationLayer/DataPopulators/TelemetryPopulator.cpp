#include "TelemetryPopulator.h"

TelemetryPopulator::TelemetryPopulator(I_PacketDecoder& packetDecoder, TelemetryData& data) 
    : packetDecoder_(packetDecoder), data_(data) {
    connect(&packetDecoder, SIGNAL(packetDecoded(TelemetryMessage)), this, SLOT(populateData(TelemetryMessage)));
}

void TelemetryPopulator::populateData(const TelemetryMessage message){
    data_.setGpsYear(message.gpsYear());
    data_.setGpsMonth(message.gpsMonth());
    data_.setGpsDay(message.gpsDay());
    data_.setGpsHour(message.gpsHour());
    data_.setGpsMinute(message.gpsMinute());
    data_.setGpsSecond(message.gpsSecond());
    data_.setGpsValidityFlags(message.gpsValidityFlags());
    data_.setGpsFixStatusFlags(message.gpsFixStatusFlags());
    data_.setGpsAdditionalFlags(message.gpsAdditionalFlags());
    data_.setGpsLongitude(message.gpsLongitude());
    data_.setGpsLatitude(message.gpsLatitude());
    data_.setMpuAccelerationX(message.mpuAccelerationX());
    data_.setMpuAccelerationY(message.mpuAccelerationY());
    data_.setMpuAccelerationZ(message.mpuAccelerationZ());
    data_.setMpuRotationX(message.mpuRotationX());
    data_.setMpuRotationY(message.mpuRotationY());
    data_.setMpuRotationZ(message.mpuRotationZ());
    data_.setMpuTemperature(message.mpuTemperature());
}
