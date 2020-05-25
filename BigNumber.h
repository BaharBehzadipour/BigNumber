#ifndef TA14_BIGNUMBER_H
#define TA14_BIGNUMBER_H

#include <cstdint>
#include <string>
#include <regex>

class BigNumber {

    friend std::ostream& operator<<( std::ostream & output, const BigNumber & myBig ); //prototype of operator <<
    friend std::istream& operator>>( std::istream & input, BigNumber & myBig ); //prototype of operator >>
    friend BigNumber operator+( const BigNumber & num1, const BigNumber & num2); //prototype of operator +
    friend BigNumber operator-( const BigNumber & num1, const BigNumber & num2); //prototype of operator -

protected:
    bool sign; //sign of BigNumber
    int8_t * numArray = nullptr; //Array of BigNumber numbers
    unsigned numOfDigits; //number of digits
    bool validate( const std::string & str, const std::string & pattern); //check value of entered number
    unsigned numOfTrimCharsOnLeft( const std::string & str );
    BigNumber(){} //no arg constructor

    static bool unsignedGreaterOrEqual( const BigNumber& num1, const BigNumber& num2);
    static bool unsignedLessOrEqual( const BigNumber& num1, const BigNumber& num2);
    static BigNumber unsignedAdd( const BigNumber& num1, const BigNumber& num2 );

public:

    static BigNumber unsignedMax( const BigNumber& num1, const BigNumber& num2);
    static BigNumber unsignedMin( const BigNumber& num1, const BigNumber& num2);
    static BigNumber unsignedSubtract( const BigNumber& num1, const BigNumber& num2 );
    int8_t& operator[](size_t index); //prototype of operator []

    BigNumber( const std::string & str ); //one arg constructor
    BigNumber( const char * myCharArray ) : BigNumber((std::string) myCharArray) {} //one arg constructor
    BigNumber(const long & intNum );
    BigNumber ( const BigNumber & myBig );   // copy constructor
    BigNumber ( BigNumber && myBig ) noexcept;  // move constructor
    ~BigNumber(); //destructor

    void setValues( const std::string & str ); //prototype of function that set a BigNumber
    void setSign (bool b ); //prototype of function that set sign
    bool getSign() const; //prototype of function that get sign
    unsigned int getNumOfDigits() const; //prototype of function that get number of digits
    BigNumber & operator=(const BigNumber & rightNum); //prototype assignment operator
    BigNumber & operator=(BigNumber && rightNum) noexcept ; // move assignment overloading
    BigNumber operator-() const; //prototype of operator -
    int operator[](size_t index) const; //prototype of operator []
    bool operator==( const BigNumber & myBig) const; //prototype of operator ==
    bool operator!=( const BigNumber & myBig) const; //prototype of operator !=
    bool operator>=( const BigNumber & myBig) const; //prototype of operator >=
    bool operator<=( const BigNumber & myBig) const; //prototype of operator <=
    bool operator>( const BigNumber & myBig) const; //prototype of operator >
    bool operator<( const BigNumber & myBig) const; //prototype of operator <
    BigNumber absoluteValue() const;
    BigNumber operator>>( unsigned shift ); //prototype of operator >> (shift)

    BigNumber& operator ++(); //prototype of operator ++(pre) for BigNumber
    BigNumber operator ++(int); //prototype of operator ++(pose) for BigNumber

    BigNumber& operator --(); //prototype of operator --(pre) for BigNumber
    BigNumber operator --(int); //prototype of operator --(pose) for BigNumber

    std::string toString()const;

};


#endif //TA14_BIGNUMBER_H
