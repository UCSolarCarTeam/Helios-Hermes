#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include <QScopedPointer>
#include <QDebug>
#include <QByteArray>
#include <string>

#include <SimpleAmqpClient/SimpleAmqpClient.h>

#include "CommunicationLayer/CommDeviceControl/UdpMessageForwarder.h"
#include "InfrastructureLayer/Settings/MockSettings.h"

using ::testing::Return;

namespace
{
    const QString MOCK_IP = QString("localhost");
    const quint16 MOCK_PORT = 5672;
    const QString MOCK_QUEUE = "test-queue";
    const QString MOCK_EXCHANGE = "amq.direct";
    const QString MOCK_ROUTING_KEY = "routing-key";
}

class UdpMessageForwarderTest : public ::testing::Test
{
protected:

    QScopedPointer<MockSettings> settings_;
    QScopedPointer<UdpMessageForwarder> forwarder;
    AmqpClient::Channel::ptr_t receiver;

    // TODO complete testing of UdpMessageForwarder
    // TODO mock settings for using UdpMessageForwarder
    // TODO Setup queue to receive data sent by UdpMessageForwarder
    // TODO test that sending when the queue has not been created yet still works
    // TODO test that upon deletion of the UdpMessageForwarder the destructor performs its duties
    // TODO test that disconnecting the sender does not destroy messages in the queue
    // TODO test to check if data is getting converted from string to bytes to string correctly

    /**
   * @brief SetUp will set up the receiver to verify messages are being sent, as well as mocking the settings to be used by the UdpMessageForwarder
   */
    virtual void SetUp()
    {
        settings_.reset(new MockSettings());
        receiver = Channel::Create(MOCK_IP.toStdString(), MOCK_PORT);
        receiver->DeclareQueue(MOCK_QUEUE.toStdString(), false, true, false, false);

        // TODO determine what these should be for the purposes of HERMES
        receiver->BindQueue(MOCK_QUEUE.toStdString(), MOCK_EXCHANGE.toStdString(), MOCK_ROUTING_KEY.toStdString());

        EXPECT_CALL(*settings_, ipAddress())
                .WillRepeatedly(Return(MOCK_IP));
        EXPECT_CALL(*settings_, queueName())
                .WillRepeatedly(Return(MOCK_QUEUE));
        EXPECT_CALL(*settings_, udpPort())
                .WillRepeatedly(Return(MOCK_PORT));
        EXPECT_CALL(*settings_, routingKey())
                .WillRepeatedly(Return(MOCK_ROUTING_KEY));
    }

    virtual void TearDown() {
        receiver->PurgeQueue(MOCK_QUEUE.toStdString());
        receiver->DeleteQueue(MOCK_QUEUE.toStdString());
        receiver.reset();
    }
};


/**
 * @brief Send a single message representing a JSON string via UdpMessageForwarder and verify its success
 */
TEST_F(UdpMessageForwarderTest, testSendingMessage) {
    // Send via UdpMessageForwarder
    QString expected = "Message Test";
    try {
        forwarder.reset(new UdpMessageForwarder(*settings_));
    } catch (quint16 err) {
        qDebug() << "Failed to reset forwarder with exception: " << err;
    }
    QByteArray expectedBytes = QByteArray();
    expectedBytes.append(expected);
    try {
        forwarder->forwardData(expectedBytes);
    } catch (quint16 err) {
        qDebug() << "Failed to forward data with exception: " << err;
    }

    // Receive message from local server
    QString actual;
    try {
        actual = QString::fromStdString(receiver->BasicConsume(MOCK_QUEUE.toStdString()));
    } catch (quint16 err) {
        qDebug() << "Failed to receive data with exception: " << err;
    }

    // Verify Success
    EXPECT_EQ(expected.toStdString(), actual.toStdString());
}

/**
 * @brief Send a series of messages that make up a JSON string via UdpMessageForwarder and verify its success
 */
TEST_F(UdpMessageForwarderTest, testSendingSeries) {
    // Send via UdpMessageForwarder

    // Receive message from local server

    // Verify Success
    EXPECT_EQ(1, 0);
}
