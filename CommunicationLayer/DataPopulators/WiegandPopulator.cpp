#include "WiegandPopulator.h"
#include "../../DataLayer/WiegandData/WiegandData.h"
#include "../Wiegand/Wiegand26.h"  // Include Wiegand26 protocol header
#include <QDebug>

WiegandPopulator::WiegandPopulator(WiegandData& wiegandData, I_PacketChecksumChecker& checksumChecker)
    : wiegandData_(wiegandData), checksumChecker_(checksumChecker) {}

void WiegandPopulator::handleNewData() {
    connect(&wiegandReader_, &Wiegand26::dataReceived, this, [this](unsigned long data) {
        QByteArray wiegandPacket = QByteArray::number(data, 16);  // Convert to hex for simplicity

        wiegandData_.setData(wiegandPacket);
        qDebug() << "WiegandPopulator: Data populated successfully.";
    });

    wiegandReader_.start();  // Start the Wiegand reader thread

}

void WiegandPopulator::timerExpired() {
    qDebug() << "Timer expired, refreshing data.";
    // You could clear data or perform other maintenance tasks here
    wiegandData_.clearData();
}
