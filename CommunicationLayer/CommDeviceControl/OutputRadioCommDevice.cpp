#include <QDebug>
#include <QTimer>

#include "OutputRadioCommDevice.h"
#include "InfrastructureLayer/Settings/I_Settings.h"

OutputRadioCommDevice::OutputRadioCommDevice(I_CommDevice& inputSerialPort, QSerialPort& outputSerialPort, I_Settings& settings)
    : outputSerialPort_(outputSerialPort)
    , inputSerialPort_(inputSerialPort)
{
    setSerialParameters(settings.outputSerialPortName(), settings.outputBaudrate());
    // This makes sure that it is connected after everything is created.
    // Otherwise the error messages won't be sent to the GUI
    QTimer::singleShot(0, this, SLOT(connectToDataSource()));
    connect(&inputSerialPort_, SIGNAL(dataRecieved(QByteArray)), this, SLOT(handleSerialDataOutgoing(QByteArray)));
}

OutputRadioCommDevice::~OutputRadioCommDevice()
{
}

void OutputRadioCommDevice::setSerialParameters(QString serialPortName, int baudRate)
{
    outputSerialPort_.setPortName(serialPortName);
    outputSerialPort_.setBaudRate(baudRate);
    outputSerialPort_.setParity(QSerialPort::NoParity);
    outputSerialPort_.setStopBits(QSerialPort::OneStop);
    outputSerialPort_.setDataBits(QSerialPort::Data8);
}

bool OutputRadioCommDevice::connectToDataSource()
{
    if (outputSerialPort_.open(QIODevice::ReadWrite))
    {
        connect(&outputSerialPort_, SIGNAL(readyRead()),
                this, SLOT(handleSerialDataIncoming()), Qt::UniqueConnection);
        emit connectionSucceeded();
        return true;
    }
    else
    {
        qWarning() << outputSerialPort_.errorString();
        emit connectionFailed(outputSerialPort_.errorString());
        return false;
    }
}

void OutputRadioCommDevice::handleSerialDataOutgoing(QByteArray input)
{
     qDebug() << input;
}
