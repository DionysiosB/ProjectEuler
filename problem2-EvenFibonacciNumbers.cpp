#include <iostream>
#include <cmath>
using namespace std;

int fibonacciSequence(int n){
	
	double phi=(1+sqrt(5))/2;
	double psi=(1-sqrt(5))/2;
	return round((pow(phi,n)-pow(psi,n))/sqrt(5));
}

int evenSumFib(int upperBound){
	
	int cumsum=0;
	int n=1;
	int temp=0;
	while(true){
		temp=fibonacciSequence(3*(n++));
		cout << temp << "   ";
		if(temp>=upperBound)	break;
		cumsum+=temp;
		cout << cumsum << "   " <<endl;

	}
	
	return cumsum;
}
		
	
	

int main (int argc, char * const argv[]) {
	
	cout << endl<< evenSumFib(4000000)<< endl;
    
	
	return 0;
}