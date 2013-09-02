#include <iostream>
#include <cmath>
using namespace std;

long spiralPrimes(){

    const int upperBound=15000;
    const long long totalNumbers=(2*upperBound+1)*(2*upperBound+1);
    bool *primes=new bool[totalNumbers+1];primes[0]=0;primes[1]=0;
    for(int k=2;k<=totalNumbers;k++){primes[k]=1;}
    for(int k=0;k<=sqrt(totalNumbers);k++){if(primes[k]){for(int m=2;m<=totalNumbers/k;m++){primes[k*m]=0;}}}

    long long upperRight,upperLeft,bottomRight,bottomLeft,count=0,output=0;
    for(int n=1;n<=upperBound;n++){
        upperRight=4*n*n-2*n+1;
        upperLeft=4*n*n+1;
        bottomLeft=4*n*n+2*n+1;
        //bottomRight=(2*n+1)*(2*n+1); //this will never be a prime by construction
        count+=primes[upperRight]+primes[upperLeft]+primes[bottomLeft];
        if(1.0*count/(4*n+1)<0.1){output=2*n+1;break;}
    }
    return output;
}

int main () {
	cout << spiralPrimes() <<endl;
}
