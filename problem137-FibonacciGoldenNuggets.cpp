#include <iostream>
#include <cmath>
using namespace std;

unsigned long long fibonacci(int n){	
	double phi=(1+sqrt(5))/2;
	double psi=(1-sqrt(5))/2;
	return round((pow(phi,n)-pow(psi,n))/sqrt(5));
}

unsigned long long fibonacciGoldenNuggets(int n){return fibonacci(2*n)*fibonacci(2*n+1);}

int main(){cout<< fibonacciGoldenNuggets(15)<<endl;}
