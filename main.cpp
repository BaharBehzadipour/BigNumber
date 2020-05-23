#include <iostream>
#include <cstdint>

#include "BigNumber.h"
#include "MyBigNumber.h"

using namespace std;

int main() {

    BigNumber b="-155";
    BigNumber c=55;
    MyBigNumber a;
    a.setValues("-0012");
    MyBigNumber x;
    x.setValues("158462");

    cout<<MyBigNumber::multByOneDigit(b,2)<<endl;
    cout<<(b>>2)<<endl;
    cout<<(a<<0)<<endl;

    cout<<(a*x)<<endl;

    cout<<MyBigNumber::power(b,5)<<endl;

    cout<<x(4,3)<<endl;

return 0;
}
