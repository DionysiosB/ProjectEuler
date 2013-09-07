#include <iostream>
using namespace std;

bool checkSquare(unsigned long input){
    unsigned long long square=input*input;
    int count=9;
    for(int count=9;count>0;count--){if(square%10 != count){return 0;};square /=100;}
    return 1;
}

unsigned long concealedSquare(){
    for(unsigned long k=40000000;k<=49999999;k++){
        if(k%10 !=3 && k%10 != 7){continue;}
        if(checkSquare(k)){return 10*k;}
    }
    for(unsigned long k=100000000;k<=199999999;k++){
        if(k%10 !=3 && k%10 != 7){continue;}
        if(checkSquare(k)){return 10*k;}
    }
    return 0;
}

int main (){cout << concealedSquare()<<endl;}
