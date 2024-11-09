#ifndef DATACONTAINER_H
#define DATACONTAINER_H

#include <QScopedPointer>

#include "KeyMotorData/KeyMotorData.h"
#include "ProximitySensorsData/ProximitySensorsData.h"
#include "B3Data/B3Data.h"
#include "TelemetryData/TelemetryData.h"
#include "BatteryData/BatteryData.h"
#include "BatteryFaultsData/BatteryFaultsData.h"
#include "MbmsData/MbmsData.h"
#include "MpptData/MpptData.h"
#include "MotorDetailsData/MotorDetailsData.h"
#include "WiegandData/WiegandData.h"

class I_Settings;

class DataContainer {
public:
    DataContainer(const I_Settings& settings);
    ~DataContainer();

    KeyMotorData& keyMotorData();
    ProximitySensorsData& proximitySensorsData();
    B3Data& b3Data();
    TelemetryData& telemetryData();
    BatteryData& batteryData();
    BatteryFaultsData& batteryFaultsData();
    MpptData& mpptData();
    MbmsData& mbmsData();
    WiegandData& wiegandData();
    MotorDetailsData& motorDetailsData();

private:
    QScopedPointer<KeyMotorData> keyMotorData_;
    QScopedPointer<ProximitySensorsData> proximitySensorsData_;
    QScopedPointer<B3Data> b3Data_;
    QScopedPointer<TelemetryData> telemetryData_;
    QScopedPointer<BatteryData> batteryData_;
    QScopedPointer<BatteryFaultsData> batteryFaultsData_;
    QScopedPointer<MbmsData> mbmsData_;
    QScopedPointer<WiegandData> wiegandData_;
    QScopedPointer<MpptData> mpptData_;
    QScopedPointer<MotorDetailsData> motorDetailsData_;
};

#endif // DATACONTAINER_H
