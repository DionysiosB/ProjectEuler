#include <iostream>
#include <cmath>
using namespace std;

unsigned long long perfectSquareCollection(unsigned long upperBound){

    unsigned long d,f,g,dsquare,fsquare,gsquare;
    for(unsigned long a=1;a<upperBound;a++){
        for(unsigned long c=1;c<a;c++){
            int bstart= a%2==1 ? 1:2;
            for(unsigned long b=bstart;b<c;b+=2){
                dsquare=a*a+b*b-c*c;d=int(sqrt(dsquare));
                fsquare=c*c-b*b;f=int(sqrt(fsquare));
                gsquare=a*a-c*c;g=int(sqrt(gsquare));
                if(dsquare==d*d && fsquare==f*f && gsquare==g*g && c*c>d*d){return a*a+(c*c-dsquare)/2;}
            } 
        }
    }
    return 0;
}

int main () {
	cout << perfectSquareCollection(1000) <<endl;
}
