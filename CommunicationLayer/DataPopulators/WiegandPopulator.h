#ifndef WIEGANDPOPULATOR_H
#define WIEGANDPOPULATOR_H

#include <QObject>
#include <QTimer>
#include "../../CommunicationLayer/PacketChecksumChecker/I_PacketChecksumChecker.h"
#include "../../DataLayer/WiegandData/WiegandData.h"
#include "../Wiegand/Wiegand26.h"

class WiegandPopulator : public QObject {
    Q_OBJECT
public:
    WiegandPopulator(WiegandData& wiegandData, I_PacketChecksumChecker& checksumChecker);

public slots:
    void handleNewData();  // Called when new Wiegand data is available
    void timerExpired();   // Handle cases where data may need refreshing

private:
    I_PacketChecksumChecker& checksumChecker_;
    WiegandData& wiegandData_;
    Wiegand26 wiegandReader_;
    QTimer* timer_;
};

#endif
