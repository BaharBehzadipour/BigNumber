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
    int8_t& operator[](size_t index);
    static BigNumber unsignedMax( const BigNumber& num1, const BigNumber& num2);
    static BigNumber unsignedMin( const BigNumber& num1, const BigNumber& num2);

public:
    BigNumber( const std::string & str );
    BigNumber(const long & intNum );
    BigNumber ( BigNumber & myBig );   // copy constructor
    BigNumber ( BigNumber && myBig ) noexcept;  // move constructor
    ~BigNumber();
    void setValues( const std::string & str );
    bool getSign() const;
    unsigned int getNumOfDigits() const;
    BigNumber & operator=(const BigNumber & rightNum);
    BigNumber & operator=(BigNumber && rightNum);   // move assignment overloading
    BigNumber operator-() const;
    int operator[](size_t index) const;
    bool operator==( const BigNumber & ) const;
    bool operator!=( const BigNumber & ) const;
};


#endif //TA14_BIGNUMBER_H
