#ifndef MBMSPOPULATOR_H
#define MBMSPOPULATOR_H

#include <QObject>
#include "../../CommunicationLayer/PacketDecoder/I_PacketDecoder.h"
#include "../../DataLayer/MbmsData/MbmsData.h"

class MbmsPopulator : public QObject {
    Q_OBJECT
public:
    MbmsPopulator(I_PacketDecoder& packetDecoder, MbmsData& data);

public slots:
    void populateData(const MbmsMessage);

private:
    I_PacketDecoder& packetDecoder_;
    MbmsData& data_;
};

#endif // MBMSPOPULATOR_H
