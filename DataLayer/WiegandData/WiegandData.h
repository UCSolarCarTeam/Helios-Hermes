#ifndef WIEGANDDATA_H
#define WIEGANDDATA_H

#include <QByteArray>

class WiegandData {
public:
    WiegandData() = default;

    QByteArray getData() const;
    void setData(const QByteArray& data);
    int getWiegandId() const;
    void clearData();

private:
    QByteArray wiegandData_;
};

#endif  // WIEGANDDATA_H
