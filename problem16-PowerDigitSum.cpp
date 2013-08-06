#include <iostream>
#include <cmath>
#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

long digitSum(int power){
	
	int counter=0;
	int carryList[power+1];
	long output=0;
	int current=0;int next=0;
	bool moreDigits=true;
	
	for(counter =0; counter<=power;++counter) carryList[counter]=0;
	carryList[0]=1;
	
	for(int currentDigit=0;moreDigits; ++currentDigit){
		moreDigits=false;
		current=0;
		for(counter=0;counter<=power;++counter){
			next=2*current+carryList[counter];
			current=next%10;
			carryList[counter]=next/10;
			if(carryList[counter]==1) moreDigits=true;
			//cout << " Digit:"<<currentDigit<<" Current:"<<current<<" Carry:"<<carryList[counter]<<endl;
		}
		//cout <<"---------------------------------------"<< current << "\n";
		output+=current;
	}
	
	return output;
}


int main (int argc, char * const argv[]) {
	
	cout <<endl << digitSum(1000)<<endl;
	
	return 0;
}
