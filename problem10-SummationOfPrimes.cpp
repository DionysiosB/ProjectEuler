#include <iostream>
#include <cmath>
#include <vector>
#include <iostream>
#include <fstream>
using namespace std;

int primeSum(unsigned long int n){
	
	unsigned long long totalSum=0;
	bool primesList[n+1];
	for (int k=0; k<n; k++) primesList[k]=true;
	primesList[0]=false;primesList[1]=false;primesList[2]=true;primesList[3]=true;
	
	for (int k=2; k<=n; k++) {
		if (primesList[k]==true) {
			for (int m=2; m<=n/k; m++) {
				primesList[m*k]=false;
			}
		}
	}
	
	 
	ofstream myfile;
	myfile.open ("testOutput.txt");
	
	int numsum=0;
	for (int k=0; k<=n; k++) {
		if(primesList[k]){
			//cout << k << "  ";
			totalSum+=k;
			numsum++;
		}
	}
	myfile.close();
	
	cout << numsum;
	 return totalSum;
}


int main (int argc, char * const argv[]) {
	 cout << endl<< primeSum(2000000)<< endl;
	 
	 
	 return 0;
}
