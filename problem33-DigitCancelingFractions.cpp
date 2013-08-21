#include <iostream>
#include <cmath>
#include <set>
using namespace std;

bool checkDigitCanceling(int nom, int den){
   
    if(nom%10==0 || den%10==0){return 0;} //trivial example;
    
    if((nom/10) == (den/10) && (nom*(den%10)== den*(nom%10))  ){return 1;}
    if((nom/10) == (den%10) && (nom*(den/10)== den*(nom%10))  ){return 1;}
    if((nom%10) == (den/10) && (nom*(den%10)== den*(nom/10))  ){return 1;}
    if((nom%10) == (den%10) && (nom*(den/10)== den*(nom/10))  ){return 1;}
    
    return 0;
}

int main (int argc, char * const argv[]) {
   
    for(int a=11;a<99;++a){for(int b=a+1;b<=99;++b){if(checkDigitCanceling(a,b)){cout<<a<<" "<<b<<endl;}}}
    return 0;
}
