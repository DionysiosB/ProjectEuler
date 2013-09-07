#include <iostream>
#include <cmath>
using namespace std;

long long arrangedProbability(long long upperBound) {
    long long x=15,a=21,xnew=15,anew=21;
    while(a<upperBound){
        xnew=3*x+2*a-2;
        anew=4*x+3*a-3;
        a=anew;x=xnew;
    }
    return x;
}

int main(){cout<< arrangedProbability(1000000000000)<<endl;}
