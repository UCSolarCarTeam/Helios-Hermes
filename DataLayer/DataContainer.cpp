#include "DataContainer.h"

DataContainer::DataContainer(const I_Settings& settings)
    : keyMotorData_(new KeyMotorData()),
        b3Data_(new B3Data()),
        proximitySensorsData_(new ProximitySensorsData()) {}

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
