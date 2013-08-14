#include <iostream>
#include <cmath>
#include <set>
using namespace std;


bool isPangram(long n){
    set<int> digits;bool output;
    while(n>0){
        if( digits.find(n%10)== digits.end() ){digits.insert(n%10);n /=10;}
        else{return 0;}
    }
    for(int k=1;k<=digits.size();++k){if(digits.find(k) == digits.end()){return 0;}}
    return 1;
}


void findPandigitalPrime(long upperBound){

    bool primes[upperBound+1];
    primes[0]=0;primes[1]=0;for(long k=2;k<=upperBound;++k){primes[k]=1;}
    for(long k=0;k<=sqrt(upperBound);++k){
        if(primes[k]){for(long m=2;m<=upperBound/k;++m){primes[m*k]=0;}}
    }
    for(long k=upperBound;k>=0;--k){if(primes[k] && isPangram(k)) {cout<<k<<endl;break;}}
}

int main (int argc, char * const argv[]) {
    findPandigitalPrime(8000000);
	return 0;
}
