#include <iostream>
#include <cmath>
#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

unsigned long bruteForceCollatz(unsigned long n){
	unsigned long counter=1;	
	while(true){
		//cout << counter <<"   "<< n << endl;
		if(n==1) return counter;
		++counter;
		if(n % 2== 0) n=n/2;
		else n=3*n+1;
	}
	return 0;
}



long maxCollatzLength(int N){
	
	int constant = 2.75;
	long currentMax=0;int counterMax=0;
	int counter=0;
	int lengthVector[constant*N];	
	for(counter=0;counter<constant*N;++counter) lengthVector[counter]=1;
	
	counter=0;
	int index=1;
	while(index<constant*N){
		lengthVector[index]=++counter;
		index*=2;		
	}
	
	for(counter=2;counter<N; ++counter){
		
		if(counter % 2 ==0){
			lengthVector[counter]=1+lengthVector[counter/2];
		}
		if(counter %6 == 1 ||counter % 6 ==3 || counter % 6 ==5 ){
			lengthVector[counter]=bruteForceCollatz(counter);
		}
		
		
		if(lengthVector[counter]>currentMax){
			currentMax=lengthVector[counter];
			counterMax=counter;
			cout << counterMax << " --->  "<< currentMax<<endl;
		}
				
	}
	
	return currentMax;
	
}



int main (int argc, char * const argv[]) {
	
	cout <<endl << maxCollatzLength(1000000)<<endl;
	
	return 0;
}
