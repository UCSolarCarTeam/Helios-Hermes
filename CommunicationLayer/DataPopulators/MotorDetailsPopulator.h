#ifndef MOTORDETAILSPOPULATOR_H
#define MOTORDETAILSPOPULATOR_H

#include <QObject>
#include "../../CommunicationLayer/PacketDecoder/I_PacketDecoder.h"
#include "../../DataLayer/MotorDetailsData/MotorDetailsData.h"

class MotorDetailsPopulator : public QObject {
    Q_OBJECT
public:
    MotorDetailsPopulator(I_PacketDecoder& packetDecoder, MotorDetailsData& data);

public slots:
    void populateData(const MotorDetailsMessage);

private:
    I_PacketDecoder& packetDecoder_;
    MotorDetailsData& data_;
};

#endif // MOTORDETAILSPOPULATOR_H
