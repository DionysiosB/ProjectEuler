#include <iostream>
#include <cmath>
using namespace std;

long primeCubePartnership(long upperBound) {
	
    long primeBound;
    for(int k=1;k<=upperBound;k++){primeBound=k;if(k*k*k-(k-1)*(k-1)*(k-1)>upperBound){break;}}

    long a,count=0;
    int *primes= new int[upperBound+1];primes[0]=0;primes[1]=0;for(int k=2;k<=upperBound;k++){primes[k]=1;}
    for(int k=0;k<=sqrt(upperBound);k++){if(primes[k]){for(int m=2;m<=upperBound/k;m++){primes[k*m]=0;}}}
    for(int k=0;k<=primeBound;k++){a=k*k*k-(k-1)*(k-1)*(k-1);if(a<=upperBound && primes[a]){count++;}}
    return count;
}

int main () {cout<< primeCubePartnership(1000000)<<endl;}
