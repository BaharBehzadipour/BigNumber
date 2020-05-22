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

BigNumber operator << (const BigNumber myBig1, const unsigned shift ) {

    MyBigNumber myBig;
    myBig.sign = myBig1.getSign();
    myBig.numOfDigits = myBig1.getNumOfDigits()+shift;
    myBig.numArray=new int8_t [myBig.numOfDigits];
    size_t i{0};
    for(; i <shift; ++i){
      myBig[i]=0;
    }
    size_t j{0};
    for(;i<myBig.numOfDigits;++i){
       myBig[i]= myBig1[j];
       ++j;
    }
    return myBig;
}


