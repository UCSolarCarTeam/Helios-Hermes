#include "DataContainer.h"

#include "KeyMotorData/KeyMotorData.h"

DataContainer::DataContainer(const I_Settings& settings) : keyMotorData_(new KeyMotorData()) {}

DataContainer::~DataContainer() {}

KeyMotorData& DataContainer::keyMotorData(){
    return *keyMotorData_;
}
