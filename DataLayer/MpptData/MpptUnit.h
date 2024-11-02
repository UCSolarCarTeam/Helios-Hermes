#ifndef MPPTUNIT_H
#define MPPTUNIT_H

#include <QObject>
class MpptUnit : public QObject
{
    Q_OBJECT
public:
    MpptUnit();
    virtual ~MpptUnit();

    unsigned char mpptStatus() const;
    void setMpptStatus(const unsigned char newMpptStatus);
    float arrayVoltage() const;
    void setArrayVoltage(const unsigned short newArrayVoltage);
    float arrayCurrent() const;
    void setArrayCurrent(const unsigned short newArrayCurrent);
    float batteryVoltage() const;
    void setBatteryVoltage(const unsigned short newBatteryVoltage);
    float temperature() const;
    void setTemperature(const unsigned short newTemperature);

private:
    unsigned char mpptStatus_ = 0;
    float arrayVoltage_ = 0;
    float arrayCurrent_ = 0;
    float batteryVoltage_ = 0;
    float temperature_ = 0;
};

#endif // MPPTUNIT_H
