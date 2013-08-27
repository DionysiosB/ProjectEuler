#include <iostream>
using namespace std;

int countTiles(){
    
    const int upperBound=1000,minLength=50,target=1000000;
    long data[upperBound+1]={0};for(int k=0;k<minLength;k++){data[k]=1;}

    int firstInstance=0;
    for(int n=minLength;n<=upperBound;n++){
        data[n]=1+data[n-1];
        for(int m=minLength;m<=n-1;++m){data[n]+=data[n-1-m];}
        if(data[n]>target){firstInstance=n;break;}
    }

    cout <<"Result: "<< firstInstance <<endl;
    return firstInstance;
}

int main (int argc, char * const argv[]) {
    countTiles();
}
