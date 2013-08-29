#include <iostream>
#include <cmath>
#include <set>
using namespace std;

int SquareFreeBinomialCoefficients(){

    const int upperBound=51;
    unsigned long long pascalTriangle[upperBound+1][upperBound+1]={0};
    pascalTriangle[1][1]=1;
    
    long long totalSum=0;
    long long temp=0;
    set<long long> squareFreeSet;bool squareFree=0;
    for(int row=2;row<=upperBound;row++){
        for(int col=1;col<=row;col++){
            temp =pascalTriangle[row-1][col]+pascalTriangle[row-1][col-1];
            pascalTriangle[row][col]=temp;
            squareFree=1;
            for(long long  k=2;k<=sqrt(temp);k++){if(temp%(k*k)==0){squareFree=0;break;}}
            if(squareFree){squareFreeSet.insert(temp);}
        }
    }
    for(set<long long>::iterator myIter=squareFreeSet.begin();myIter!=squareFreeSet.end();myIter++){totalSum+=(*myIter);}
    cout << "Result: "<< totalSum<<endl;
}

int main (int argc, char * const argv[]) {
    SquareFreeBinomialCoefficients();
}
