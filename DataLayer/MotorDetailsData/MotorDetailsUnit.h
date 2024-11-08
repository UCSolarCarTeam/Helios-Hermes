#ifndef MOTORDETAILSUNIT_H
#define MOTORDETAILSUNIT_H

#include <QObject>

class MotorDetailsUnit : public QObject {
    Q_OBJECT
public:
    MotorDetailsUnit();
    virtual ~MotorDetailsUnit();


    short controlValue() const;
    void setControlValue(short newControlValue);
    bool controlMode() const;
    bool motorMode() const;
    bool softwareEnable() const;
    bool debugMode() const;
    short currentMotorTorque() const;
    void setCurrentMotorTorque(short newCurrentMotorTorque);
    short currentRpmValue() const;
    void setCurrentRpmValue(short newCurrentRpmValue);
    char motorTemperature() const;
    void setMotorTemperature(char newMotorTemperature);
    short inverterPeakCurrent() const;
    void setInverterPeakCurrent(short newInverterPeakCurrent);
    short currentMotorPower() const;
    void setCurrentMotorPower(short newCurrentMotorPower);
    unsigned short AbsoluteAngle() const;
    void setAbsoluteAngle(unsigned short newAbsoluteAngle);
    bool motorAboutToStall() const;
    bool delayInReadingTempSensor() const;
    bool delayInReadingPosSensor() const;
    bool inverter1TempVeryHigh() const;
    bool inverter2TempVeryHigh() const;
    bool inverter3TempVeryHigh() const;
    bool inverter4TempVeryHigh() const;
    bool inverter5TempVeryHigh() const;
    bool inverter6TempVeryHigh() const;
    bool cpuTemperatureVeryHigh() const;
    bool hallTemperatureVeryHigh() const;
    bool dclinkTemperatureVeryHigh() const;
    bool delayInDclinkCommunication() const;
    bool inverter1OverCurrent() const;
    bool inverter2OverCurrent() const;
    bool inverter3OverCurrent() const;
    bool inverter4OverCurrent() const;
    bool inverter5OverCurrent() const;
    bool inverter6OverCurrent() const;
    bool dcOvervoltageWarning() const;
    bool dcUndervoltageWarning() const;
    bool canCommsTimeout() const;
    bool inverter1faultWarning() const;
    bool inverter2faultWarning() const;
    bool inverter3faultWarning() const;
    bool inverter4faultWarning() const;
    bool inverter5faultWarning() const;
    bool inverter6faultWarning() const;
    bool canSendWarning() const;
    bool lostFramesOnCanBusWarning() const;
    bool overspeedWarning() const;
    bool cpuOverload() const;
    bool torqueLimited() const;
    bool startAtHighRpm() const;
    bool initError() const;
    bool settingsNotFound() const;
    bool motorStalled() const;
    bool controllerDataReadingTimeout() const;
    bool invalidHallSensorSequence() const;
    bool invalidHallSector() const;
    bool errorReadingTempSensor() const;
    bool positionSensorReadingError() const;
    bool errorReadingEncoder() const;
    bool zeroPositionOffsetNotSet() const;
    bool hwEnableNotSet() const;
    bool inverter1TempTooHigh() const;
    bool inverter2TempTooHigh() const;
    bool inverter3TempTooHigh() const;
    bool inverter4TempTooHigh() const;
    bool inverter5TempTooHigh() const;
    bool inverter6TempTooHigh() const;
    bool cpuTemperatureTooHigh() const;
    bool hallTemperatureTooHigh() const;
    bool dclinkTemperatureTooHigh() const;
    bool errorInDclinkCommunication() const;
    bool inverter1Overcurrent() const;
    bool inverter2Overcurrent() const;
    bool inverter3Overcurrent() const;
    bool inverter4Overcurrent() const;
    bool inverter5Overcurrent() const;
    bool inverter6Overcurrent() const;
    bool dcOvervoltageError() const;
    bool dcUndervoltageError() const;
    bool doubleCanCommsTimeout() const;
    bool inverter1FaultError() const;
    bool inverter2FaultError() const;
    bool inverter3FaultError() const;
    bool inverter4FaultError() const;
    bool inverter5FaultError() const;
    bool inverter6FaultError() const;
    bool canSendError() const;
    bool lostFramesOnCanBusError() const;
    bool overspeedError() const;
    bool cpuOverloaded() const;
    bool canCommsTimeoutError() const;

    void setControlBits(const unsigned char& val);

    void setWarningCode1(const unsigned short& val);
    void setWarningCode2(const unsigned short& val);
    void setWarningCode3(const unsigned short& val);
    void setWarningCode4(const unsigned short& val);
    void setWarningCode5(const unsigned char& val);

