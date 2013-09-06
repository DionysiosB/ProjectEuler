#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

unsigned long long factorialTrailingZeros(unsigned long long input){

    unsigned long long N=input/(5*5*5*5*5*5*5*5);
    cout << N<<endl;
    unsigned long long output=1;
    for(unsigned long n=1;n<=N;n++){
        unsigned long temp=n;
        output *=temp;
        while(output%10==0){output /=10;}
        output %=100000000;
    }
    return output%1000000;
}

int main (){cout <<factorialTrailingZeros(1000000000000)<<endl;}
