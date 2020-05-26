#include <iostream>
#include "BigNumber.h"
#include "MyBigNumber.h"

using namespace std;

int main() {

    try {
        cout << " *********************** HW_8 *********************** " << endl;
        cout << boolalpha;
        BigNumber myBigNumber1 = "-25565555548658"; // call constructor
        BigNumber myBigNumber2 = -255555485566; // call constructor
        BigNumber myBigNumber3 = "25852"; // call constructor
        MyBigNumber myBigNum1 = "-12155555555555555555"; // call constructor
        MyBigNumber myBigNum2 = 6545454; // call constructor
        MyBigNumber myBigNum3 = "258955"; // call constructor
        cout << "first BigNumber : " << myBigNumber1 << endl << "second BigNumber : " << myBigNumber2
             << endl; //call operator << for BigNumber
        cout << "Enter a BigNumber : " << endl;
        cin >> myBigNumber2; //call operator >> for BigNumber
        cout << "second BigNumber after change: " << myBigNumber2 << endl;
        myBigNumber2.setValues("6810"); //call function setValue for BigNumber
        myBigNumber2.setSign(false); //call function setSign
        cout << "second BigNumber after setValue: " << myBigNumber2 << endl;
        cout << "myBigNumber1's sign = " << myBigNumber1.getSign() << endl; //call function getSign
        cout << "myBigNumber1's NumOfDigits = " << myBigNumber1.getNumOfDigits() << endl; //call function getNumOfDigits
        cout << "myBigNumber2 + myBigNumber1 = " << (myBigNumber2 + myBigNumber1)
             << endl; //call operator + for BigNumber
        cout << "myBigNumber2 - myBigNumber1 = " << (myBigNumber2 - myBigNumber1)
             << endl; //call operator - for BigNumber
        myBigNumber3 = myBigNumber1;
        cout << "myBigNumber3 = " << myBigNumber3 << endl; //call operator = for BigNumber
        cout << "-myBigNumber3 = " << (-myBigNumber3) << endl; //call operator - for BigNumber
        cout << "myBigNumber2 <= myBigNumber1 : " << (myBigNumber2 <= myBigNumber1)
             << endl; //call operator <= for BigNumber
        cout << "myBigNumber2 < myBigNumber1 : " << (myBigNumber2 < myBigNumber1)
             << endl; //call operator < for BigNumber
        cout << "myBigNumber2 >= myBigNumber1 : " << (myBigNumber2 >= myBigNumber1)
             << endl; //call operator >= for BigNumber
        cout << "myBigNumber2 > myBigNumber1 : " << (myBigNumber2 > myBigNumber1)
             << endl; //call operator > for BigNumber
        cout << "unsignedMax(myBigNumber1,myBigNumber2) : " << BigNumber::unsignedMax(myBigNumber1, myBigNumber2)
             << endl; //call unsignedMax function for BigNumber
        cout << "unsignedMin(myBigNumber1,myBigNumber2) : " << BigNumber::unsignedMin(myBigNumber1, myBigNumber2)
             << endl; //call unsignedMin function for BigNumber
        cout << "unsignedSubtract(myBigNumber1,myBigNumber2) : "
             << BigNumber::unsignedSubtract(myBigNumber1, myBigNumber2)
             << endl; //call unsignedSubtract function for BigNumber
        int a = myBigNumber2[1];
        cout << "myBigNumber2[1] = " << a << endl; //call operator [] for BigNumber
        cout << "myBigNumber2.absoluteValue() : " << myBigNumber2.absoluteValue()
             << endl; //call absoluteValue function for BigNumber
        cout << "myBigNumber2>>2 : " << (myBigNumber2 >> 2) << endl; //call operator shift >> for BigNumber
        cout << "myBigNumber2++ : " << (myBigNumber2++) << endl; //call operator ++(pose) for BigNumber
        cout << "++myBigNumber2 : " << (++myBigNumber2) << endl; //call operator ++(pre) for BigNumber
        cout << "myBigNumber2-- : " << (myBigNumber2--) << endl; //call operator --(pose) for BigNumber
        cout << "--myBigNumber2 : " << (--myBigNumber2) << endl; //call operator --(pre) for BigNumber
        cout << "myBigNum1 : " << myBigNum1 << endl << "myBigNum2 : " << myBigNum2 << endl;
        myBigNum3 = myBigNum2; //call operator = for MyBigNumber
        cout << "myBigNum3 after assignment : " << myBigNum3 << endl;
        cout << "multByOneDigit(myBigNumber1 , 2 ) : " << MyBigNumber::multByOneDigit(myBigNumber1, 2)
             << endl; //call multByOneDigit function for MyBigNumber
        cout << "myBigNum1 << 2 : " << (myBigNum1 << 2) << endl; //call operator shift << for BigNumber
        cout << "myBigNum1*myBigNum2 = " << (myBigNum1 * myBigNum2) << endl; //call operator * for BigNumber
        cout << "myBigNum1^2 = " << MyBigNumber::power(myBigNum1, 2) << endl; //call power function for BigNumber
        cout << "myBigNum1/myBigNum2 = " << (myBigNum1 / myBigNum2) << endl; //call operator / for BigNumber
        cout << "myBigNum1%myBigNum2 = " << (myBigNum1 % myBigNum2) << endl; //call operator % for BigNumber
        cout << "myBigNum2(5,2) : " << myBigNum2(4, 2) << endl; //call operator () for BigNumber
    } catch (out_of_range e) {

              cout<<e.what()<<endl;
    }
      return 0;
}
