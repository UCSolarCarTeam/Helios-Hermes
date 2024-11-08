#ifndef MPPTPOPULATOR_H
#define MPPTPOPULATOR_H

#include <QObject>
#include "../../CommunicationLayer/PacketDecoder/I_PacketDecoder.h"
#include "../../DataLayer/MpptData/MpptData.h"

class MpptPopulator : public QObject {
    Q_OBJECT
public:
    MpptPopulator(I_PacketDecoder& packetDecoder, MpptData& data);

public slots:
    void populateData(const MpptMessage);

private:
    I_PacketDecoder& packetDecoder_;
    MpptData& data_;
};

#endif // MPPTPOPULATOR_H
