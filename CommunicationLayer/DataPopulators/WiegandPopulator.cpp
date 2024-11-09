#include "WiegandPopulator.h"
#include "../../DataLayer/WiegandData/WiegandData.h"
#include "../Wiegand/Wiegand26.h"
#include <QDebug>

WiegandPopulator::WiegandPopulator(WiegandData& wiegandData, I_PacketChecksumChecker& checksumChecker)
    : wiegandData_(wiegandData), checksumChecker_(checksumChecker) {}

void WiegandPopulator::handleNewData() {
    connect(&wiegandReader_, &Wiegand26::dataReceived, this, [this](unsigned long data) {
        QByteArray wiegandPacket = QByteArray::number(data, 16);  // Convert to hex

        wiegandData_.setData(wiegandPacket);
    });

    wiegandReader_.start();

}

void WiegandPopulator::timerExpired() {
    // qDebug() << "Timer expired, refreshing data.";
    wiegandData_.clearData();
}
