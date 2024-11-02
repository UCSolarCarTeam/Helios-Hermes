#include "DataContainer.h"

DataContainer::DataContainer(const I_Settings& settings)
    : keyMotorData_(new KeyMotorData()),
        b3Data_(new B3Data()),
        batteryFaultsData_(new BatteryFaultsData()),
        batteryData_(new BatteryData()),
        proximitySensorsData_(new ProximitySensorsData()),
        telemetryData_(new TelemetryData()) {}

DataContainer::~DataContainer() {}

KeyMotorData& DataContainer::keyMotorData(){
    return *keyMotorData_;
}

ProximitySensorsData& DataContainer::proximitySensorsData(){
    return *proximitySensorsData_;
}

B3Data& DataContainer::b3Data(){
    return *b3Data_;
}

TelemetryData& DataContainer::telemetryData(){
    return *telemetryData_;
}

BatteryData& DataContainer::batteryData(){
    return *batteryData_;
}

BatteryFaultsData& DataContainer::batteryFaultsData(){
    return *batteryFaultsData_;
}
