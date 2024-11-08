#ifndef B3POPULATOR_H
#define B3POPULATOR_H

#include <QObject>
#include "../../CommunicationLayer/PacketDecoder/I_PacketDecoder.h"
#include "../../DataLayer/B3Data/B3Data.h"

class B3Populator : public QObject {
    Q_OBJECT
public:
    B3Populator(I_PacketDecoder& packetDecoder, B3Data& data);

public slots:
    void populateData(const B3Message);

private:
    I_PacketDecoder& packetDecoder_;
    B3Data& data_;
};

#endif // B3POPULATOR_H
