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
    int data[dim][dim]={0},score[dim][dim]={0},step[dim][dim]={0};  
    ifstream inputFile("matrix.txt");
    if(inputFile){
        while(getline(inputFile,currentLine)){
            istringstream buf(currentLine);
            while(getline(buf,temp,',')){data[row][col++]=atoi(temp.c_str());}
            row++;col=0;
        }
    }
//    for(int k=0;k<dim;++k){for(int m=0;m<dim;++m){cout << data[k][m]<<"  ";};cout <<endl;};cout<<endl<<endl;

    long largeInt=10000000;
    for(int k=0;k<dim;++k){for(int m=0;m<dim;++m){score[k][m]=largeInt;step[k][m]=-1;}}
    score[0][0]=data[0][0];step[0][0]=0;

    for(int currentStep=0;currentStep<dim*dim;currentStep++){
        for(int row=0;row<dim;row++){
            for(int col=0;col<dim;col++){

                if(row>0 && step[row-1][col]==currentStep){
                    step[row][col]=currentStep+1;score[row][col]=min(score[row-1][col]+data[row][col],score[row][col]);}

                if(row<dim-1 && step[row+1][col]==currentStep){
                    step[row][col]=currentStep+1;score[row][col]=min(score[row+1][col]+data[row][col],score[row][col]);}

                if(col>0 && step[row][col-1]==currentStep){
                    step[row][col]=currentStep+1;score[row][col]=min(score[row][col-1]+data[row][col],score[row][col]);}

                if(col<dim-1 && step[row][col+1]==currentStep){
                    step[row][col]=currentStep+1;score[row][col]=min(score[row][col+1]+data[row][col],score[row][col]);}
    		}
    	}
    }
    return score[dim-1][dim-1];
}

int main (int argc, char * const argv[]) {
    cout << minPath() <<endl;
	return 0;
}
