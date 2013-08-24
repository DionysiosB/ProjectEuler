#include <iostream>
#include <cmath>
using namespace std;

int addSquareDigits(int x){
    int output=0;
    while(x>0){output+=(x%10)*(x%10);x /=10;}
    return output;
}

int squareDigitChains(long upperBound){
    long count=0;int temp=0;
    for(int k=1;k<upperBound;k++){
        temp=k;
        do{temp=addSquareDigits(temp);if(temp==89){++count;}}while(temp !=89 && temp !=1);
    }
    cout << "Total: "<< count <<endl;
    return count;
}

int main (int argc, char * const argv[]) {
    squareDigitChains(10000000);
}

