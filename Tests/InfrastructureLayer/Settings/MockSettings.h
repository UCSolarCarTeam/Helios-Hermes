#pragma once
#include <gmock/gmock.h>

#include "InfrastructureLayer/Settings/I_Settings.h"

class MockSettings : public I_Settings
{
public:
    MOCK_CONST_METHOD0(serialPortName, QString());
    MOCK_CONST_METHOD0(baudrate, int());
    MOCK_CONST_METHOD0(ipAddress, QString());
    MOCK_CONST_METHOD0(udpPort, quint16());
    MOCK_CONST_METHOD0(forwardPeriod, int());
    MOCK_CONST_METHOD0(packetTitle, QString());
    MOCK_CONST_METHOD0(exchangeName, QString());
};
