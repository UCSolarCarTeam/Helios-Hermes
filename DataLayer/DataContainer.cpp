#include "DataContainer.h"

#include "../InfrastructureLayer/Settings/I_Settings.h"

DataContainer::DataContainer(const I_Settings& settings)
    : keyMotorData_(new KeyMotorData()),
        b3Data_(new B3Data()),
        batteryFaultsData_(new BatteryFaultsData()),
        batteryData_(new BatteryData()),
        proximitySensorsData_(new ProximitySensorsData()),
        mbmsData_(new MbmsData()),
        telemetryData_(new TelemetryData()) {
    QList<MotorDetailsUnit*> motorDetailsUnits;
    QList<MpptUnit*> mpptUnits;

    for(int i = 0; i < settings.numberOfMotors(); ++i){
        motorDetailsUnits.append(new MotorDetailsUnit());
    }

    for(int i = 0; i < settings.numberOfMppts(); ++i){
        mpptUnits.append(new MpptUnit());
    }

    motorDetailsData_.reset(new MotorDetailsData(motorDetailsUnits));
    mpptData_.reset(new MpptData(mpptUnits));
}

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

MbmsData& DataContainer::mbmsData(){
    return *mbmsData_;
}

MpptData& DataContainer::mpptData(){
    return *mpptData_;
}

MotorDetailsData& DataContainer::motorDetailsData(){
    return *motorDetailsData_;
}
