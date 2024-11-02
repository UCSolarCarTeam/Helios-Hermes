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
    bool rightSignalIn_;
    bool leftSignalIn_;
    bool hazardLights_;
    bool headlightsSwitch_;
    bool forwardSwitch_;
    bool hornSwitch_;
    bool forward_;

    bool neutral_;
    bool reverse_;
    bool brakeSwitch_;
    bool handBrakeSwitch_;
    bool motorReset_;
    bool raceMode_;
    bool lap_;
    bool zoomZoom_;

    unsigned short acceleration_;
    unsigned short regenBraking_;

    bool rightSignalOut_;
    bool leftSignalOut_;
    bool daytimeRunningLightSignal_;
    bool headlightSignal_;
    bool brakeLightSignal_;
    bool hornSignal_;
};

#endif // B3DATA_H
