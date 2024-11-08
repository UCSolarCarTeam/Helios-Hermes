#ifndef KEYMOTORDATA_H
#define KEYMOTORDATA_H

#include <QObject>

class KeyMotorData : public QObject {
    Q_OBJECT
public:
    KeyMotorData();
    virtual ~KeyMotorData();

    unsigned short getMotorSetpoint() const;
    bool getControlMode() const;
    bool getMotorMode() const;
    bool getSoftwareEnable() const;
    bool getDebugMode() const;

    void setMotorSetpoint(const unsigned short& val);
    void setControlBits(const unsigned char& val);

private:
    unsigned short motorSetpoint_ = 0;
    bool controlMode_ = 0;
    bool motorMode_ = 0;
    bool softwareEnable_ = 0;
    bool debugMode_ = 0;
};

#endif // KEYMOTORDATA_H
