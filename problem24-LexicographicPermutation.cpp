#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <stdlib.h>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> findNextPerm(vector<int> input, int inputLength){
				
	for(int k=inputLength-2;k>=0;--k){				
		if(input[k]<input[k+1]){
			int currentMin=input[k+1];int currentMinPos=k+1;
			for(int m=inputLength-1;m>=k+1;--m){if(input[m]<currentMin && input[m]>input[k]){currentMin=input[m];currentMinPos=m;}}
			
			int temp=input[k];input[k]=input[currentMinPos];input[currentMinPos]=temp;
			
			sort(input.begin()+k+1,input.end());
			return input;
		}
	}	
	return input;
}

void stringPerm(long number) {
    
		vector<int> stringCounter;for(int k=0;k<10;++k){stringCounter.push_back(k);}
	
        for(int k=0;k<number;++k){
			for(int m=0;m<10;++m){cout <<stringCounter[m];};cout<<endl;
			stringCounter=findNextPerm(stringCounter,10);
		}
}


int main (int argc, char * const argv[]) {
	stringPerm(1000000);
	return 0;
}
