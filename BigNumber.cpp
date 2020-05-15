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

BigNumber::BigNumber ( const BigNumber & myBig ){
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
    if( numOfDigits == 1 && numArray[0] == 0){
        sign = true;
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

BigNumber BigNumber:: operator-() const{
    BigNumber temp;
    temp.sign = !sign;
    temp.numOfDigits = numOfDigits;
    temp.numArray = new int8_t[numOfDigits];
    for( size_t i{0}; i < numOfDigits; ++i){
        temp.numArray[i] = numArray[i];
    }
    return temp;
}

int8_t & BigNumber::operator[](size_t index){
    if( index < 0 || index >= numOfDigits){
        throw out_of_range("The index is out of range.");
    }
    return numArray[index];
}

int BigNumber::operator[](size_t index) const{
    if( index < 0 || index >= numOfDigits){
        throw out_of_range("The index is out of range.");
    }
    return numArray[index];
}

bool BigNumber:: operator==( const BigNumber & myBig) const{
    if(sign != myBig.sign){
        return false;
    }
    if(numOfDigits != myBig.numOfDigits){
        return false;
    }
    for( size_t i{0}; i < numOfDigits; ++i){
        if( (*this)[i] != myBig[i] ){
            return false;
        }
    }
    return true;
}

bool BigNumber::operator!=(const BigNumber & myBig) const {
    return !(*this == myBig);
}

BigNumber::BigNumber ( BigNumber && myBig ) noexcept
    :sign{myBig.sign}, numOfDigits{myBig.numOfDigits}, numArray{myBig.numArray}
{
    myBig.numArray = nullptr;
}

BigNumber & BigNumber:: operator=( BigNumber && rightNum) noexcept {
    if( &rightNum != this ){
        sign = rightNum.sign;
        numOfDigits = rightNum.numOfDigits;
        delete [] numArray;
        numArray = rightNum.numArray;
        rightNum.numArray = nullptr;
    }
    return *this;
}

BigNumber BigNumber::unsignedMax(const BigNumber &num1, const BigNumber &num2) {
    if( num1.numOfDigits > num2.numOfDigits){
        return num1;
    }

    if( num1.numOfDigits < num2.numOfDigits){
        return num2;
    }

    size_t index = num1.numOfDigits - 1;
    while( (num1[index] == num2[index]) && (index > 0) ){
        --index;
    }
    if( num1[index] >= num2[index]){
        return num1;
    }
    if( num1[index] < num2[index]){
        return num2;
    }
}

BigNumber BigNumber::unsignedMin(const BigNumber &num1, const BigNumber &num2) {
    if( num1.numOfDigits > num2.numOfDigits){
        return num2;
    }

    if( num1.numOfDigits < num2.numOfDigits){
        return num1;
    }

    size_t index = num1.numOfDigits - 1;
    while( (num1[index] == num2[index]) && (index > 0) ){
        --index;
    }
    if( num1[index] >= num2[index]){
        return num2;
    }
    if( num1[index] < num2[index]){
        return num1;
    }
}

bool BigNumber::unsignedGreaterOrEqual(const BigNumber &num1, const BigNumber &num2) {
    return ( unsignedMax(num1, num2) == num1 );
}

bool BigNumber:: unsignedLessOrEqual( const BigNumber& num1, const BigNumber& num2){
    return ( unsignedMin(num2, num1) == num1 );
}

bool BigNumber:: operator>=( const BigNumber & myBig) const{
    if( sign == true && myBig.sign == false){
        return true;
    }

    if( sign == false && myBig.sign == true){
        return false;
    }

    if( sign == true && myBig.sign == true){
        return unsignedGreaterOrEqual(*this, myBig);
    }

    if( sign == false && myBig.sign == false){
        return unsignedLessOrEqual(*this, myBig);
    }
}

bool BigNumber:: operator<=( const BigNumber & myBig) const{
    if( sign == true && myBig.sign == false){
        return false;
    }

    if( sign == false && myBig.sign == true){
        return true;
    }

    if( sign == true && myBig.sign == true){
        return unsignedLessOrEqual(*this, myBig);
    }

    if( sign == false && myBig.sign == false){
        return unsignedGreaterOrEqual(*this, myBig);
    }
}

bool BigNumber:: operator>( const BigNumber & myBig) const{
    return !(*this <= myBig);
}

bool BigNumber:: operator<( const BigNumber & myBig) const{
    return !(*this >= myBig);
}