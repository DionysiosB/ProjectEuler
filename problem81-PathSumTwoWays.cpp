#include <iostream>
#include <fstream>
#include <sstream>
#include <cmath>
#include <stdlib.h>
using namespace std;

long minPath(){

    const int dim=80;
    string currentLine;int row=0,col=0;
    string temp;
    int data[dim][dim],scores[dim][dim];
    ifstream inputFile("matrix.txt");
    if(inputFile){
        while(getline(inputFile,currentLine)){
            istringstream buf(currentLine);
            while(getline(buf,temp,',')){data[row][col++]=atoi(temp.c_str());}
            row++;col=0;
        }
    }
    
    //for(int k=0;k<dim;++k){cout << endl;for(int m=0;m<dim;++m){cout << data[k][m]<<"  ";}};cout <<endl;

    scores[0][0]=data[0][0];
    for(int k=1;k<dim;++k){scores[0][k]=scores[0][k-1]+data[0][k];}
    for(int k=1;k<dim;++k){scores[k][0]=scores[k-1][0]+data[k][0];}
    for(int k=1;k<dim;++k){
        for(int m=1;m<dim;++m){
            scores[k][m]=data[k][m]+min(scores[k-1][m],scores[k][m-1]);
        }
    }

    //for(int k=0;k<dim;++k){cout << endl;for(int m=0;m<dim;++m){cout <<scores[k][m]<<"  ";}};cout <<endl;
    
    return scores[dim-1][dim-1];


}

int main (int argc, char * const argv[]) {
    cout << minPath() <<endl;
	return 0;
}
