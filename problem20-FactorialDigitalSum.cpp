#include <iostream>
#include <cmath>
#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

long digitSum(int number){
	
	int counter=0;
	int totalDigits=20*number;
	int digitList[totalDigits];
	long output=0;
	int current=0;
	long next=0;
	int currentDigit;
	int nextDigits;
	
	for (counter=1; counter<totalDigits; ++counter) digitList[counter]=0;
	digitList[0]=1;
	
	for(counter=1;counter<=number;++counter){
		//cout << "-------------------------------------------------->Iteration:"<<counter <<endl;
		for(currentDigit=totalDigits;currentDigit>=0;--currentDigit){
			current=digitList[currentDigit];
			next=counter*current;
			digitList[currentDigit]=0;
			//cout <<"  CurrentOrder:"<<currentDigit<< " CurrentDigit:"<<digitList[currentDigit]<<" Current:"<<current<< "  Next:"<< next<<endl;
			for (nextDigits=currentDigit; nextDigits<=totalDigits; ++nextDigits) {
				//cout << "tempDigit:"<< nextDigits<<endl;
				digitList[nextDigits]+=(next%10);
				next /=10;
			}
		}
		
		for (currentDigit=0; currentDigit<totalDigits; ++currentDigit) {
			if (digitList[currentDigit]>9) {
				digitList[currentDigit+1]+=digitList[currentDigit]/10;
				digitList[currentDigit]=digitList[currentDigit]%10;
			}
		}
		
	}
	
	
	
	cout <<endl;
	for (counter=totalDigits-1; counter>=0; --counter) {
		//cout << digitList[counter];
		output+=digitList[counter];
	}
	return output;
}


int main (int argc, char * const argv[]) {
	
	cout <<endl << digitSum(100)<<endl;
	
	return 0;
}
