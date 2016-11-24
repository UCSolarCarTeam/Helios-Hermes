#pragma once

#include <QString>

class MotorFaults
{
public:
   MotorFaults(unsigned char errorFlags, unsigned char limitFlags);

   // TODO implement this (look at file history, accidently deleted before implemented)
   bool operator==(const MotorFaults& other) const;
   QString toString() const;

private:
   unsigned char errorFlags_;
   unsigned char limitFlags_;
};
