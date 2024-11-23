#ifndef GPIOREADER_H
#define GPIOREADER_H

#include <QObject>
#include <QSerialPort>
#include <QThread>

class GPIOReader : public QThread {
    Q_OBJECT

public:
    explicit GPIOReader(QObject* parent = nullptr);
    ~GPIOReader();

    void begin(const QString& portName);
    void stop();
    void reset();

signals:
    void onData(unsigned long data);

protected:
    void run() override;

private:
    QSerialPort* serialPort;
    bool running = true;
    QByteArray buffer;
    static const int MAX_BITS = 26;
    bool _bitData[MAX_BITS] = {false};
    int _bitCnt = 0;

    void processBuffer();

private slots:
    void handleReadyRead();
};

#endif // GPIOREADER_H
