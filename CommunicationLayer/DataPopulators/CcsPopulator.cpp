#include "CcsPopulator.h"
#include <QDebug>

CcsPopulator::CcsPopulator(I_PacketChecksumChecker& checksumChecker, I_CcsData& ccsData)
    : checksumChecker_(checksumChecker)
    , ccsData_(ccsData)
    , timer_(new QTimer())
{
    connect(&checksumChecker_, SIGNAL(validDataReceived(QByteArray)), this, SLOT(validData()));
    connect(timer_, SIGNAL(timeout()), this, SLOT(timerExpired()));
    timer_->start(3000);
}

void CcsPopulator::validData()
{
    timer_->start();
    ccsData_.setCcsAlive(true);
}

void CcsPopulator::timerExpired()
{
    ccsData_.setCcsAlive(false);
}

