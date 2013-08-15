#include <iostream>
#include <cmath>
#include <set>
using namespace std;

long chooseFunction(int n,int r){
    if(r>n){return 0;}
    long long nom=1,den=1;
    for(int k=1;k<=r;++k){nom *= n-k+1;den *=k;}
    return nom/den;
}

long findSmallChoose(int upperBound,int cutoff){

    long total=0;
    for(int n=1;n<=upperBound;++n){
        for(int r=1;r<n/2;++r){if(chooseFunction(n,r)> cutoff){total+=(n-2*r+1);break;}}
    }
    return total;
}

int main (int argc, char * const argv[]) {
    cout<< findSmallChoose(100,1000000)<<endl;
	return 0;
}
