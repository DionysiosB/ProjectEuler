#include <iostream>
#include <cmath>
using namespace std;

unsigned long selfPowerLSB(unsigned n,unsigned long d){
    
    unsigned long output=1;
    for(unsigned k=0;k<n;++k){output=(output*n)%d;}
    return output;
}

int main (int argc, char * const argv[]) {
    
    unsigned long output;
    unsigned long upperBound=10000000000;
    for(int k=1;k<=1000;++k){
        cout << selfPowerLSB(k,upperBound)<<endl;
        output+=selfPowerLSB(k,upperBound);
    }
    output=output%upperBound;
    cout<<"The sum is: "<< output<<endl;
	
	return 0;
}
