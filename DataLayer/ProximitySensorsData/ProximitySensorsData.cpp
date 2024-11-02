#include "ProximitySensorsData.h"

ProximitySensorsData::ProximitySensorsData() {}

ProximitySensorsData::~ProximitySensorsData() {}


unsigned short ProximitySensorsData::getProximitySensor1() const {
    return proximitySensor1_;
}

unsigned short ProximitySensorsData::getProximitySensor2() const {
    return proximitySensor2_;
}

unsigned short ProximitySensorsData::getProximitySensor3() const {
    return proximitySensor3_;
}

unsigned short ProximitySensorsData::getProximitySensor4() const {
    return proximitySensor4_;
}


void ProximitySensorsData::setProximitySensor1(const unsigned short& val){
    proximitySensor1_ = val;
}

void ProximitySensorsData::setProximitySensor2(const unsigned short& val){
    proximitySensor2_ = val;
}

void ProximitySensorsData::setProximitySensor3(const unsigned short& val){
    proximitySensor3_ = val;
}

void ProximitySensorsData::setProximitySensor4(const unsigned short& val){
    proximitySensor4_ = val;
}
