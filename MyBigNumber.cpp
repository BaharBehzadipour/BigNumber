//
// Created by pars on 5/22/2020.
//

#include "MyBigNumber.h"
#include <cmath>
#include <stdexcept>
#include <sstream>

using namespace  std;

BigNumber MyBigNumber::multByOneDigit(  const BigNumber& myBig , const int8_t& number ) {
if(number >=0 && number<=9){
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
return  multi;}
else{
    throw invalid_argument("A number is out of range");
}
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

BigNumber operator * (const BigNumber &num1, const BigNumber &num2) {

  const  BigNumber max=BigNumber::unsignedMax(num1,num2);
  const  BigNumber min=BigNumber::unsignedMin(num1,num2);
    size_t i{0};
    BigNumber sum = "0";

    for(; i<min.getNumOfDigits();++i){
        sum = sum + ((MyBigNumber::multByOneDigit(max,min[i]))<<i);
    }
    if(num1.getSign()==num2.getSign()){
        sum.setSign(true);
    }else {
        sum.setSign(false);
    }

    return sum;
}

BigNumber MyBigNumber::power( const BigNumber &  myBig , const unsigned int number ) {

    BigNumber myBig1 = myBig;
    if(number==0){
        return 1;
    }
    for(size_t i=1;i<number;++i){
        myBig1=myBig1*myBig;
    }
    return myBig1;
}

BigNumber MyBigNumber::operator()(unsigned int a , unsigned int b) {
    MyBigNumber temp;
    temp.sign = true ;
    temp.numOfDigits = b;
    temp.numArray = new int8_t [temp.numOfDigits];
    unsigned int i =(a-b)+1;
    for( int j=0;j< b;++j){
        temp[j]=numArray[i];
        ++i;
    }
return temp;
}



BigNumber operator/(const BigNumber &num1 , const BigNumber &num2) {
    if(num2=="0"){
        throw invalid_argument("second number cant be zero");
    }
    
   if(num1==num2){
       return 1;
   }else if(BigNumber::unsignedMax(num1,num2)==num2){
       return "0";
   }else {
       MyBigNumber temp ;
       temp.numOfDigits=num2.getNumOfDigits()+1;
       temp.numArray=new int8_t [ temp.numOfDigits];

       MyBigNumber temp2=num1;
       MyBigNumber temp3=num1;
       int carry=0;
       temp2=temp2(num1.getNumOfDigits()-1,num2.getNumOfDigits());

        if(temp2 < num2){
            temp2=temp3(num1.getNumOfDigits()-1,num2.getNumOfDigits()+1);
            if(((temp2[temp2.getNumOfDigits() - 1]*10+temp2[temp2.getNumOfDigits() - 2] )/ num2[num2.getNumOfDigits()-1])*num2>temp2){
                carry= ((temp2[temp2.getNumOfDigits() - 1]*10+temp2[temp2.getNumOfDigits() - 2] )/ num2[num2.getNumOfDigits()-1])-1;
            }else {
                carry = (temp2[temp2.getNumOfDigits() - 1] * 10 + temp2[temp2.getNumOfDigits() - 2]) /
                        num2[num2.getNumOfDigits() - 1];
            }
        } else {
            if((temp2[temp2.getNumOfDigits() - 1] / num2[num2.getNumOfDigits()-1])*num2 > temp2){
           carry= temp2[temp2.getNumOfDigits() - 1] / num2[num2.getNumOfDigits()-1] -1;
            } else {carry= temp2[temp2.getNumOfDigits() - 1] / num2[num2.getNumOfDigits()-1];}
        }
        for (int i=0;i<num1.getNumOfDigits()-temp2.getNumOfDigits();++i){
            temp2=((temp2-carry*num2)<<1)+temp3[num1.getNumOfDigits()-temp2.getNumOfDigits()-1];
            carry=carry*10;
        }
   }

}

MyBigNumber::MyBigNumber(BigNumber myBig) {
sign=myBig.getSign();
numOfDigits=myBig.getNumOfDigits();
numArray=new int8_t [numOfDigits];

for(int i=0;i<numOfDigits;++i){
    numArray[i]=myBig[i];
}
}

MyBigNumber::~MyBigNumber() {
delete [] numArray;
}

MyBigNumber::MyBigNumber(const string &str) : BigNumber(str) {

}

MyBigNumber::MyBigNumber(const char *myCharArray) : BigNumber(myCharArray) {

}

MyBigNumber::MyBigNumber(const long &intNum) : BigNumber(intNum) {

}

MyBigNumber &MyBigNumber::operator=(const MyBigNumber &myBigNumber) {
    if(&myBigNumber!=this){
    sign=myBigNumber.sign;
    numOfDigits=myBigNumber.numOfDigits;
    delete [] numArray;
    numArray=new int8_t [numOfDigits];
    for(int i=0;i<numOfDigits;++i){
        numArray[i]=myBigNumber[i];
    }}
    return *this;
}

std::string MyBigNumber::toString() const {
    ostringstream  output;
    output<<"i am a MyBigNumber object"<<endl;
    output<<BigNumber::toString();
    return output.str();
}

std::string MyBigNumber::toString(int num) {
    ostringstream output;
    for(int i=1;i<=numOfDigits;++i){

        output<<"hello"<<endl;

    }
    output<<BigNumber::toString();
    return output.str();
}

MyBigNumber::MyBigNumber(const MyBigNumber &myBigNumber) {

}

MyBigNumber::MyBigNumber(MyBigNumber &&myBigNumber) noexcept {

}

MyBigNumber &MyBigNumber::operator=(MyBigNumber &&myBigNumber) noexcept {
    if(&myBigNumber!=this){
        sign=myBigNumber.sign;
        numOfDigits=myBigNumber.numOfDigits;
        delete [] numArray;
        numArray=new int8_t [numOfDigits];
        for(int i=0;i<numOfDigits;++i){
            numArray[i]=myBigNumber[i];
        }}
    return *this;
}






