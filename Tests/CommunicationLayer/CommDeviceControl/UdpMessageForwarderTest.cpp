#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include <QScopedPointer>
#include <QDebug>

#include <SimpleAmqpClient/SimpleAmqpClient.h>

#include "CommunicationLayer/CommDeviceControl/UdpMessageForwarder.h"
#include "InfrastructureLayer/Settings/MockSettings.h"

using namespace AmqpClient;

using ::testing::Return;

#define MOCK_IP "localhost"
#define MOCK_PORT 5672
#define MOCK_QUEUE "test-queue"
#define MOCK_EXCHANGE "amq.direct"
#define MOCK_ROUTING_KEY "routing-key"

class UdpMessageForwarderTest : public ::testing::Test
{
protected:

    QScopedPointer<MockSettings> settings_;

    // TODO complete testing of UdpMessageForwarder
    // TODO mock settings for using UdpMessageForwarder
    // TODO Setup queue to receive data sent by UdpMessageForwarder

    /**
   * @brief SetUp will set up the receiver to verify messages are being sent, as well as mocking the settings to be used by the UdpMessageForwarder
   */
    virtual void SetUp() {


        EXPECT_CALL(*settings_, queueName())
                .WillRepeatedly(Return(MOCK_IP));
        EXPECT_CALL(*settings_, queueName())
                .WillRepeatedly(Return(MOCK_QUEUE));
        EXPECT_CALL(*settings_, udpPort())
                .WillRepeatedly(Return(MOCK_PORT));
        EXPECT_CALL(*settings_, routingKey())
                .WillRepeatedly(Return(MOCK_ROUTING_KEY));



        // Create the channel
        Channel::ptr_t channel = Channel::Create(MOCK_IP, MOCK_PORT);
        channel->DeclareQueue(MOCK_QUEUE, false, true, false, false);
        // TODO determine what these should be for the purposes of HERMES

        // Bind the channel
        channel->BindQueue(MOCK_QUEUE, MOCK_EXCHANGE, MOCK_ROUTING_KEY);
    }
};


/**
 * Send a single message representing a JSON string via UdpMessageForwarder and verify its success
 */
TEST_F(UdpMessageForwarderTest, testSendingMessage) {
    // Send via UdpMessageForwarder


    // Receive message from local server

    // Verify Success
    EXPECT_EQ(1, 0);
}

/**
 * Send a series of messages that make up a JSON string via UdpMessageForwarder and verify its success
 */
TEST_F(UdpMessageForwarderTest, testSendingJSON) {
    // Send via UdpMessageForwarder

    // Receive message from local server

    // Verify Success
    EXPECT_EQ(1, 0);
}
