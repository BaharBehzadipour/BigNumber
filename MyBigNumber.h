//
// Created by pars on 5/22/2020.
//

#ifndef TA14_MYBIGNUMBER_H
#define TA14_MYBIGNUMBER_H
#include "BigNumber.h"



class MyBigNumber : public BigNumber    {

public:
    static  BigNumber multByOneDigit ( const BigNumber& myBig , const int8_t&   number );
    friend BigNumber operator << ( const  BigNumber myBig1 , const unsigned shift ); // ba mybig ahhhh
    friend  BigNumber operator * (const BigNumber &num1, const BigNumber &num2);
    static BigNumber power( const BigNumber & myBig , const unsigned int number );
    BigNumber operator () (unsigned  int a , unsigned  int b);
};


#endif //TA14_MYBIGNUMBER_H
