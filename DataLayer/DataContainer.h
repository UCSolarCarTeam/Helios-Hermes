#ifndef DATACONTAINER_H
#define DATACONTAINER_H

#include <QScopedPointer>

#include "KeyMotorData/KeyMotorData.h"
#include "ProximitySensorsData/ProximitySensorsData.h"
#include "B3Data/B3Data.h"

class I_Settings;

class DataContainer {
public:
    DataContainer(const I_Settings& settings);
    ~DataContainer();

    KeyMotorData& keyMotorData();
    ProximitySensorsData& proximitySensorsData();
    B3Data& b3Data();

private:
    QScopedPointer<KeyMotorData> keyMotorData_;
    QScopedPointer<ProximitySensorsData> proximitySensorsData_;
    QScopedPointer<B3Data> b3Data_;
};

#endif // DATACONTAINER_H
