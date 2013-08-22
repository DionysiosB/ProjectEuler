#include <iostream>
#include <cmath>
using namespace std;

unsigned long long largePrime(){

    const int power=7830457;
    const int multiplier=28433;
    const long long tenDigits=10000000000;

    unsigned long long output=1;
    for(int k=1;k<=power;++k){output=(2*output)%tenDigits;}
    output=(multiplier*output+1)%tenDigits;
    return output;
}

int main (int argc, char * const argv[]) {
    cout << largePrime()<<endl;
    return 0;
}
