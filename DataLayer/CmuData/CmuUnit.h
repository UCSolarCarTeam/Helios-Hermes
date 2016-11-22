#pragma once

#include "I_CmuUnit.h"

class CmuUnit : public I_CmuUnit
{
public:
    CmuUnit(const unsigned char& cmuNumber);
    virtual ~CmuUnit();

    /* CmuUnit Gets */
    unsigned char getCmuNumber() const;
    unsigned short getCell0Voltage() const;
    unsigned short getCell1Voltage() const;
    unsigned short getCell2Voltage() const;
    unsigned short getCell3Voltage() const;
    unsigned short getCell4Voltage() const;
    unsigned short getCell5Voltage() const;
    unsigned short getCell6Voltage() const;
    unsigned short getCell7Voltage() const;
    unsigned short getPcbTemp() const;
    unsigned short getCellTemp0() const;
    unsigned short getCellTemp1() const;
    unsigned short getCellTemp2() const;
    unsigned short getCellTemp3() const;
    unsigned short getCellTemp4() const;
    unsigned short getCellTemp5() const;
    unsigned short getCellTemp6() const;
    unsigned short getCellTemp7() const;
    unsigned short getCellTemp8() const;
    unsigned short getCellTemp9() const;
    unsigned short getCellTemp10() const;
    unsigned short getCellTemp11() const;
    unsigned short getCellTemp12() const;
    unsigned short getCellTemp13() const;
    unsigned short getCellTemp14() const;

    /* CmuUnit Sets */
    void setCell0Voltage(const unsigned short&);
    void setCell1Voltage(const unsigned short&);
    void setCell2Voltage(const unsigned short&);
    void setCell3Voltage(const unsigned short&);
    void setCell4Voltage(const unsigned short&);
    void setCell5Voltage(const unsigned short&);
    void setCell6Voltage(const unsigned short&);
    void setCell7Voltage(const unsigned short&);
    void setPcbTemp(const unsigned short&);
    void setCellTemp0(const unsigned short&);
    void setCellTemp1(const unsigned short&);
    void setCellTemp2(const unsigned short&);
    void setCellTemp3(const unsigned short&);
    void setCellTemp4(const unsigned short&);
    void setCellTemp5(const unsigned short&);
    void setCellTemp6(const unsigned short&);
    void setCellTemp7(const unsigned short&);
    void setCellTemp8(const unsigned short&);
    void setCellTemp9(const unsigned short&);
    void setCellTemp10(const unsigned short&);
    void setCellTemp11(const unsigned short&);
    void setCellTemp12(const unsigned short&);
    void setCellTemp13(const unsigned short&);
    void setCellTemp14(const unsigned short&);


private:
    unsigned char cmuNumber_;
    unsigned short cell0Voltage_;
    unsigned short cell1Voltage_;
    unsigned short cell2Voltage_;
    unsigned short cell3Voltage_;
    unsigned short cell4Voltage_;
    unsigned short cell5Voltage_;
    unsigned short cell6Voltage_;
    unsigned short cell7Voltage_;
    unsigned short pcbTemp_;
    unsigned short cellTemp0_;
    unsigned short cellTemp1_;
    unsigned short cellTemp2_;
    unsigned short cellTemp3_;
    unsigned short cellTemp4_;
    unsigned short cellTemp5_;
    unsigned short cellTemp6_;
    unsigned short cellTemp7_;
    unsigned short cellTemp8_;
    unsigned short cellTemp9_;
    unsigned short cellTemp10_;
    unsigned short cellTemp11_;
    unsigned short cellTemp12_;
    unsigned short cellTemp13_;
    unsigned short cellTemp14_;
};
