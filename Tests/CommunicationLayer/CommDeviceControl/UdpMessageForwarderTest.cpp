#include <gtest/gtest.h>
#include <gmock/gmock.h>



#include "CommunicationLayer/CommDeviceControl/UdpMessageForwarder.h"

using namespace AmqpClient;

class UdpMessageForwarderTest : public ::testing::Test
{
protected:

  // TODO complete testing of UdpMessageForwarder

  virtual void SetUp() {
    // TODO Must retrieve values from settings
    // Create the channel
    //Channel::ptr_t = Channel::Create();
  }

};


/**
 * Send a single message via UdpMessageForwarder and verify its success
 */
TEST_F(UdpMessageForwarderTest, testSendingMessage) {
  // Send via UdpMessageForwarder

  // Receive message from local server

  // Verify Success
    EXPECT_EQ(1, 0);
}

/**
 * Send a series of messages that make up a JSON string and verify its success
 */
TEST_F(UdpMessageForwarderTest, testSendingJSON) {
  // Send via UdpMessageForwarder

  // Receive message from local server

  // Verify Success
    EXPECT_EQ(1, 0);
}
