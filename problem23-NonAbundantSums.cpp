#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int numberAbundance(int n){

    vector<int> divisors;
    if(n>1){divisors.push_back(1);}
    int root=int(sqrt(n));if(root*root==n) {divisors.push_back(root);}
    for(int k=2;k<sqrt(n);++k){if(n%k==0){divisors.push_back(k);divisors.push_back(n/k);}}
    
    int divisorSum=0;
    for(int k=0;k<divisors.size();++k){divisorSum+=divisors[k];}
    if(divisorSum<n){return -1;}
    else if (divisorSum>n){return 1;}
    else {return 0;}

}

long nonAbundantSum(int upperBound){

    bool nonAbundantSum;long total=0;
    for(int n=1;n<=upperBound;++n){
        nonAbundantSum=1;
        for(int k=1;k<=n/2;++k){if(numberAbundance(k)==1 && numberAbundance(n-k)==1){nonAbundantSum=0;break;}}
        if(nonAbundantSum){total+=n;}
    }
    return total;
}

int main (int argc, char * const argv[]) {
    cout<<endl<<nonAbundantSum(30000)<<endl;
	return 0;
}
