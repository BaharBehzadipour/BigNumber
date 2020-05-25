
#ifndef TA14_MYBIGNUMBER_H
#define TA14_MYBIGNUMBER_H
#include "BigNumber.h"



class MyBigNumber : public BigNumber    {

public:
    MyBigNumber(){} //no arg constructor
    MyBigNumber (BigNumber myBig); //one arg constructor
    MyBigNumber(const std::string &str ); //one arg constructor
    MyBigNumber(const char * myCharArray); //one arg constructor
    MyBigNumber(const long & intNum); //one arg constructor
    MyBigNumber & operator =(const MyBigNumber & myBigNumber);
    MyBigNumber (const MyBigNumber & myBigNumber); //copy constructor
    MyBigNumber(MyBigNumber && myBigNumber)noexcept ; // move constructor
    MyBigNumber & operator= (MyBigNumber && myBigNumber)noexcept ; // move assignment overloading

    std::string toString()const;
    std::string toString(int num);

    static  BigNumber multByOneDigit ( const BigNumber& myBig , const int8_t&   number );
    friend BigNumber operator << ( const  BigNumber myBig1 , const unsigned shift ); //prototype of operator <<
    friend  BigNumber operator * (const BigNumber &num1, const BigNumber &num2); //prototype of operator *
    static BigNumber power( const BigNumber & myBig , const unsigned int number ); //prototype of power function
    BigNumber operator () (unsigned  int a , unsigned  int b); //prototype of operator ()
    friend  BigNumber operator / (const BigNumber &num1, const BigNumber &num2); //prototype of operator /
    friend  BigNumber operator % (const BigNumber &num1, const BigNumber &num2); //prototype of operator %
};


#endif //TA14_MYBIGNUMBER_H
