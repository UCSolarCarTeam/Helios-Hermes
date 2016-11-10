#pragma once

#include <QObject>

class I_CmuUnit : public QObject
{
    Q_OBJECT
public:
    virtual ~I_CmuUnit() {}

    /* CmuUnit Gets */
    virtual unsigned char getCmuNumber() const = 0;
    virtual unsigned short getCell0Voltage() const = 0;
    virtual unsigned short getCell1Voltage() const = 0;
    virtual unsigned short getCell2Voltage() const = 0;
    virtual unsigned short getCell3Voltage() const = 0;
    virtual unsigned short getCell4Voltage() const = 0;
    virtual unsigned short getCell5Voltage() const = 0;
    virtual unsigned short getCell6Voltage() const = 0;
    virtual unsigned short getCell7Voltage() const = 0;
    virtual unsigned short getPcbTemp() const = 0;
    virtual unsigned short getCellTemp0() const = 0;
    virtual unsigned short getCellTemp1() const = 0;
    virtual unsigned short getCellTemp2() const = 0;
    virtual unsigned short getCellTemp3() const = 0;
    virtual unsigned short getCellTemp4() const = 0;
    virtual unsigned short getCellTemp5() const = 0;
    virtual unsigned short getCellTemp6() const = 0;
    virtual unsigned short getCellTemp7() const = 0;
    virtual unsigned short getCellTemp8() const = 0;
    virtual unsigned short getCellTemp9() const = 0;
    virtual unsigned short getCellTemp10() const = 0;
    virtual unsigned short getCellTemp11() const = 0;
    virtual unsigned short getCellTemp12() const = 0;
    virtual unsigned short getCellTemp13() const = 0;
    virtual unsigned short getCellTemp14() const = 0;

    /* CmuUnit Sets */
    virtual void setCmuNumber(const unsigned char&) = 0;
    virtual void setCell0Voltage(const unsigned short&) = 0;
    virtual void setCell1Voltage(const unsigned short&) = 0;
    virtual void setCell2Voltage(const unsigned short&) = 0;
    virtual void setCell3Voltage(const unsigned short&) = 0;
    virtual void setCell4Voltage(const unsigned short&) = 0;
    virtual void setCell5Voltage(const unsigned short&) = 0;
    virtual void setCell6Voltage(const unsigned short&) = 0;
    virtual void setCell7Voltage(const unsigned short&) = 0;
    virtual void setPcbTemp(const unsigned short&) = 0;
    virtual void setCellTemp0(const unsigned short&) = 0;
    virtual void setCellTemp1(const unsigned short&) = 0;
    virtual void setCellTemp2(const unsigned short&) = 0;
    virtual void setCellTemp3(const unsigned short&) = 0;
    virtual void setCellTemp4(const unsigned short&) = 0;
    virtual void setCellTemp5(const unsigned short&) = 0;
    virtual void setCellTemp6(const unsigned short&) = 0;
    virtual void setCellTemp7(const unsigned short&) = 0;
    virtual void setCellTemp8(const unsigned short&) = 0;
    virtual void setCellTemp9(const unsigned short&) = 0;
    virtual void setCellTemp10(const unsigned short&) = 0;
    virtual void setCellTemp11(const unsigned short&) = 0;
    virtual void setCellTemp12(const unsigned short&) = 0;
    virtual void setCellTemp13(const unsigned short&) = 0;
    virtual void setCellTemp14(const unsigned short&) = 0;

signals:
    void cmuNumberReceived(const unsigned char& cmuNumber);
    void cell0VoltageReceived(const unsigned short& cell0Voltage);
    void cell1VoltageReceived(const unsigned short& cell1Voltage);
    void cell2VoltageReceived(const unsigned short& cell2Voltage);
    void cell3VoltageReceived(const unsigned short& cell3Voltage);
    void cell4VoltageReceived(const unsigned short& cell4Voltage);
    void cell5VoltageReceived(const unsigned short& cell5Voltage);
    void cell6VoltageReceived(const unsigned short& cell6Voltage);
    void cell7VoltageReceived(const unsigned short& cell7Voltage);
    void pcbTempReceived(const unsigned short& pcbTemp);
    void cellTemp0Received(const unsigned short& cellTemp0);
    void cellTemp1Received(const unsigned short& cellTemp1);
    void cellTemp2Received(const unsigned short& cellTemp2);
    void cellTemp3Received(const unsigned short& cellTemp3);
    void cellTemp4Received(const unsigned short& cellTemp4);
    void cellTemp5Received(const unsigned short& cellTemp5);
    void cellTemp6Received(const unsigned short& cellTemp6);
    void cellTemp7Received(const unsigned short& cellTemp7);
    void cellTemp8Received(const unsigned short& cellTemp8);
    void cellTemp9Received(const unsigned short& cellTemp9);
    void cellTemp10Received(const unsigned short& cellTemp10);
    void cellTemp11Received(const unsigned short& cellTemp11);
    void cellTemp12Received(const unsigned short& cellTemp12);
    void cellTemp13Received(const unsigned short& cellTemp13);
    void cellTemp14Received(const unsigned short& cellTemp14);
};
