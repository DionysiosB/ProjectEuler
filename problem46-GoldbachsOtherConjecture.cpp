#include <iostream>
#include <cmath>
#include <set>
using namespace std;

void disproveGoldbach(long upperBound){

    bool primes[upperBound+1];
    primes[0]=0;primes[1]=0;for(int k=2;k<=upperBound;++k){primes[k]=1;}
    for(int k=2;k<=sqrt(upperBound);++k){if(primes[k]){for(int m=2;m<=upperBound/k;++m){primes[m*k]=0;}}}
    //for(int k=0;k<=upperBound;++k){if(primes[k]){cout << k<<endl;}}
    
    int diff=0;int s=0;
    for(int n=3;n<=upperBound;n+=2){
        if(primes[n]){continue;}
        s=0;
        do{++s;diff=n-2*s*s;}while((diff >0)&&(!primes[diff]));
        if(diff<0){cout<<"Found CounterExample!   " <<n << endl; break;}
    }
}

int main (int argc, char * const argv[]) {
   
    disproveGoldbach(10000);
    return 0;
}
