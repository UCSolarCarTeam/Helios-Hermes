#ifndef B3DATA_H
#define B3DATA_H

#include <QObject>

class B3Data : public QObject {
    Q_OBJECT
public:
    B3Data();
    virtual ~B3Data();

    bool rightSignalIn() const;
    bool leftSignalIn() const;
    bool hazardLights() const;
    bool headlightsSwitch() const;
    bool forwardSwitch() const;
    bool hornSwitch() const;
    bool forward() const;
    bool neutral() const;
    bool reverse() const;
    bool brakeSwitch() const;
    bool handBrakeSwitch() const;
    bool motorReset() const;
    bool raceMode() const;
    bool lap() const;
    bool zoomZoom() const;
    unsigned short acceleration() const;
    unsigned short regenBraking() const;
    bool rightSignalOut() const;
    bool leftSignalOut() const;
    bool daytimeRunningLightSignal() const;
    bool headlightSignal() const;
    bool brakeLightSignal() const;
    bool hornSignal() const;

    void setLightInputs(const unsigned char& val);
    void setDriverInputs(const unsigned char& val);
    void setAcceleration(const unsigned short& val);
    void setRegenBraking(const unsigned short& val);
    void setLightsOutputs(const unsigned char& val);

private:
    bool rightSignalIn_ = 0;
    bool leftSignalIn_ = 0;
    bool hazardLights_ = 0;
    bool headlightsSwitch_ = 0;
    bool forwardSwitch_ = 0;
    bool hornSwitch_ = 0;
    bool forward_ = 0;

    bool neutral_ = 0;
    bool reverse_ = 0;
    bool brakeSwitch_ = 0;
    bool handBrakeSwitch_ = 0;
    bool motorReset_ = 0;
    bool raceMode_ = 0;
    bool lap_ = 0;
    bool zoomZoom_ = 0;

    unsigned short acceleration_ = 0;
    unsigned short regenBraking_ = 0;

    bool rightSignalOut_ = 0;
    bool leftSignalOut_ = 0;
    bool daytimeRunningLightSignal_ = 0;
    bool headlightSignal_ = 0;
    bool brakeLightSignal_ = 0;
    bool hornSignal_ = 0;
};

#endif // B3DATA_H
