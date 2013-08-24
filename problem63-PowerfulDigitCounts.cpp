#include <iostream>
#include <cmath>
using namespace std;

int powerfulDigitCounts(){

    double currentProduct=1,currentOrder=1;
    int count=0;
    for(int k=1;k<=9;++k){
        currentProduct=k;currentOrder=1;
        do{++count;currentProduct *=k;currentOrder *=10;}while(currentProduct/currentOrder>=1.0);
    }
    cout<<"Total: "<<count<< endl;
    return count;
}

int main (int argc, char * const argv[]) {
	powerfulDigitCounts();
}

