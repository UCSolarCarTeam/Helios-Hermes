#include "MotorDetailsPopulator.h"

MotorDetailsPopulator::MotorDetailsPopulator(I_PacketDecoder& packetDecoder, MotorDetailsData& data)
    : packetDecoder_(packetDecoder), data_(data) {
    connect(&packetDecoder_, SIGNAL(packetDecoded(MotorDetailsMessage)), this, SLOT(populateData(MotorDetailsMessage)));
}

void MotorDetailsPopulator::populateData(const MotorDetailsMessage message){
    MotorDetailsUnit& unit = data_.getMotorDetailsUnit(message.motorId() - 2);
    unit.setControlValue(message.controlValue());
    unit.setControlBits(message.controlBits());
    unit.setCurrentMotorTorque(message.currentMotorTorque());
    unit.setCurrentRpmValue(message.currentRpmValue());
    unit.setMotorTemperature(message.motorTemperature());
    unit.setInverterPeakCurrent(message.inverterPeakCurrent());
    unit.setCurrentMotorPower(message.currentMotorPower());
    unit.setAbsoluteAngle(message.AbsoluteAngle());
    unit.setWarningCode1(message.warningCode1());
    unit.setWarningCode2(message.warningCode2());
    unit.setWarningCode3(message.warningCode3());
    unit.setWarningCode4(message.warningCode4());
    unit.setWarningCode5(message.warningCode5());
    unit.setErrorCode1(message.errorCode1());
    unit.setErrorCode2(message.errorCode2());
    unit.setErrorCode3(message.errorCode3());
    unit.setErrorCode4(message.errorCode4());
    unit.setErrorCode5(message.errorCode5());
}
