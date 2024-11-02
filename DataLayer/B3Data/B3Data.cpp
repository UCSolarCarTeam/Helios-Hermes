#include "B3Data.h"

namespace {
    const unsigned char RIGHT_SIGNAL_OFFSET = 0x01;
    const unsigned char LEFT_SIGNAL_OFFSET = 0x02;

    const unsigned char HAZARD_LIGHTS_OFFSET = 0x04;
    const unsigned char HEADLIGHTS_SWITCH_OFFSET = 0x08;
    const unsigned char FORWARD_SWITCH_OFFSET = 0x10;
    const unsigned char HORN_SWITCH_OFFSET = 0x20;
    const unsigned char FORWARD_OFFSET = 0x40;

    const unsigned char NEUTRAL_OFFSET = 0x01;
    const unsigned char REVERSE_OFFSET = 0x02;
    const unsigned char BRAKE_SWITCH_OFFSET = 0x04;
    const unsigned char HANDBRAKE_SWITCH_OFFSET = 0x08;
    const unsigned char MOTOR_RESET_OFFSET = 0x10;
    const unsigned char RACE_MODE_OFFSET = 0x20;
    const unsigned char LAP_OFFSET = 0x40;
    const unsigned char ZOOM_ZOOM_OFFSET = 0x80;

    const unsigned char DAYTIME_RUNNING_LIGHT_SIGNAL_OFFSET = 0x04;
    const unsigned char HEADLIGHT_SIGNAL_OFFSET = 0x08;
    const unsigned char BRAKE_LIGHT_SIGNAL_OFFSET = 0x10;
    const unsigned char HORN_SIGNAL_OFFSET = 0x20;
}

B3Data::B3Data() {}

B3Data::~B3Data() {}

bool B3Data::rightSignalIn() const
{
    return rightSignalIn_;
}

bool B3Data::leftSignalIn() const
{
    return leftSignalIn_;
}

bool B3Data::hazardLights() const
{
    return hazardLights_;
}

bool B3Data::headlightsSwitch() const
{
    return headlightsSwitch_;
}

bool B3Data::forwardSwitch() const
{
    return forwardSwitch_;
}

bool B3Data::hornSwitch() const
{
    return hornSwitch_;
}

bool B3Data::forward() const
{
    return forward_;
}

bool B3Data::neutral() const
{
    return neutral_;
}

bool B3Data::reverse() const
{
    return reverse_;
}

bool B3Data::brakeSwitch() const
{
    return brakeSwitch_;
}

bool B3Data::handBrakeSwitch() const
{
    return handBrakeSwitch_;
}

bool B3Data::motorReset() const
{
    return motorReset_;
}

bool B3Data::raceMode() const
{
    return raceMode_;
}

bool B3Data::lap() const
{
    return lap_;
}

bool B3Data::zoomZoom() const
{
    return zoomZoom_;
}

unsigned short B3Data::acceleration() const
{
    return acceleration_;
}

unsigned short B3Data::regenBraking() const
{
    return regenBraking_;
}

bool B3Data::rightSignalOut() const
{
    return rightSignalOut_;
}

bool B3Data::leftSignalOut() const
{
    return leftSignalOut_;
}

bool B3Data::daytimeRunningLightSignal() const
{
    return daytimeRunningLightSignal_;
}

bool B3Data::headlightSignal() const
{
    return headlightSignal_;
}

bool B3Data::brakeLightSignal() const
{
    return brakeLightSignal_;
}

bool B3Data::hornSignal() const
{
    return hornSignal_;
}

void B3Data::setAcceleration(const unsigned short& val){
    acceleration_ = val;
}

void B3Data::setRegenBraking(const unsigned short& val){
    regenBraking_ = val;
}

void B3Data::setLightInputs(const unsigned char& val){
    rightSignalIn_ = val & RIGHT_SIGNAL_OFFSET;
    leftSignalIn_ = val & LEFT_SIGNAL_OFFSET;
    hazardLights_ = val & HAZARD_LIGHTS_OFFSET;
    headlightsSwitch_ = val & HEADLIGHTS_SWITCH_OFFSET;
    forwardSwitch_ = val & FORWARD_SWITCH_OFFSET;
    hornSwitch_ = val & HORN_SWITCH_OFFSET;
    forward_ = val & FORWARD_OFFSET;
}

void B3Data::setDriverInputs(const unsigned char& val){
    neutral_ = val & NEUTRAL_OFFSET;
    reverse_ = val & REVERSE_OFFSET;
    brakeSwitch_ = val & BRAKE_SWITCH_OFFSET;
    motorReset_ = val & MOTOR_RESET_OFFSET;
    raceMode_ = val & RACE_MODE_OFFSET;
    lap_ = val & LAP_OFFSET;
    zoomZoom_ = val & ZOOM_ZOOM_OFFSET;
}

void B3Data::setLightsOutputs(const unsigned char& val){
    rightSignalOut_ = val & RIGHT_SIGNAL_OFFSET;
    leftSignalOut_ = val & LEFT_SIGNAL_OFFSET;
    daytimeRunningLightSignal_ = val & DAYTIME_RUNNING_LIGHT_SIGNAL_OFFSET;
    headlightSignal_ = val & HEADLIGHT_SIGNAL_OFFSET;
    brakeLightSignal_ = val & BRAKE_LIGHT_SIGNAL_OFFSET;
    hornSignal_ = val & HORN_SIGNAL_OFFSET;
}
