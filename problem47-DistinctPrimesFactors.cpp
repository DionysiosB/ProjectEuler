#include <iostream>
#include <cmath>
#include <set>
using namespace std;

void distinctPrimeFactors(long upperBound){

    const int requestedFactors=4;
    bool primes[upperBound+1];primes[0]=0;primes[1]=0;
    for(int k=2;k<=upperBound;k++){primes[k]=1;}
    for(int k=2;k<=sqrt(upperBound);k++){if(primes[k]){for(int m=2;m<=upperBound/k;m++){primes[m*k]=0;}}}

    set<int> divisorSet;
    int k=0,count=0,lastNumber=0;
    for(int n=3;n<=upperBound-3;n++){
        if(primes[n]){continue;}
        int m=1;divisorSet.clear();k=n;
        while(k>1){++m;if(primes[m]&&(k%m==0)){divisorSet.insert(m);while(k%m==0){k /=m;}}}

        if(divisorSet.size()==requestedFactors){
            if(lastNumber<n-1){count=0;}
            ++count;lastNumber=n;
            if(count>=requestedFactors){cout << "Done! "<< n-3<<endl; break;}
        }
        else {count=0;};
    }
}

int main (int argc, char * const argv[]) {
    distinctPrimeFactors(1000000);
    return 0;
}
