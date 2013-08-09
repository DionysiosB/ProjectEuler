#include <iostream>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

bool isPalindrome(int n,int base){
    int order=1;
    while(n/(base*order)>0){order *=base;}

    bool output=1;
    while(n>0){
        if(n/order != n%base){output=0;break;}
        else{n=n-(n/order)*order;n=n/base;order=order/(base*base);}
    }
    return output;

}




int main (int argc, char * const argv[]) {

    int total=0;
	for(int x=0;x<1000000;++x){if(isPalindrome(x,10)&& isPalindrome(x,2)){total+=x;cout<< x<<endl;}}
    cout << "Grand Sum: "<< total<<endl;
	return 0;
}
