#include <iostream>
#include <fstream>
#include <sstream>
#include <cmath>
#include <stdlib.h>
using namespace std;

int sgn(int x){
    if(x<0){return -1;}
    else{return 1;}
}


long minPath(){

    const int dim=80;
    string currentLine;int row=0,col=0;
    string temp;
    int data[dim][dim]={0},scores[dim][dim]={0};
    ifstream inputFile("matrix.txt");
    if(inputFile){
        while(getline(inputFile,currentLine)){
            istringstream buf(currentLine);
            while(getline(buf,temp,',')){data[row][col++]=atoi(temp.c_str());}
            row++;col=0;
        }
    }
    for(int k=0;k<dim;++k){for(int m=0;m<dim;++m){cout << data[k][m]<<"  ";};cout <<endl;};cout<<endl<<endl;


    long largeInt=10000000;
    for(int k=0;k<dim;++k){for(int m=1;m<dim;++m){scores[k][m]=largeInt;}}
    for(int k=0;k<dim;++k){scores[k][0]=data[k][0];}

    int dummy=0;
    for(int col=1;col<dim;col++){
        for(int y=0;y<dim;y++){
            for(int x=0;x<dim;x++){
               dummy=scores[x][col-1];
               //cout <<"Col:"<<col<<"  x:"<<x<<"  y:"<<y<<endl;
               for(int curr=min(x,y);curr<=max(x,y);curr+=1){
                  // cout << "Curr:"<<curr<<endl;
                   dummy+=data[curr][col];}
               if(dummy<scores[y][col]){scores[y][col]=dummy;}
            }
        }
    }

    for(int k=0;k<dim;++k){for(int m=0;m<dim;++m){cout<<scores[k][m]<<"  ";};cout <<endl;}
    
    int output = largeInt;
    for(int row=0;row<dim;row++){if(scores[row][dim-1]<output){output=scores[row][dim-1];}}
    
    return output;


}

int main (int argc, char * const argv[]) {
    cout << minPath() <<endl;
	return 0;
}
