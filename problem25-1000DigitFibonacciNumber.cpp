#include <iostream>
#include <cmath>
#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;


int largeFib(int numDigits){
	
	int x[numDigits];int y[numDigits];int temp[numDigits];
	int digit;int counter;int dummy;
	for(digit=1;digit<numDigits;++digit){
		x[digit]=0;y[digit]=0;temp[digit]=0;
	}
	x[0]=y[0]=1;
	
	counter=2;
	while(y[numDigits-1]==0){
		++counter;
		for(digit=numDigits-2;digit>=0;--digit) {
			temp[digit]=x[digit];x[digit]=y[digit];
			dummy=y[digit]+temp[digit];
			y[digit]=dummy%10;
			y[digit+1]+=dummy/10;
		}
		
		//cout << counter<< "   ";
		//for(digit=numDigits-1;digit>=0;--digit) cout << y[digit];cout <<endl;
	}
	
	return counter;
}






int main (int argc, char * const argv[]) {
	
	cout <<endl << largeFib(1000)<<endl;
	
	return 0;
}
