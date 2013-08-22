#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> findNextPerm(vector<int> input){
    int inputLength=input.size();
	for(int k=inputLength-2;k>=0;--k){				
		if(input[k]<input[k+1]){
			int currentMin=input[k+1];int currentMinPos=k+1;
			for(int m=inputLength-1;m>=k+1;--m){
                if(input[m]<currentMin && input[m]>input[k]){currentMin=input[m];currentMinPos=m;}}
			int temp=input[k];input[k]=input[currentMinPos];input[currentMinPos]=temp;
			sort(input.begin()+k+1,input.end());
			return input;
		}
	}	
	return input;
}

bool pandigitCheck(vector<int> x){
    if((100*x[7]+10*x[8]+x[9])%17 !=0 || (100*x[6]+10*x[7]+x[8])%13 !=0 || (100*x[5]+10*x[6]+x[7])%11 !=0 || (100*x[4]+10*x[5]+x[6])%7 !=0 || (100*x[3]+10*x[4]+x[5])%5 !=0 || (100*x[2]+10*x[3]+x[4])%3 !=0 || (100*x[1]+10*x[2]+x[3])%2 !=0 ){return 0;}
	else {return 1;}
}


int main (int argc, char * const argv[]) {

    vector<int> data,nextData;
	unsigned long total=0, currentValue=0;
	for(int k=0;k<=9;k++){nextData.push_back(k);}
	do{	
		data=nextData;
        if(pandigitCheck(data)){
			currentValue=0;for(unsigned k=0;k<data.size();k++){currentValue=10*currentValue+data[k];}
			total+=currentValue;
		}
        nextData=findNextPerm(data);
	}while(nextData != data);
	cout << total << endl;
}
