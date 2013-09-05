#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
const int upperBound=10000000;

long findLargestDivisible(int p,int q,int n){
    if(p*q>n){return 0;}
    int maxP=1,maxQ=1;long temp=0,output=0;
    maxP=1+int(log(1.0*n/q)/log(p));maxQ=1+int(log(1.0*n/p)/log(q));

    for(int powerP=1;powerP<=maxP;powerP++){
        for(int powerQ=1;powerQ<=maxQ;powerQ++){
            temp=int(pow(1.0*p,powerP)*pow(1.0*q,powerQ));
            if(temp>output && temp<=n){output=temp;}
        }
    }
    return output;
}

long twoPrimeDivisibleSum(){

    bool *primes=new bool[upperBound];vector<int> primesVector;long output=0;

    primes[0]=0;primes[1]=0;for(int k=2;k<=upperBound;k++){primes[k]=1;}
    for(int k=2;k<=sqrt(upperBound);k++){if(!primes[k]){continue;};for(int m=2;m<=upperBound/k;m++){primes[m*k]=0;}}
    for(int k=0;k<=upperBound;k++){if(primes[k]){primesVector.push_back(k);}}
    delete[] primes;

    for(unsigned k=0;k<primesVector.size()-1;k++){
        if(primesVector[k]>sqrt(upperBound)){break;}
        for(unsigned m=k+1;m<primesVector.size();m++){
            if(primesVector[k]*primesVector[m]>upperBound){break;}
            output+=findLargestDivisible(primesVector[k],primesVector[m],upperBound);
        }
    }
    return output;
}

int main (){cout << twoPrimeDivisibleSum()<<endl;}