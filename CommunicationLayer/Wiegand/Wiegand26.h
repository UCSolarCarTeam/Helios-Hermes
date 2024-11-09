#ifndef WIEGAND26_H
#define WIEGAND26_H

#include <QObject>
#include <QSerialPort>
#include <QThread>
#include <QByteArray>

#define MAX_BITS 26

class Wiegand26 : public QThread {
    Q_OBJECT

public:
    explicit Wiegand26(QObject *parent = nullptr);
    void begin(const QString &portName);
    void stop();

signals:
    void onData(unsigned long data);

protected:
    void run() override;

private:
    void reset();
    void processBuffer();

    QSerialPort *serialPort;
    QByteArray buffer;
    bool _bitData[MAX_BITS] = {false};
    int _bitCnt = 0;
    bool running = true;

private slots:
    void handleReadyRead();
};

#endif // WIEGAND26_H
