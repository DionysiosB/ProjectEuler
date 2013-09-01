#include <iostream>
#include <cmath>
using namespace std;

int gcd(int x,int y){
    if(min(x,y)==0){return max(x,y);}
    while(x>0 && y>0){if(x>y){x %=y;}else{y %=x;}}
    return max(x,y);
}


int countingFractionsInRange(){
    const int upperBound=12000;

    long count=0;
    for(int n=2;n<=upperBound/2;n++){
        for(int d=2*n;d<=min(3*n,upperBound);d++){
            if( gcd(n,d)==1) {++count;}
        }
    }
    cout << "Result: " <<count<<endl;
    return count;
}


int main (int argc, char * const argv[]) {
    countingFractionsInRange();
}
