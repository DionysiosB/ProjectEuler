#include <iostream>
#include <cmath>
using namespace std;

void checkPolygonNumbers(unsigned long upperBound){

    for(unsigned long x=0;x<upperBound;++x){

        unsigned long n=0;
        n=int(sqrt(2*x));
        if(n*(n+1)!=2*x){continue;}
        
        n=1+int(sqrt(2.0*x/3));
        if(n*(3*n-1) != 2*x){continue;}

        n=1+int(sqrt(1.0*x/2));
        if( n*(2*n-1) != x){continue;}

        cout << x <<endl;
    }
}



int main (int argc, char * const argv[]) {
    checkPolygonNumbers(4000000000);
	return 0;
}
