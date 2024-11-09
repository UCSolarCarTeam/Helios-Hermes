#include "WiegandPopulator.h"
#include "../../DataLayer/WiegandData/WiegandData.h"
#include "../Wiegand/Wiegand26.h"
#include <QDebug>

WiegandPopulator::WiegandPopulator(WiegandData& wiegandData, I_PacketChecksumChecker& checksumChecker)
    : wiegandData_(wiegandData), checksumChecker_(checksumChecker), timer_(new QTimer(this)) {

    connect(timer_, &QTimer::timeout, this, &WiegandPopulator::timerExpired);
    timer_->start(1000); // Timer for refreshing or clearing data every second

    connect(&wiegandReader_, &Wiegand26::onData, this, &WiegandPopulator::handleNewData);
}

void WiegandPopulator::handleNewData(unsigned long data) {
    QByteArray wiegandPacket = QByteArray::number(data);
    qDebug() << "Received Wiegand Data: " << wiegandPacket;

    // Set the received data into WiegandData
    wiegandData_.setData(wiegandPacket);
}


void WiegandPopulator::timerExpired() {
    qDebug() << "Timer expired, clearing Wiegand data.";
    wiegandData_.clearData();
}
