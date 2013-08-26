#include <iostream>
using namespace std;

int countTiles(){
    
    const int upperBound=50;
    long long dataRed[upperBound+1]={0},dataGreen[upperBound+1]={0},dataBlue[upperBound+1]={0};

    dataRed[0]=1;dataRed[1]=1;
    for(int n=2;n<=upperBound;n++){dataRed[n]=dataRed[n-1]+dataRed[n-2];}

    dataGreen[0]=1;dataGreen[1]=1;dataGreen[2]=1;
    for(int n=3;n<=upperBound;n++){dataGreen[n]=dataGreen[n-1]+dataGreen[n-3];}

    dataBlue[0]=1;dataBlue[1]=1;dataBlue[2]=1;dataBlue[3]=1;
    for(int n=4;n<=upperBound;n++){dataBlue[n]=dataBlue[n-1]+dataBlue[n-4];}

    long output=(dataRed[upperBound]-1)+(dataGreen[upperBound]-1)+(dataBlue[upperBound]-1);
    cout <<"Result: "<< output <<endl;
    return output;
}

int main (int argc, char * const argv[]) {
    countTiles();
}
