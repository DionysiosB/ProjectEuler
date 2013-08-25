#include <iostream>
#include <cmath>
using namespace std;

int countSummations(){
    const int upperBound=100;
    long long data[upperBound+1][upperBound+1]={0};

    for(int col=1;col<=upperBound;++col){
        for(int row=1;row<=col/2;++row){
            data[row][col]=col/2-row+1;for(int x=row;x<col;++x){data[row][col]+=data[x][col-x];}
        }
    }

    for(int col=2;col<=upperBound;++col){cout << data[1][col]<<" ";}
    cout <<endl<<"Output: "<< data[1][upperBound]<<endl;
}

int main (int argc, char * const argv[]) {
    countSummations();
}
