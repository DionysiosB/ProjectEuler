#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int largestPrimeB(unsigned long int n){
	
	int largestPrime=2;
	vector<int> factorsList;factorsList.push_back(2);
	vector<int>::iterator myIter;
	
	
	for (int currentNumber=3; currentNumber <= n ; ++currentNumber) {
		if( (n % currentNumber) == 0 ){
			bool isPrime=true;
			for (myIter=factorsList.begin(); myIter != factorsList.end(); ++myIter	) {
				if (currentNumber % (*myIter)==0) {
					isPrime=false;
					break;
				}
			}
			
			if (isPrime) {
				cout << "New Prime: "<<currentNumber <<endl;
				factorsList.push_back(currentNumber);
				largestPrime=currentNumber;
			}
		}
	}
	
	return largestPrime;
	
}

int main (int argc, char * const argv[]) {
	
	cout << endl<< largestPrimeB(600851475143)<< endl;
    
	
	return 0;
}

/*OLD SOLUTION

#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int largestPrimeA(unsigned long int n){
		
	vector<int> primesList;primesList.push_back(2);
	vector<int>::iterator primeIter;
	
	for (int currentNumber = 3; currentNumber<=n; currentNumber+=2) {
		bool isPrime=1;
		//cout << " ***"<< currentNumber;
		
		for ( primeIter= primesList.begin(); primeIter != primesList.end() ; primeIter++) {
			if (currentNumber % (*primeIter) == 0) {
				isPrime=0;
				break;
			}
		}
		
		if (isPrime) {
			primesList.push_back(currentNumber);
			cout << currentNumber << "  ";
		}
		
	}
	
	/*
	for ( primeIter= primesList.begin(); primeIter != primesList.end() ; primeIter++) {
		cout << (*primeIter)<< "  ";
	}

	
	vector<int>::reverse_iterator reverseIter;
	for (reverseIter= primesList.rbegin(); reverseIter != primesList.rend() ; ++reverseIter) {
		if (n % (*reverseIter)==0) return (*reverseIter);
	}
	
	return 0;
	

}

int main (int argc, char * const argv[]) {
	cout << endl<< largestPrimeA(607564)<< endl;
    
	
	return 0;
}
	*/