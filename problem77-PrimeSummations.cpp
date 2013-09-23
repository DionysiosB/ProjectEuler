#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

long primeSummations(int upperBound){

	int *primes=new int[upperBound+1];
	primes[0]=0;primes[1]=0;for(int k=2;k<=upperBound;k++){primes[k]=1;}
	for(int k=2;k<=sqrt(upperBound);k++){if(!primes[k]){continue;};for(int m=2;m<=upperBound;m++){primes[m*k]=0;}}
	
	vector<int> primeVector;
	for(int k=1;k<=upperBound;k++){if(primes[k]){primeVector.push_back(k);}}

	int *output=new int[upperBound+1];
	output[0]=1;for(int k=1;k<=upperBound;k++){output[k]=0;}
	for(unsigned k=0;k<primeVector.size();k++){
		for(int m=primeVector[k];m<=upperBound;m++){
			output[m]+=output[m-primeVector[k]];
		}
	}
	
	int threshold=5000;
	for(int k=0;k<=upperBound;k++){if(output[k]>threshold){return k;}}

	return 0;
}

int main(){cout<< primeSummations(100)<<endl;}
