//
// Created by pars on 5/22/2020.
//

#include "MyBigNumber.h"

BigNumber MyBigNumber::multByOneDigit(  const BigNumber& myBig , const int8_t& number ) {

    MyBigNumber multi;

    multi.sign = true;
    multi.numOfDigits = myBig.getNumOfDigits() + 1;
    multi.numArray = new int8_t[multi.numOfDigits];

    size_t i{0};
    int8_t carry = 0;
    int8_t s;

    for (; i < myBig.getNumOfDigits(); ++i) {
        s = (myBig[i]*number) + carry;
        multi[i] = s % 10;
        carry = s / 10;
    }
if(carry==0){
    multi.numOfDigits-=1;
}else{
    multi[i]=carry;
}
return  multi;
}
