#include <iostream>
#include <cmath>
#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

unsigned long gridPaths(int n){
	
	unsigned long matrix[n+1][n+1];
	int counter;
	for(counter=0;counter<=n;counter++){
		matrix[counter][0]=1;
		matrix[0][counter]=1;
	}
	
	for(int row=1;row<=n;++row){
		for(int col=1;col<=row;++col){
			matrix[row][col]=matrix[row-1][col]+matrix[row][col-1];
			matrix[col][row]=matrix[row-1][col]+matrix[row][col-1];
		}
	}
	
	/*
	for(int row=0;row<=n;++row){
		for(int col=0;col<=n;++col){
			cout << row<< "   "<< col << "   Steps:" << matrix[row][col]<<endl; 
		}
	}
	*/
	
	return matrix[n][n];
	
	
}



int main (int argc, char * const argv[]) {
	
	cout <<endl << gridPaths(20)<<endl;
	
	return 0;
}
