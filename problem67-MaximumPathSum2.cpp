#include <iostream>
#include <cmath>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

int findOptimal() {
	
	int temp,row,col,finalRow,maxSum;
	int maxRows=150;int matrix[maxRows][maxRows];
	
	ifstream inputFile ("inputFile.txt");	
	row=0;col=0;
	while (inputFile >> temp){
		if(col>row){row++;col=0;}
		matrix[row][col++]=temp;
	}
	inputFile.close();
	
	finalRow=row;
	int score[finalRow+1][finalRow+1];
	score[0][0]=matrix[0][0];
	
	maxSum=score[0][0];
	for(row=1;row<=finalRow;++row){
		for(col=0;col<=row;++col){
			score[row][col]=matrix[row][col]+max(score[row-1][max(0,col-1)],score[row-1][min(row-1,col)]);
			if(score[row][col]>maxSum) maxSum=score[row][col];
		}
	}
	return maxSum;
}	


int main (int argc, char * const argv[]) {
	 
	cout << findOptimal()<< endl;
	 
	 return 0;
}
