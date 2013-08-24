#include <iostream>
#include <cmath>
using namespace std;

bool sameLength(double x, double y){
    double a=max(x,y),b=min(x,y);
    while(b>1){a /=10; b /=10;}
    if(a>1){return 0;} else{return 1;}
}

int rootSequence(int upperBound){

    double p=1,q=1,newP=1,newQ=1;
    double largeConstant=pow(10.0,100);
    int count=0;
    for(int k=1;k<upperBound;k++){
        newP=p+2*q; newQ=p+q;
        p=newP;q=newQ;
        if(p>largeConstant){p /=10; q/=10;}
        if(!sameLength(p,q)){++count;}
    }
    cout << "Total: "<<count<<endl;
    return count;
}

int main (int argc, char * const argv[]) {
    rootSequence(1000);
}

