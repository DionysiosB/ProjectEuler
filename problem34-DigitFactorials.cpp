#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

vector<int> findDigits(int n){
    vector<int> output;
    while(n>0){output.push_back(n%10);n /=10;}
    return output;
}

int digitFactorial(int n){
    if(n==0){return 1;}
    int output=1;while(n>1){output *=(n--);}
    return output;
}

int factorialSum(int n){
    int total=0;vector<int> digits=findDigits(n);
    for(int k=0;k<digits.size();++k){total+=digitFactorial(digits[k]);}
    return total;
}

int main (int argc, char * const argv[]) {

    int upperBound=3000000;
    int total=0;
    for(int k=3;k<=upperBound;++k){
        if(k==factorialSum(k)){cout << k<< endl; total+=k;}
    }
    cout <<"Total: "<< total<<endl;


    return 0;
}
