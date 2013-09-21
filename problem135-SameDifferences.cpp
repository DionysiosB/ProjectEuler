#include <iostream>
#include <cmath>
using namespace std;

long sameDifferences(long upperBound){

	int *outputArray=new int[upperBound+1];
	for(int k=0;k<=upperBound;k++){outputArray[k]=0;}
    for(long u=1;u<=upperBound;u++){for(long v=u/3+1;u*v<=upperBound;v++){if((u+v)%4 == 0 && (-u+3*v)%4 == 0){outputArray[u*v]++;}}}
	long output=0;for(int k=0;k<=upperBound;k++){if(outputArray[k]==10){output++;}}
	return output;
}

int main(){cout<< sameDifferences(1000000)<<endl;}
