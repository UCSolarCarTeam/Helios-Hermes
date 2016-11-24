#include "MotorFaults.h"



MotorFaults::MotorFaults(unsigned char errorFlags, unsigned char limitFlags)
: errorFlags_(errorFlags)
, limitFlags_(limitFlags)
{
}

// TODO check this
QString MotorFaults::toString() const
{
   return "0x" + QString::number(errorFlags_, 16) + " 0x" + QString::number(limitFlags_, 16);
}
