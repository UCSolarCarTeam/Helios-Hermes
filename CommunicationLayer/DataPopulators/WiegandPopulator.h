#pragma once

#include <QObject>
#include <QTimer>
#include "../../CommunicationLayer/PacketChecksumChecker/I_PacketChecksumChecker.h"
#include "../../DataLayer/WiegandData/I_WiegandData.h"

class WiegandPopulator : public QObject
{
    Q_OBJECT
public:
    WiegandPopulator(I_PacketChecksumChecker& checksumChecker, I_WiegandData& wiegandData);

public slots:
    void handleNewData();  // Called when new Wiegand data is available
    void timerExpired();   // Optional: Handle cases where data may need refreshing

private:
    I_PacketChecksumChecker& checksumChecker_;
    I_WiegandData& wiegandData_;
    QTimer* timer_;
};
