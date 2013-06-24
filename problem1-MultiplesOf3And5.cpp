#include <iostream>
using namespace std;

int seriesSum(int x){
	return x*(x+1)/2;
}

int multiplesSumA(int x, int y, int UpperBound){
	int temp = UpperBound-1;
	return x*seriesSum(temp/x)+y*seriesSum(temp/y)-x*y*seriesSum(temp/(x*y));
}

int main (int argc, char * const argv[]) {
	
	cout << endl << multiplesSumA(3,5,1000)<< endl;
    
	
	return 0;
}
