#include "CcsMessage.h"
#include "MessageDecodingHelpers.h"
#include "MessageDefines.h"

using namespace MessageDecodingHelpers;

namespace
{
    const int CCS_ALIVE_OFFSET = 1;
}

CcsMessage::CcsMessage(const QByteArray& messageData)
    : messageData_(messageData)
{
}


bool CcsMessage::ccsAlive() const
{
    return static_cast<bool>(messageData_.at(CCS_ALIVE_OFFSET));
}



