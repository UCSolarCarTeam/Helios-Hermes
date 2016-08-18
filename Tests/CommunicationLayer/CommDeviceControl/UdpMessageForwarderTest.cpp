#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include <QScopedPointer>
#include <SimpleAmqpClient/SimpleAmqpClient.h>

#include "CommunicationLayer/CommDeviceControl/UdpMessageForwarder.h"
#include "InfrastructureLayer/Settings/Settings.h"

using namespace AmqpClient;

class UdpMessageForwarderTest : public ::testing::Test
{
protected:

  QScopedPointer<Settings> settings_;

  // TODO complete testing of UdpMessageForwarder

  virtual void SetUp() {
    // TODO Setup settings
    // TODO mock settings
    const QString TEST_FILE_PATH = "forwarderconfig.ini";
    settings_.reset(new Settings(TEST_FILE_PATH));

    // Create the channel
    Channel::ptr_t channel = Channel::Create();


  }

private:

  /**
  * Validates whether the expected equals the observed results
  */
  void testResponse(QString&, QString&);

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
