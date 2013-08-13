#include <iostream>
#include <set>
using namespace std;

multiset<int> findDigits(long n){
    multiset<int> output;
    while(n>0){output.insert(n%10);n /=10;}
    return output;
}

long permutedMultiples(long upperBound){

    bool sameDigits=0;const int maxMultiple=6;multiset<int> currentDigits;
    for(long n=1;n<=upperBound;++n){
        currentDigits=findDigits(n);
        sameDigits=1;
        for(int k=2;k<=maxMultiple;++k){if(currentDigits != findDigits(k*n)){sameDigits=0;break;}}
        if(sameDigits){return n;}
    }
    return 0;
}

int main (int argc, char * const argv[]) {
    cout << permutedMultiples(1000000)<<endl;
	return 0;
}
