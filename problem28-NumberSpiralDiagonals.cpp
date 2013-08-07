#include <iostream>
using namespace std;

int main (int argc, char * const argv[]) {

    int length=500;
    
    unsigned long long total;
    for(unsigned n=1;n<=length;++n){
        total+=(2*n+1)*(2*n+1);     //Upper Right
        total+=4*n*n-2*n+1;         //Lower Right
        total+=4*n*n+1;             //Lower Left
        total+=4*n*n+2*n+1;         //Upper Left
        // total+=16*n*n+4;  // All in one;
    }
    ++total;
    cout << total<<endl;
    
	return 0;
}
