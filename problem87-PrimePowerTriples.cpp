#include <iostream>
#include <cmath>
using namespace std;

int primePowerTriples(){

    const int upperBound=50000000;
    const int primesBound=1+int(sqrt(upperBound));
    bool primes[primesBound+1];
    primes[0]=0;primes[1]=0;for(int k=2;k<=primesBound;++k){primes[k]=1;}
    for(int k=2;k<=sqrt(primesBound);k++){if(primes[k]){for(int m=2;m<=primesBound/k;m++){primes[m*k]=0;}}}

	bool *primeSums=new bool[upperBound];
	double A,B,C;
	long temp=0;
    for(int a=0;a<=primesBound;a++){
		if(!primes[a]){continue;};A=pow(1.0*a,4);if(A>upperBound){continue;}
        for(int b=0;b<=primesBound;b++){
			if(!primes[b]){continue;};B=pow(1.0*b,3);if(A+B>upperBound){continue;}
            for(int c=0;c<=primesBound;c++){
				if(!primes[c]){continue;};C=pow(1.0*c,2);
                if(A+B+C<upperBound){temp=int(A+B+C);primeSums[temp]=1;}
            }    
        }
    }
    
    long count=0;for(int k=0;k<upperBound;k++){if(primeSums[k]){++count;}}
    cout << "Result: "<< count<<endl;
    return count;

}

int main (int argc, char * const argv[]) {
    primePowerTriples();
}
