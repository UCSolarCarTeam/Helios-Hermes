#ifndef PROXIMITYSENSORSDATA_H
#define PROXIMITYSENSORSDATA_H

#include <QObject>

class ProximitySensorsData : public QObject {
    Q_OBJECT
public:
    ProximitySensorsData();
    virtual ~ProximitySensorsData();

    unsigned short getProximitySensor1() const;
    unsigned short getProximitySensor2() const;
    unsigned short getProximitySensor3() const;
    unsigned short getProximitySensor4() const;

    void setProximitySensor1(const unsigned short& val);
    void setProximitySensor2(const unsigned short& val);
    void setProximitySensor3(const unsigned short& val);
    void setProximitySensor4(const unsigned short& val);

private:
    unsigned short proximitySensor1_ = 0;
    unsigned short proximitySensor2_ = 0;
    unsigned short proximitySensor3_ = 0;
    unsigned short proximitySensor4_ = 0;
};

#endif // PROXIMITYSENSORSDATA_H
