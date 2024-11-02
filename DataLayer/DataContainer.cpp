#include "DataContainer.h"

DataContainer::DataContainer(const I_Settings& settings)
    : keyMotorData_(new KeyMotorData()),
      proximitySensorsData_(new ProximitySensorsData()) {}

DataContainer::~DataContainer() {}

KeyMotorData& DataContainer::keyMotorData(){
    return *keyMotorData_;
}

ProximitySensorsData& DataContainer::proximitySensorsData(){
    return *proximitySensorsData_;
}
