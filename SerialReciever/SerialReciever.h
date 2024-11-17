#ifndef SERIALRECIEVER_H
#define SERIALRECIEVER_H

#include <QObject>
#include <QSerialPort>

class SerialReciever : public QObject {
    Q_OBJECT
public:
    SerialReciever();
    ~SerialReciever();

signals:
    void dataRecieved(const QByteArray& data);

private slots:
    void handleReadyRead();

private:
    QSerialPort *serialPort_;
};

#endif // SERIALRECIEVER_H