    void setErrorCode1(const unsigned short& val);
    void setErrorCode2(const unsigned short& val);
    void setErrorCode3(const unsigned short& val);
    void setErrorCode4(const unsigned short& val);
    void setErrorCode5(const unsigned char& val);

private:
    short int controlValue_ = 0;
    
    bool controlMode_ = 0;
    bool motorMode_ = 0;
    bool softwareEnable_ = 0;
    bool debugMode_ = 0;

    short int currentMotorTorque_ = 0;
    short int currentRpmValue_ = 0;
    char motorTemperature_ = 0;
    short inverterPeakCurrent_ = 0;
    short currentMotorPower_ = 0;
    unsigned short AbsoluteAngle_ = 0;

    bool motorAboutToStall_ = 0;
    bool delayInReadingTempSensor_ = 0;
    bool delayInReadingPosSensor_ = 0;
    bool inverter1TempVeryHigh_ = 0;
    bool inverter2TempVeryHigh_ = 0;
    bool inverter3TempVeryHigh_ = 0;
    bool inverter4TempVeryHigh_ = 0;
    bool inverter5TempVeryHigh_ = 0;

    bool inverter6TempVeryHigh_ = 0;
    bool cpuTemperatureVeryHigh_ = 0;
    bool hallTemperatureVeryHigh_ = 0;
    bool dclinkTemperatureVeryHigh_ = 0;
    bool delayInDclinkCommunication_ = 0;
    bool inverter1OverCurrent_ = 0;
    bool inverter2OverCurrent_ = 0;
    bool inverter3OverCurrent_ = 0;

    bool inverter4OverCurrent_ = 0;
    bool inverter5OverCurrent_ = 0;
    bool inverter6OverCurrent_ = 0;
    bool dcOvervoltageWarning_ = 0;
    bool dcUndervoltageWarning_ = 0;
    bool canCommsTimeout_ = 0;
    bool inverter1faultWarning_ = 0;
    bool inverter2faultWarning_ = 0;

    bool inverter3faultWarning_ = 0;
    bool inverter4faultWarning_ = 0;
    bool inverter5faultWarning_ = 0;
    bool inverter6faultWarning_ = 0;
    bool canSendWarning_ = 0;
    bool lostFramesOnCanBusWarning_ = 0;
    bool overspeedWarning_ = 0;
    bool cpuOverload_ = 0;

    bool torqueLimited_ = 0;
    bool startAtHighRpm_ = 0;

    bool initError_ = 0;
    bool settingsNotFound_ = 0;
    bool motorStalled_ = 0;
    bool controllerDataReadingTimeout_ = 0;
    bool invalidHallSensorSequence_ = 0;
    bool invalidHallSector_ = 0;
    bool errorReadingTempSensor_ = 0;
    bool positionSensorReadingError_ = 0;

    bool errorReadingEncoder_ = 0;
    bool zeroPositionOffsetNotSet_ = 0;
    bool hwEnableNotSet_ = 0;
    bool inverter1TempTooHigh_ = 0;
    bool inverter2TempTooHigh_ = 0;
    bool inverter3TempTooHigh_ = 0;
    bool inverter4TempTooHigh_ = 0;
    bool inverter5TempTooHigh_ = 0;

    bool inverter6TempTooHigh_ = 0;
    bool cpuTemperatureTooHigh_ = 0;
    bool hallTemperatureTooHigh_ = 0;
    bool dclinkTemperatureTooHigh_ = 0;
    bool errorInDclinkCommunication_ = 0;
    bool inverter1Overcurrent_ = 0;
    bool inverter2Overcurrent_ = 0;
    bool inverter3Overcurrent_ = 0;

    bool inverter4Overcurrent_ = 0;
    bool inverter5Overcurrent_ = 0;
    bool inverter6Overcurrent_ = 0;
    bool dcOvervoltageError_ = 0;
    bool dcUndervoltageError_ = 0;
    bool doubleCanCommsTimeout_ = 0;
    bool canCommsTimeoutError_ = 0;
    bool inverter1FaultError_ = 0;
    bool inverter2FaultError_ = 0;
    bool inverter3FaultError_ = 0;
    bool inverter4FaultError_ = 0;
    bool inverter5FaultError_ = 0;
    bool inverter6FaultError_ = 0;
    bool canSendError_ = 0;
    bool lostFramesOnCanBusError_ = 0;
    bool overspeedError_ = 0;

    bool cpuOverloaded_ = 0;
};

#endif // MOTORDETAILSUNIT_H
