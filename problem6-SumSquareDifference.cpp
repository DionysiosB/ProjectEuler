#include <iostream>
#include <cmath>
using namespace std;

int sumOfSquares(int n){
	return n*(n+1)*(2*n+1)/6;
}
int squareOfSum(int n){
	return pow((n*(n+1)/2.0),2);
}

int squaresDiff(int n){
	return squareOfSum(n)-sumOfSquares(n);
}



int main (int argc, char * const argv[]) {
	
	cout << endl<< squaresDiff(100)<< endl;
    
	
	return 0;
}