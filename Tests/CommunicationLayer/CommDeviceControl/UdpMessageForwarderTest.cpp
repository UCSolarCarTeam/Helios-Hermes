/**
 *  Schulich Delta Hermes
 *  Copyright (C) 2015 University of Calgary Solar Car Team
 *
 *  This file is part of Schulich Delta Hermes
 *
 *  Schulich Delta Hermes is free software:
 *  you can redistribute it and/or modify it under the terms
 *  of the GNU Affero General Public License as published by
 *  the Free Software Foundation, either version 3 of the
 *  License, or (at your option) any later version.
 *
 *  Schulich Delta Hermes is distributed
 *  in the hope that it will be useful, but WITHOUT ANY WARRANTY;
 *  without even the implied warranty of MERCHANTABILITY or
 *  FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Affero
 *  General Public License for more details.
 *
 *  You should have received a copy of the GNU Affero General
 *  Public License along with Schulich Delta Hermes.
 *  If not, see <http://www.gnu.org/licenses/>.
 *
 *  For further contact, email <software@calgarysolarcar.ca>
 */

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
// TODO fix exchange values
const QString MOCK_EXCHANGE = "testExchange";
const QString MOCK_ROUTING_KEY = "x73F34rS0dl";
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

    // TODO any new tests?
    // TODO add documentation for rabbitMQ libraries
    // TODO fix travis
    // TODO Fix indentation
    // TODO fix .ini files
    // TODO fix exhange usage in test
    // TODO Only the receiver should be generating the queue
    // TODO Come up with official exchange name

    /**
   * @brief SetUp will set up the receiver to verify messages are being sent, as well as mocking the settings to be used by the UdpMessageForwarder
   */
    virtual void SetUp()
    {
        settings_.reset(new MockSettings());

        ON_CALL(*settings_, ipAddress())
                .WillByDefault(Return(MOCK_IP));
        ON_CALL(*settings_, exchangeName())
                .WillByDefault(Return(MOCK_EXCHANGE));
        ON_CALL(*settings_, udpPort())
                .WillByDefault(Return(MOCK_PORT));
        ON_CALL(*settings_, routingKey())
                .WillByDefault(Return(MOCK_ROUTING_KEY));
    }

    virtual void TearDown() {
        // Delete exchange
        receiver->DeleteExchange(MOCK_EXCHANGE.toStdString());
        cleanReceiver();
    }

    // Test Methods

    void sendMessage(const QString& message);
    QString receiveMessage(bool setupConsume);
    /**
     * @brief setup the receiver for usage
     */
    void setupReceiver();
    /**
     * @brief reset the receiver (clear and delete queue)
     */
    void cleanReceiver();
};

void UdpMessageForwarderTest::sendMessage(const QString& message) {
    QByteArray expectedBytes = QByteArray();
    expectedBytes.append(message);
    forwarder->forwardData(expectedBytes);
}

QString UdpMessageForwarderTest::receiveMessage(bool setupConsume) {
    // Receive message from local server
    if (setupConsume) {
        receiver->BasicConsume(MOCK_QUEUE.toStdString());
    }
    return QString::fromStdString(receiver->BasicConsumeMessage()->Message()->Body());
}

void UdpMessageForwarderTest::setupReceiver() {
    receiver = Channel::Create(MOCK_IP.toStdString(), MOCK_PORT);
    // passive (false), durable (true), exclusive (false), auto_delete (false)
    receiver->DeclareQueue(MOCK_QUEUE.toStdString(), false, true, false, false);
    receiver->DeclareExchange(MOCK_EXCHANGE.toStdString(), AmqpClient::Channel::EXCHANGE_TYPE_FANOUT);
    receiver->BindQueue(MOCK_QUEUE.toStdString(), MOCK_EXCHANGE.toStdString(), MOCK_ROUTING_KEY.toStdString());
}

void UdpMessageForwarderTest::cleanReceiver() {
    receiver->PurgeQueue(MOCK_QUEUE.toStdString());
    receiver->DeleteQueue(MOCK_QUEUE.toStdString());
    receiver.reset();
}


/**
 * @brief Send a single message representing a JSON string via UdpMessageForwarder and verify its success
 */
TEST_F(UdpMessageForwarderTest, testSendingMessage) {
    setupReceiver();
    forwarder.reset(new UdpMessageForwarder(*settings_));
    sendMessage(EXPECTED_1);
    QString ACTUAL = receiveMessage(true);
    EXPECT_EQ(EXPECTED_1.toStdString(), ACTUAL.toStdString());
}

/**
 * @brief Send a message before the receiver has setup
 */
TEST_F(UdpMessageForwarderTest, testSendingNoReceiver) {
    setupReceiver();
    forwarder.reset(new UdpMessageForwarder(*settings_));
    sendMessage(EXPECTED_1);
    setupReceiver();
    QString ACTUAL = receiveMessage(true);
    EXPECT_EQ(EXPECTED_1.toStdString(), ACTUAL.toStdString());
}

/**
 * @brief Disconnect the receiver during delivery and ensure messages still arrive
 */
TEST_F(UdpMessageForwarderTest, testSendingReceiverDC) {
    setupReceiver();
    forwarder.reset(new UdpMessageForwarder(*settings_));
    sendMessage(EXPECTED_1);
    QString ACTUAL = receiveMessage(true);
    EXPECT_EQ(EXPECTED_1.toStdString(), ACTUAL.toStdString());
    receiver.reset();
    sendMessage(EXPECTED_2);
    setupReceiver();
    ACTUAL = receiveMessage(true);
    EXPECT_EQ(EXPECTED_2.toStdString(), ACTUAL.toStdString());
}

/**
 * @brief test sending message with special characters
 */
TEST_F(UdpMessageForwarderTest, testSendingSpecialChars) {
    setupReceiver();
    forwarder.reset(new UdpMessageForwarder(*settings_));
    sendMessage(EXPECTED_3);
    QString ACTUAL = receiveMessage(true);
    EXPECT_EQ(EXPECTED_3.toStdString(), ACTUAL.toStdString());
}
