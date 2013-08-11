#include <iostream>
#include <cmath>
using namespace std;

int coinValues[]={1,2,5,10,20,50,100,200};

int coinSums(int totalValue,int maxCoinIndex){

    if(maxCoinIndex==0 || totalValue==0){return 1;}
    int maxCoin=coinValues[maxCoinIndex]; int total=0;
    for(int k=0;k<=totalValue/maxCoin;++k){total+=coinSums(totalValue-k*maxCoin,maxCoinIndex-1);}
    return total;
}

int main (int argc, char * const argv[]) {
    cout << coinSums(200,7)<<endl;
	return 0;
}
