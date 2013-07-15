#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int nthPrime(int n){
	
	int counter=1;
	int output=2;
	
	vector<int> primesList;primesList.push_back(2);
	vector<int>::iterator primeIter;
	
	for (int currentNumber = 3; counter<=n; currentNumber+=2) {
		bool isPrime=1;
		
		for ( primeIter= primesList.begin(); primeIter != primesList.end() ; primeIter++) {
			if (currentNumber % (*primeIter) == 0) {
				isPrime=0;
				break;
			}
		}
		
		if (isPrime) {
			primesList.push_back(currentNumber);
			counter++;
			//cout << counter << "---> " << currentNumber <<endl;
			if (counter==n) return currentNumber;
		}
		
	}
	 
	 
	 return output;
	 
	 
	 }
	 
	 int main (int argc, char * const argv[]) {
	 cout << endl<< nthPrime(10)<< endl;
	 
	 
	 return 0;
	 }