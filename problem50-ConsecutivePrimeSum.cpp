#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int consecutivePrimeSum(int upperBound){

    bool primes[upperBound+1];
    primes[0]=0;primes[1]=0;for(int k=2;k<=upperBound;++k){primes[k]=1;}
    for(int k=2;k<=sqrt(upperBound);++k){if(primes[k]){for(int m=2;m<=upperBound/k;++m){primes[m*k]=0;}}}

    int currentLength=0,maxLength=0,currentSum=0,maxSum=0;
    for(int k=0;k<=upperBound;++k){if(primes[k]){
            currentSum=k;currentLength=1;
            for(int m=k+1;m<=upperBound;++m){if(primes[m]){
                currentSum+=m;++currentLength;
                if(currentSum >=upperBound ){break;}
                if(primes[currentSum] && currentLength>maxLength){maxLength=currentLength;maxSum=currentSum;}
            }}
    }}
    return maxSum;
}

int main (int argc, char * const argv[]) {
    cout << consecutivePrimeSum(1000000)<<endl;
	return 0;
}
