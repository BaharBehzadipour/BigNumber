#ifndef TA14_BIGNUMBER_H
#define TA14_BIGNUMBER_H

#include <cstdint>
#include <string>
#include <regex>

class BigNumber {
    friend std::ostream& operator<<( std::ostream & output, const BigNumber & myBig );
    friend std::istream& operator>>( std::istream & input, BigNumber & myBig );
private:
    bool sign;
    int8_t * numArray = nullptr;
    unsigned numOfDigits;

    bool validate( const std::string & str, const std::string & pattern);
    unsigned numOfTrimCharsOnLeft( const std::string & str );
    BigNumber(){}

public:
    BigNumber( const std::string & str );
    BigNumber(const long & intNum );
    BigNumber ( BigNumber & myBig );
    ~BigNumber();
    void setValues( const std::string & str );
    bool getSign() const;
    unsigned int getNumOfDigits() const;
    BigNumber & operator=(const BigNumber & rightNum);
    BigNumber operator-();

};


#endif //TA14_BIGNUMBER_H
