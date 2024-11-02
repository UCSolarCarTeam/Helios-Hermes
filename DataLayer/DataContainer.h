#ifndef DATACONTAINER_H
#define DATACONTAINER_H

#include <QScopedPointer>

#include "KeyMotorData/KeyMotorData.h"
#include "ProximitySensorsData/ProximitySensorsData.h"

class I_Settings;

class DataContainer {
public:
    DataContainer(const I_Settings& settings);
    ~DataContainer();

    KeyMotorData& keyMotorData();
    ProximitySensorsData& proximitySensorsData();

private:
    QScopedPointer<KeyMotorData> keyMotorData_;
    QScopedPointer<ProximitySensorsData> proximitySensorsData_;
};

#endif // DATACONTAINER_H
