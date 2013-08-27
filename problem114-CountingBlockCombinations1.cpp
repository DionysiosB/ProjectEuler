#include <iostream>
using namespace std;

int countTiles(){
    
    const int upperBound=50;
    long data[upperBound+1]={0};

    data[0]=1;data[1]=1;data[2]=1;
    for(int n=3;n<=upperBound;n++){data[n]=1+data[n-1];for(int m=3;m<=n-1;++m){data[n]+=data[n-1-m];}}
    cout <<"Result: "<< data[upperBound] <<endl;
    return data[upperBound];
}

int main (int argc, char * const argv[]) {
    countTiles();
}
