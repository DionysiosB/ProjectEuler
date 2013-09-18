#include <iostream>
using namespace std;
long long  squareRemainders(int n){
    long long output=0;
    for(int a=3;a<=n;a++){output+=2*a*((a-1)/2);}
    return output;
}

int main(){cout<< squareRemainders(1000)<<endl;}
