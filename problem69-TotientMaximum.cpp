#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int gcd(int a, int b){
    while(a>0 && b>0){if(a>b){a=a%b;}else{b=b%a;}}
    if(a==0){return b;}else {return a;}
}

int phiFunction(int n){
    int count=0;
    //for(int k=1;k<n;++k){if(gcd(k,n)==1){++count;}}
    //return count;
    bool primes[n];for(int k=1;k<n;++k){primes[k]=1;}
    for(int k=1;k<=n/2;++k){if(gcd(k,n)>1){for(int m=1;m<n/k;++m){primes[m*k]=0;}}}
    for(int k=1;k<n;++k){count+=primes[k];}//if(primes[k]) cout<<k<<endl;}
    return count;
}

int maxPhi(int upperBound){

    double currentRatio=0,maxRatio=0;
    int maxNum=0;
    for(int n=2;n<=upperBound;++n){
        if(n%17017 !=0){continue;} //Solved with Mathematica
        currentRatio=1.0*n/phiFunction(n);
        if(currentRatio > maxRatio){
            maxRatio=currentRatio;
            maxNum=n;
            cout << maxNum <<"   " << maxRatio<<endl;
        }
    }
    return maxNum;
}

int main (int argc, char * const argv[]) {
    
    //cout << phiFunction(1234) <<endl;
    cout <<endl<<endl<< maxPhi(1000000)<<endl;
	return 0;
}
