#ifndef MPPTDATA_H
#define MPPTDATA_H

#include <QScopedArrayPointer>

#include "MpptUnit.h"

class MpptData : public QObject {
    Q_OBJECT
public:
    MpptData(QList<MpptUnit*> mpptUnits);
    unsigned char getNumberOfUnits() const;
    MpptUnit& getMpptUnit(const unsigned char& index) const;

private:
    QList<MpptUnit*> mpptUnits_;
};

#endif // MPPTDATA_H
