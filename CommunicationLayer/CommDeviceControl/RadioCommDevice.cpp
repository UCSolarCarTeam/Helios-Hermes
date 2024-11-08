#include <QDebug>
#include <QTimer>

#include "RadioCommDevice.h"
#include "../../InfrastructureLayer/Settings/I_Settings.h"

RadioCommDevice::RadioCommDevice(QSerialPort& serialPort, I_Settings& settings)
    : serialPort_(serialPort)
{
    qDebug() << "STRTING";
    setSerialParameters(settings.serialPortName(), settings.baudrate());
    // This makes sure that it is connected after everything is created.
    // Otherwise the error messages won't be sent to the GUI
    QTimer::singleShot(0, this, SLOT(connectToDataSource()));
}

RadioCommDevice::~RadioCommDevice()
{
}

void RadioCommDevice::setSerialParameters(QString serialPortName, int baudRate)
{
    serialPort_.setPortName("/dev/pts/2");
    serialPort_.setBaudRate(QSerialPort::Baud115200);
    serialPort_.setParity(QSerialPort::NoParity);
    serialPort_.setStopBits(QSerialPort::OneStop);
    serialPort_.setDataBits(QSerialPort::Data8);
}

bool RadioCommDevice::connectToDataSource()
{
    if (serialPort_.open(QIODevice::ReadWrite))
    {
        connect(&serialPort_, SIGNAL(readyRead()),
                this, SLOT(handleSerialDataIncoming()), Qt::UniqueConnection);
        return true;
    }
    else
    {
        // Use qWarning to redirect these to stderr
        qDebug() << serialPort_.error();
        qDebug() << serialPort_.errorString();
        return false;
    }
}

void RadioCommDevice::handleSerialDataIncoming()
{
    qDebug() << "Serial port received data";
    QByteArray incomingData = serialPort_.readAll();
    qDebug() << incomingData;
    if (incomingData.isEmpty())
    {
        // Use qWarning to redirect these to stderr
        qDebug() << "Incoming data empty";
        return;
    }

    emit dataReceived(incomingData);
}
