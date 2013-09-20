#include <iostream>
#include <vector>
#include <stdlib.h>
#include <algorithm>
using namespace std;


class counter {
	int min,max,length;vector<int> data;	
public:
	counter (int m,int M,int l){
		min=m;max=M;length=l;
		for(int k=0;k<l;++k){data.push_back(min);}
	}
	
	int inc(){
		data[0]++;
		for(int k=0;k<length-1;++k){if(data[k]>max){data[k]=min;++data[k+1];}}
		if(data[length-1]>max){return 0;}
		return 1;
	}
	
	vector<int> queryData(){return data;}
};


int vectorSum(vector<int> data){
	int output=0;
	for(unsigned k=0;k<data.size();k++){output+=data[k];}
	return output;
}

void diceGame() {
	bool notdone;
	const int maxScore=36;
	int countP[maxScore+1]={0},countC[maxScore+1]={0};
	vector<int> currentState;
	
	counter counterP(1,4,9);
	do{
		currentState=counterP.queryData();
		countP[vectorSum(currentState)]++;
		notdone=counterP.inc();
	}while(notdone);
	
	counter counterC(1,6,6);
	do{
		currentState=counterC.queryData();
		countC[vectorSum(currentState)]++;
		notdone=counterC.inc();
	}while(notdone);
	
	long sumC=0,sumP=0;
	for(int k=0;k<=maxScore;k++){sumC+=countC[k];sumP+=countP[k];}
	
	double output=0;
	for(int k=1;k<=maxScore;k++){
		for(int m=1;m<k;m++){
			output+=countP[k]*countC[m];			
		}
	}
	output /= (sumC*sumP);
	cout.precision(7);cout<<output<<endl;
}

int main (int argc, char * const argv[]) {diceGame();}