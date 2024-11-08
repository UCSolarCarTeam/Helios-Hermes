#ifndef MBMSDATA_H
#define MBMSDATA_H

#include <QObject>

class MbmsData : public QObject {
    Q_OBJECT
public:
    MbmsData();
    virtual ~MbmsData();


    bool commonContactorState() const;
    bool motorContactorState() const;
    bool arrayContactorState() const;
    bool lvContactorState() const;
    bool chargeContactorState() const;
    bool commonContactorError() const;
    bool motorContactorError() const;
    bool arrayContactorError() const;
    bool lvContactorError() const;
    bool chargeContactorError() const;
    bool strobeBmsLight() const;
    bool allowCharge() const;
    bool highVoltageEnableState() const;
    bool allowDischarge() const;
    bool orionCanReceivedRecently() const;
    bool dischargeShouldTrip() const;
    bool chargeShouldTrip() const;
    bool highCellVoltageTrip() const;
    bool lowCellVoltageTrip() const;
    bool highCommonCurrentTrip() const;
    bool motorHighTemperatureCurrentTrip() const;
    bool arrayHighTemperatureCurrentTrip() const;
    bool lvHighTemperatureCurrentTrip() const;
    bool chargeHighTemperatureCurrentTrip() const;
    bool protectionTrip() const;
    bool orionMessageTimeoutTrip() const;
    bool contactorDisconnectedUnexpectedlyTrip() const;
    unsigned short auxillaryBatteryVoltage() const;
    void setAuxillaryBatteryVoltage(unsigned short newAuxillaryBatteryVoltage);
    unsigned short motorVoltage() const;
    void setMotorVoltage(unsigned short newMotorVoltage);
    unsigned short arrayVoltage() const;
    void setArrayVoltage(unsigned short newArrayVoltage);
    unsigned short lvVoltage() const;
    void setLvVoltage(unsigned short newLvVoltage);
    unsigned short chargeVoltage() const;
    void setChargeVoltage(unsigned short newChargeVoltage);
    unsigned short commonCurrent() const;
    void setCommonCurrent(unsigned short newCommonCurrent);
    unsigned short motorCurrent() const;
    void setMotorCurrent(unsigned short newMotorCurrent);
    unsigned short arrayCurrent() const;
    void setArrayCurrent(unsigned short newArrayCurrent);
    unsigned short lvCurrent() const;
    void setLvCurrent(unsigned short newLvCurrent);
    unsigned short chargeCurrent() const;
    void setChargeCurrent(unsigned short newChargeCurrent);

    void setContactorStatus(const unsigned char& val);
    void setContactorErrors(const unsigned char& val);
    void setMiscellanousStatus(const unsigned char& val);
    void setTripStatuses(const unsigned short& val);

private:
    bool commonContactorState_ = 0;
    bool motorContactorState_ = 0;
    bool arrayContactorState_ = 0;
    bool lvContactorState_ = 0;
    bool chargeContactorState_ = 0;

    bool commonContactorError_ = 0;
    bool motorContactorError_ = 0;
    bool arrayContactorError_ = 0;
    bool lvContactorError_ = 0;
    bool chargeContactorError_ = 0;

    bool strobeBmsLight_ = 0;
    bool allowCharge_ = 0;
    bool highVoltageEnableState_ = 0;
    bool allowDischarge_ = 0;
    bool orionCanReceivedRecently_ = 0;
    bool dischargeShouldTrip_ = 0;
    bool chargeShouldTrip_ = 0;

    unsigned short auxillaryBatteryVoltage_ = 0;
    unsigned short motorVoltage_ = 0;
    unsigned short arrayVoltage_ = 0;
    unsigned short lvVoltage_ = 0;
    unsigned short chargeVoltage_ = 0;
    unsigned short commonCurrent_ = 0;
    unsigned short motorCurrent_ = 0;
    unsigned short arrayCurrent_ = 0;
    unsigned short lvCurrent_ = 0;
    unsigned short chargeCurrent_ = 0;

    bool highCellVoltageTrip_ = 0;
    bool lowCellVoltageTrip_ = 0;
    bool highCommonCurrentTrip_ = 0;
    bool motorHighTemperatureCurrentTrip_ = 0;
    bool arrayHighTemperatureCurrentTrip_ = 0;
    bool lvHighTemperatureCurrentTrip_ = 0;
    bool chargeHighTemperatureCurrentTrip_ = 0;
    bool protectionTrip_ = 0;
    bool orionMessageTimeoutTrip_ = 0;
    bool contactorDisconnectedUnexpectedlyTrip_ = 0;
};

#endif // MBMSDATA_H
