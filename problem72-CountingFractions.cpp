#include <iostream>
#include <cmath>
using namespace std;

int countingFractions(){

    const int upperBound=1000000;
    bool primes[upperBound+1];primes[0]=0;primes[1]=0;
    unsigned long *phi=new unsigned long[upperBound+1];phi[0]=0;phi[1]=0;

    for(int k=2;k<=upperBound;++k){primes[k]=1;phi[k]=k;}
    for(int k=2;k<=sqrt(upperBound);k++){if(primes[k]){for(int m=2;m<=upperBound/k;m++){primes[m*k]=0;}}}

    for(int p=0;p<=upperBound;p++){
        if(!primes[p]){continue;}
        for(int m=1;m<=upperBound/p;m++){phi[m*p]=phi[m*p]*(p-1)/p;}
    }

    long count=0;
    for(int k=0;k<=upperBound;k++){count+=phi[k];}
    cout << "Result: "<< count<<endl;
    return count;
}

int main (int argc, char * const argv[]) {
    countingFractions();
}
