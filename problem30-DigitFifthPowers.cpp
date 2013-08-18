#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

vector<int> findDigits(int n){
    vector<int> output;
    while(n>0){output.push_back(n%10);n /=10;}
    return output;
}

int fifthPowerSum(int n){
    int total=0;vector<int> digits=findDigits(n);
    for(int k=0;k<digits.size();++k){total+=int( pow(1.0*digits[k],5) );}
    return total;
}

int main (int argc, char * const argv[]) {

    int upperBound=500000;
    int total=0;
    for(int k=3;k<=upperBound;++k){
        if(k==fifthPowerSum(k)){cout << k<< endl; total+=k;}
    }
    cout <<"Total: "<< total<<endl;
    return 0;
}
