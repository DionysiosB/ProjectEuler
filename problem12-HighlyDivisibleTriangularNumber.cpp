#include <iostream>
#include <cmath>
#include <vector>
#include <iostream>
#include <fstream>
using namespace std;


int countDivisors(int n){
	int counter=0;
	for(int k=1;k<=sqrt(n);++k)
		if(n%k==0) counter+=2;
	if(int(sqrt(n))*int(sqrt(n))==n) counter--;
	return counter;
	
}

int triDivisors(int n){
	
	int currentNumber=0;
	int currentTriangle=0;
	int numDiv=0;
	int currentMax=0;
	
	while(numDiv<=n){
		currentNumber++;
		currentTriangle=currentNumber*(currentNumber+1)/2;
		numDiv=countDivisors(currentTriangle);
		
		if(numDiv>=currentMax){
			currentMax=numDiv;
			//cout << currentTriangle << "   " << numDiv <<endl;
		}
		
	}
	
	return currentTriangle;
	
}



int main (int argc, char * const argv[]) {
	
	
	 cout << endl<< triDivisors(500)<< endl;
	 
	 
	 return 0;
}


