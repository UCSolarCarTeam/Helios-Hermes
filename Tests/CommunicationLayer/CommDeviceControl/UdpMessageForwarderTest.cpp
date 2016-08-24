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
    const QString EXPECTED_1 = "Message Test";
    const QString EXPECTED_2 = "Second Message Test";
    const QString EXPECTED_3 = "Sp3c1a1** Ch4r4c74r5__ 7357";
}

class UdpMessageForwarderTest : public ::testing::Test
{
protected:

    QScopedPointer<MockSettings> settings_;
    QScopedPointer<UdpMessageForwarder> forwarder;
    AmqpClient::Channel::ptr_t receiver;

    // TODO test that disconnecting the sender does not destroy messages in the queue

    /**
   * @brief SetUp will set up the receiver to verify messages are being sent, as well as mocking the settings to be used by the UdpMessageForwarder
   */
    virtual void SetUp()
    {
        settings_.reset(new MockSettings());
        receiver = Channel::Create(MOCK_IP.toStdString(), MOCK_PORT);
        receiver->DeclareQueue(MOCK_QUEUE.toStdString(), false, true, false, false);

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

    // Test Methods

    void sendMessage(const QString& message, bool resetForwarder);
    void receiveMessage(QString& actual, bool setupConsume);
    void setupReceiver();
    void resetReceiver();
};

void UdpMessageForwarderTest::sendMessage(const QString& message, bool resetForwarder) {
    if (resetForwarder)
        forwarder.reset(new UdpMessageForwarder(*settings_));
    QByteArray expectedBytes = QByteArray();
    expectedBytes.append(message);
    try {
        forwarder->forwardData(expectedBytes);
    } catch (quint16 err) {
        qDebug() << "Failed to forward data with exception: " << err;
    }
}

void UdpMessageForwarderTest::receiveMessage(QString& actual, bool setupConsume) {
    // Receive message from local server
    if (setupConsume)
        receiver->BasicConsume(MOCK_QUEUE.toStdString());
    try {
        actual = QString::fromStdString(receiver->BasicConsumeMessage()->Message()->Body());
    } catch (quint16 err) {
        qDebug() << "Failed to receive data with exception: " << err;
    }
}

void UdpMessageForwarderTest::setupReceiver() {
    receiver = Channel::Create(MOCK_IP.toStdString(), MOCK_PORT);
    receiver->DeclareQueue(MOCK_QUEUE.toStdString(), false, true, false, false);

    receiver->BindQueue(MOCK_QUEUE.toStdString(), MOCK_EXCHANGE.toStdString(), MOCK_ROUTING_KEY.toStdString());
}

void UdpMessageForwarderTest::resetReceiver() {
    receiver->PurgeQueue(MOCK_QUEUE.toStdString());
    receiver->DeleteQueue(MOCK_QUEUE.toStdString());
    receiver.reset();
}


/**
 * @brief Send a single message representing a JSON string via UdpMessageForwarder and verify its success
 */
TEST_F(UdpMessageForwarderTest, testSendingMessage) {

    sendMessage(EXPECTED_1, true);

    QString ACTUAL;
    receiveMessage(ACTUAL, true);

    EXPECT_EQ(EXPECTED_1.toStdString(), ACTUAL.toStdString());
}

/**
 * @brief Send a message before the receiver has setup
 */
TEST_F(UdpMessageForwarderTest, testSendingNoReceiver) {

    resetReceiver();

    sendMessage(EXPECTED_1, true);

    setupReceiver();

    QString ACTUAL;
    receiveMessage(ACTUAL, true);

    EXPECT_EQ(EXPECTED_1.toStdString(), ACTUAL.toStdString());
}

/**
 * @brief Disconnect the receiver during delivery and ensure messages still arrive
 */
TEST_F(UdpMessageForwarderTest, testSendingReceiverDC) {
    sendMessage(EXPECTED_1, true);

    QString ACTUAL;
    receiveMessage(ACTUAL, true);

    EXPECT_EQ(EXPECTED_1.toStdString(), ACTUAL.toStdString());

    receiver.reset();

    sendMessage(EXPECTED_2, false);

    setupReceiver();

    receiveMessage(ACTUAL, true);

    EXPECT_EQ(EXPECTED_2.toStdString(), ACTUAL.toStdString());
}

/**
 * @brief Disconnect the receiver during delivery and ensure messages still arrive
 */
TEST_F(UdpMessageForwarderTest, testSendingSpecialChars) {
    sendMessage(EXPECTED_3, true);

    QString ACTUAL;
    receiveMessage(ACTUAL, true);

    EXPECT_EQ(EXPECTED_3.toStdString(), ACTUAL.toStdString());
}
