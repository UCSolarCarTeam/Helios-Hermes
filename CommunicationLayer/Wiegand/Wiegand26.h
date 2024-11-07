#ifndef WIEGAND26_H
#define WIEGAND26_H

#include <QObject>
#include <QTimer>
#include <QThread>
#include <QVector>

// Settings
#define MAX_BITS 26

class Wiegand26 : public QThread {
    Q_OBJECT

public:
    explicit Wiegand26(QObject *parent = nullptr);
    void begin(int pinData0, int pinData1, bool swapData = false);

signals:
    void dataReceived(unsigned long data);
    void errorOccurred(const QString &error);

protected:
    void run() override;

private:
    int _pinData0;
    int _pinData1;
    bool _swapData;
    QVector<bool> _bitData;
    unsigned int _bitCnt;
    QTimer _timeoutTimer;

    void reset();
    void processBit(int bitValue);
    void emitData();
    bool checkParity();
};

#endif // WIEGAND26_H
