#include <iostream>
#include <cmath>
using namespace std;

long gcd (long a, long b){return (b == 0) ? a : gcd (b, a%b);}

long resilience(int upperBound){
	
	const double threshold=15499.0/94744.0;
	bool primes[upperBound+1];primes[0]=0;primes[1]=0;for(int k=2;k<=upperBound;k++){primes[k]=1;}
	for(int k=2;k<=sqrt(upperBound);k++){for(int m=2;m<=upperBound/k;m++){primes[m*k]=0;}}
	
	double maxProd=1,nom=1,den=1;
	for(int k=2;k<upperBound;k++){
		if(!primes[k]){continue;}
		nom *=k-1;den *=k;maxProd=nom/den;
		for(int u=1;u<k;u++){if(1.0*nom*u/(den*u-1)<threshold){return 1.0*den*u;}}
	}
	return 0;
}


int main (int argc, char * const argv[]) {
    cout << resilience(50)<<endl;
	return 0;
}
