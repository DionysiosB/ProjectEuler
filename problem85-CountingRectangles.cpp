#include <iostream>
#include <cmath>
using namespace std;

int countingRectangles(){
    
    const long target=2000000;
    const long sideLimit=target;
    long total,minDistance=target;
    int xt=0,yt=0;

    for(long x=1;x<=sqrt(sideLimit);x++){
        for(long y=x;y<=sqrt(sideLimit);y++){
            total=(x*(x+1)/2)*(y*(y+1)/2);
            if(total>target+minDistance){break;}
            if(abs(total-target)<minDistance){minDistance=abs(total-target);xt=x;yt=y;}
        }
    }
    return xt*yt;
}

int main (){cout << countingRectangles() << endl;}
