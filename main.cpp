#include <iostream>
#include <cstdint>

#include "BigNumber.h"

using namespace std;

int main() {
    cout << boolalpha;

    BigNumber myBig1 = 15;


    BigNumber myBig2 = "0000173";
cout<<myBig1-myBig2<<endl;
cout<<(myBig1--)<<endl<<(--myBig1)<<endl;

}
