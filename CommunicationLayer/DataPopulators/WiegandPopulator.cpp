#include "WiegandPopulator.h"
#include <QDebug>

WiegandPopulator::WiegandPopulator(I_PacketChecksumChecker& checksumChecker, I_WiegandData& wiegandData)
    : checksumChecker_(checksumChecker)
    , wiegandData_(wiegandData)
    , timer_(new QTimer(this))
{
    connect(&checksumChecker_, SIGNAL(validDataReceived(QByteArray)), this, SLOT(handleNewData()));
    connect(timer_, SIGNAL(timeout()), this, SLOT(timerExpired()));
    timer_->start(3000);  // Adjust interval as needed
}

void WiegandPopulator::handleNewData()
{
    QByteArray wiegandPacket = wiegandData_.getData(); // Assuming getData() retrieves formatted data
    // Code to add the Wiegand data into the main JSON packet here
    qDebug() << "Wiegand data added to packet:" << wiegandPacket;

    timer_->start();  // Reset the timer
}

void WiegandPopulator::timerExpired()
{
    // Reset state or mark data as stale if needed
    qDebug() << "Wiegand data expired";
}
