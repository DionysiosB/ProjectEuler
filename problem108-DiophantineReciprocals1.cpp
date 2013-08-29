#include <iostream>
#include <fstream>
#include <sstream>
#include <cmath>
#include <stdlib.h>
using namespace std;

int diophantineReciprocals(){
    unsigned long long upperBound=1000000;

    int count=0,maxCount=0;
    unsigned long long y=1;
    for(unsigned long long n=1;n<=upperBound;++n){
        count =0;
        for(unsigned long long x=n+1;x<=2*n;x++){
            y=n*x/(x-n);
            if(n*(x+y)==x*y){++count;}
        }
        if(count >=1000){cout << "Answer: "<<n<<endl;break;}
    }
    return 0;
}

int main (int argc, char * const argv[]) {
    diophantineReciprocals();
	return 0;
}
