#pragma once

#include <QObject>
#include <QTimer>
#include "CommunicationLayer/PacketChecksumChecker/I_PacketChecksumChecker.h"
#include "DataLayer/CcsData/I_CcsData.h"

class CcsPopulator : public QObject
{
    Q_OBJECT
public:
    CcsPopulator(I_PacketChecksumChecker& checksumChecker,
                 I_CcsData& ccsData  );
public slots:
    void validData();
    void timerExpired();

private:
    I_PacketChecksumChecker& checksumChecker_;
    I_CcsData& ccsData_;
    QTimer* timer_;


};
