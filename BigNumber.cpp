#include "BigNumber.h"
#include <stdexcept>

using namespace std;

BigNumber::BigNumber( const std::string & str){
    setValues( str );
}

BigNumber::BigNumber(const long & intNum ){
    sign = ( intNum >= 0 );

    long temp1 = abs(intNum);
    numOfDigits = 0;
    while ( temp1 > 0 ){
        ++numOfDigits;
        temp1 /= 10;
    }

    numArray = new int8_t[numOfDigits];
    long temp2 = abs(intNum);
    for( size_t i{0}; i < numOfDigits; ++i ){
        numArray[i] = temp2 % 10;
        temp2 /= 10;
    }
}

BigNumber::BigNumber ( BigNumber & myBig ){
    sign = myBig.sign;
    numOfDigits = myBig.numOfDigits;
    numArray = new int8_t[numOfDigits];
    for(size_t i{0}; i < numOfDigits; ++i){
        numArray[i] = myBig.numArray[i];
    }
}

BigNumber::~BigNumber(){
    delete [] numArray;
}


unsigned BigNumber::numOfTrimCharsOnLeft(const std::string &str) {
    unsigned numOfChars = 0;
    size_t i = 0;
    while( i < str.size() - 1 && str[i] == '0' || str[i] == '-' || str[i] == '+'){
        ++numOfChars;
        ++i;
    }
    return numOfChars;
}

void BigNumber:: setValues( const std::string & str ){
    if( !validate( str, "[+-]?[0-9]+") ){
        throw invalid_argument("A number must include just decimal digits and + or -");
    }

    sign = ( str[0] != '-' );

    numOfDigits = str.size() - numOfTrimCharsOnLeft(str);

    delete [] numArray;
    numArray = new int8_t[numOfDigits];
    for(size_t i{0}; i < numOfDigits; ++i ){
        numArray[i] = str[str.size() - 1 - i] - 48;
    }

}

bool BigNumber::getSign() const {
    return sign;
}

unsigned int BigNumber::getNumOfDigits() const {
    return numOfDigits;
}

bool BigNumber::validate(const std::string &str, const std::string &pattern) {
    regex regPattern(pattern);
    return regex_match(str, regPattern);
}

std::ostream & operator<<( std::ostream & output, const BigNumber & myBig ){
    if( myBig.sign == false ){
        output << '-';
    }
    for( int i = myBig.numOfDigits - 1; i >= 0; --i){
        output << (int8_t)(myBig.numArray[i] + 48);
    }
    return output;
}

std::istream &operator>>(std::istream &input, BigNumber &myBig) {
    string str;
    input >> str;
    myBig.setValues(str);
    return input;
}

BigNumber & BigNumber:: operator=(const BigNumber & rightNum){
    // x = y;
    if ( &rightNum != this ){
        sign = rightNum.sign;
        numOfDigits = rightNum.numOfDigits;
        delete [] numArray;
        numArray = new int8_t[numOfDigits];
        for(size_t i{0}; i < numOfDigits; ++i){
            numArray[i] = rightNum.numArray[i];
        }
    }
    return *this;
}

BigNumber BigNumber:: operator-(){
    BigNumber temp;
    temp.sign = !sign;
    temp.numOfDigits = numOfDigits;
    temp.numArray = new int8_t[numOfDigits];
    for( size_t i{0}; i < numOfDigits; ++i){
        temp.numArray[i] = numArray[i];
    }
    return temp;
}



