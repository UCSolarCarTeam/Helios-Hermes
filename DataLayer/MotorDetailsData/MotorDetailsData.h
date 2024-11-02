#ifndef MOTORDETAILSDATA_H
#define MOTORDETAILSDATA_H

#include <QObject>
#include <QScopedArrayPointer>
#include "MotorDetailsUnit.h"

class MotorDetailsData : public QObject {
    Q_OBJECT
public:
    MotorDetailsData(QList<MotorDetailsUnit*> units);
    unsigned char getNumberOfUnits() const;
    MotorDetailsUnit& getMotorDetailsUnit(const unsigned char& index) const;

private:
    QList<MotorDetailsUnit*> motorDetailsUnits_;
};

#endif // MOTORDETAILSDATA_H
