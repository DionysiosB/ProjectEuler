#include <iostream>
#include <cmath>
using namespace std;

bool reverseAddCheck(long n){

    long totalOrder=1;
    while(n/(10*totalOrder)>0){totalOrder *=10;}
    long currentOrder=1;long output=0;
    while(n>0){output+=(n%10)*(totalOrder/currentOrder+currentOrder);n /=10;currentOrder*=10;}
    bool isOdd=1;
    while(output>0){if( (output%10)%2==0 ){isOdd=0;break;} output /=10; }
    return isOdd;
}

int main (int argc, char * const argv[]) {
   
    long count=0;
    for(long k=1;k<1000000000;++k){
        //if(k%10000000==0){cout << k/10000000 <<endl;}
        if(reverseAddCheck(k) && k%10>0){++count;}}
    cout << "Total: "<<count<<endl;
	return 0;
}
