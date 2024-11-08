#include "WiegandPopulator.h"
#include <QDebug>

WiegandPopulator::WiegandPopulator(I_PacketChecksumChecker& checksumChecker, WiegandData& wiegandData)
    : checksumChecker_(checksumChecker), wiegandData_(wiegandData), timer_(new QTimer(this)) {
    connect(timer_, &QTimer::timeout, this, &WiegandPopulator::timerExpired);
    timer_->start(3000);  // Adjust interval as needed
}

void WiegandPopulator::handleNewData() {
    QByteArray wiegandPacket = wiegandData_.getData();

    qDebug() << "Valid Wiegand data with ID:" << wiegandData_.getWiegandId();


    timer_->start();  // Reset the timer
}

void WiegandPopulator::timerExpired() {
    qDebug() << "Wiegand data expired";
}
