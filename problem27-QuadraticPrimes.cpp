#include <iostream>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

long computeQuadratic(int n,int a, int b){
    return n*n+a*n+b;
}


void printMagicNumbers(int upperBound){

    //find primes;
    int limit=upperBound*upperBound+1;
    bool primes[limit];
    primes[0]=0;primes[1]=0;for(int k=2;k<limit;++k){primes[k]=1;};
    for(int k=0;k<=sqrt(limit);++k){if(primes[k]){for(int m=2;m<=limit/k;++m){primes[m*k]=0;}}}
    
    int maxA=0,maxB=0,maxPrimes=0;;
    int n=0,total=0;

    for(int a=-upperBound;a<upperBound;++a){
        for(int b=-upperBound;b<upperBound;++b){

            n=0;total=0;
            while(n<upperBound){
                if(primes[computeQuadratic(n,a,b)]){++total;++n;}
                else{break;}
            } 
            if(total>maxPrimes){maxA=a;maxB=b;maxPrimes=total;cout << maxA<<"   " <<maxB<<"   "<< maxPrimes<<endl;}
        }
    }
    cout << "a:"<<maxA<<"  b:"<<maxB<<"   Product:"<<maxA*maxB<<"    Total:"<<maxPrimes<<endl;
}

int main (int argc, char * const argv[]) {
	printMagicNumbers(1000);
	return 0;
}
