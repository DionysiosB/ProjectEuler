#include <iostream>
#include <cmath>
using namespace std;

long findPentagon(int n){return n*(3*n-1)/2;}

bool checkPentagon(long a){
    int n=int(sqrt(2.0*a/3.0))+1;
    return (n*(3*n-1)==2*a);
}

void minPentagonDiff(int upperBound){
    
    bool found =0; long b;
    for(int diff=1;diff<upperBound;++diff){
        for(int a=1;a<upperBound;a++){
            b=a+diff;
            if(checkPentagon(findPentagon(b)-findPentagon(a)) && checkPentagon(findPentagon(b)+findPentagon(a)) )
                {cout<<findPentagon(b)-findPentagon(a)<<endl;found = 1;break;}
        }
        if(found){break;}
    }
}

int main (int argc, char * const argv[]) {
    minPentagonDiff(10000);
}

