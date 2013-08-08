#include <iostream>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

vector<int> findCircular(unsigned n){

    int order=1;
    while(n/(10*order)){order *=10;};

    vector<int> output;
    int temp=n;
    do{
        temp=order*(temp%10)+(temp/10);
        output.push_back(temp);
    }while(temp !=n);

    return output;
}

unsigned findCircularPrimes(unsigned n){

    //Find Primes First;
    bool primes[n+1];bool circFlag;
    int total=0;
    primes[0]=0;primes[1]=0;primes[2]=1;
    for(int k=3;k<=n;++k){primes[k]=1;}
    for(int k=1;k<=sqrt(n);++k){if(primes[k]==1){for(int m=2;m<=(n/k);++m){primes[m*k]=0;}}}
    for(int k=2;k<=n;++k){
        if(primes[k]==1){
            circFlag=1;
            vector<int> candidate=findCircular(k);
            for(int m=0;m<candidate.size();++m){if(!primes[candidate[m]]){circFlag=0;}}
            if(circFlag){++total;cout << k<<endl;};
        }
    }
    cout << endl<<endl<<"Total: "<<total<<endl;

}
            
int main (int argc, char * const argv[]) {
	findCircularPrimes(1000000);
	return 0;
}
