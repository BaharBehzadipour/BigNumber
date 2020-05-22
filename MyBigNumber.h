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

};


#endif //TA14_MYBIGNUMBER_H
