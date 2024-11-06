#pragma once

#include "I_WiegandData.h"  // Interface file for WiegandData

class WiegandData : public I_WiegandData {
public:
    WiegandData();
    virtual ~WiegandData();

    bool getWiegandAlive() const;            // Getter for Wiegand active status
    void setWiegandAlive(const bool& alive); // Setter for Wiegand active status

    int getLastReceivedData() const;         // Example: Last data received from Wiegand reader
    void setLastReceivedData(int data);      // Example setter for last received data

signals:
    void wiegandAliveReceived(bool alive);   // Signal for when Wiegand status is updated
    void newDataReceived(int data);          // Signal for new data received

private:
    bool wiegandAlive_;       // Status indicator
    int lastReceivedData_;    // Example data storage
};
