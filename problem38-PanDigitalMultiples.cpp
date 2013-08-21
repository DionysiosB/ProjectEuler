#include <iostream>
#include <cmath>
#include <set>
using namespace std;

long concatenateNums(int x,int y){
    int order=1;
    while(y/order>0){order*=10;}
    return (order*x+y);
}

bool isPandigital(int x){
    if(!(x/100000000>=1 && x/100000000<=9)){return 0;}
    long testP=1;int testS=0;
    for(int k=0;k<9;++k){testP *= (x%10);testS+=(x%10);x /=10;}
    return (testS== 1+2+3+4+5+6+7+8+9 && testP == 9*8*7*6*5*4*3*2*1);
}

long findMaxPandigital(){

    const int upperBound=10000;const long minPandigital=123456789;
    long maxPandigital=minPandigital;
    long output=0;int nextMult=0;
    for(int x=1;x<upperBound;++x){
        output=concatenateNums(x,2*x);
        nextMult=3;
        while(output<=minPandigital){
            output=concatenateNums(output,nextMult*x);
            ++nextMult;
        }
        if(isPandigital(output) && output>maxPandigital){
            maxPandigital=output;cout <<x<< "  ---->" << output<<endl;}
    }
    return output;
}




int main (int argc, char * const argv[]) {
   
    findMaxPandigital();
    return 0;
}
