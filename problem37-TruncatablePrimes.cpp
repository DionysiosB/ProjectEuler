#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

vector<int> generateChoppedPrimes(unsigned long p){

    vector<int> digits,output;
    while(p>0){digits.push_back(p%10);p /=10;}
    
    int temp=0;
    for(int k=digits.size()-1;k>=0;--k){temp=10*temp+digits[k];output.push_back(temp);}
    for(int k=0;k<digits.size();++k){
        temp=0;for(int m=k;m>=0;--m){temp=10*temp+digits[m];}
        output.push_back(temp);
    }
    return output;
}

int truncatablePrimes(unsigned long upperBound){

    int total=0;
    bool primes[upperBound+1];primes[0]=0;primes[1]=0;
    for(unsigned long k=2;k<=upperBound;++k){primes[k]=1;}
    for(unsigned long k=2;k<=sqrt(upperBound);++k){
        if(primes[k]==1){for(unsigned long m=2;m<=upperBound/k;++m){primes[k*m]=0;}}
    }

    vector<int> related;bool flag=0;
    for(unsigned long k=10;k<=upperBound;++k){
        if(primes[k]){
            related=generateChoppedPrimes(k);
            flag=1;
            for(int m=0;m<related.size();++m){if(!primes[related[m]]){flag=0;}}
            if(flag){cout << k<< endl; total+=k;}
        }
    }
    return total;
}

int main (int argc, char * const argv[]) {
    cout << truncatablePrimes(1000000)<<endl;
	return 0;
}
