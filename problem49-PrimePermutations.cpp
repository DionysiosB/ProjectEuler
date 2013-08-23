#include <iostream>
#include <set>
#include <cmath>
using namespace std;

multiset<int> digitList(int n){
    multiset<int> output;
    while(n>0){output.insert(n%10);n /=10;}
    return output;
}

void primePermutations(){

    const int upperBound=10000;
    bool primes[upperBound];primes[0]=0;primes[1]=0;
    for(int k=2;k<upperBound;k++){primes[k]=1;}
    for(int k=2;k<=sqrt(upperBound);k++){if(primes[k]){for(int m=2;m<=upperBound/k;m++){primes[m*k]=0;}}}

    int diff;
    for(int k=1000;k<upperBound;++k){
        if(!primes[k]){continue;}
        for(int m=k+1;m<upperBound;++m){
            if(!primes[m] || digitList(k)!=digitList(m)){continue;}
            diff=m-k;
            if( (2*m-k<upperBound) && primes[2*m-k] && digitList(k)==digitList(2*m-k) ){
                cout << k << " " << m << " " << 2*m-k <<endl;
                break;
            }
        }
    }
}

int main (int argc, char * const argv[]) {
    primePermutations();
}
