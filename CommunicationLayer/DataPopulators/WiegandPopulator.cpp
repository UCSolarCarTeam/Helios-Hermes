#include "WiegandPopulator.h"
#include "../../DataLayer/WiegandData/WiegandData.h"
#include "../Wiegand/Wiegand26.h"  // Include Wiegand26 protocol header
#include <QDebug>

WiegandPopulator::WiegandPopulator(WiegandData& wiegandData, I_PacketChecksumChecker& checksumChecker)
    : wiegandData_(wiegandData), checksumChecker_(checksumChecker) {}

void WiegandPopulator::handleNewData() {
    // Initialize Wiegand26 instance for reading
    Wiegand26 wiegandReader;

    // Read and parse data using Wiegand26 protocol
    QByteArray rawData = wiegandReader.readData();  // Assuming readData() returns raw 26-bit data

    if (rawData.isEmpty()) {
        qDebug() << "WiegandPopulator: No data read from Wiegand26.";
        return;
    }

    // Create a Wiegand packet
    QByteArray wiegandPacket = wiegandReader.parse(rawData);  // Parse the raw data into packet format

    // Validate the packet if the checksum checker has a valid method
    wiegandData_.setData(wiegandPacket);
    qDebug() << "WiegandPopulator: Data populated successfully.";

}
