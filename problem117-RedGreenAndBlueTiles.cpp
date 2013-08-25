#include <iostream>
using namespace std;

int countTiles(){
    
    const int upperBound=50;
    long long data[upperBound+1]={0};
    data[0]=1;
    for(int n=1;n<=upperBound;n++){for(int m=1;m<=min(4,n);m++){data[n]+=data[n-m];}}
    cout <<"Result: "<< data[upperBound]<<endl;
    return data[upperBound];
}

int main (int argc, char * const argv[]) {
    countTiles();
}
