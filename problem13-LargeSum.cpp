#include <iostream>
#include <cmath>
#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

vector<string> readFile(){
	vector<string> output;
	string line;
	ifstream inputFile("inputFile.txt");
	if(inputFile){
		while(getline(inputFile,line)){
			output.push_back(line);
		}
	}
	return output;
}

unsigned long sumMSB(){
	
	vector<string> inputVector=readFile();
	vector<string>::iterator myIter;
	string currentString;
	int stringLength=50;	
	int msbDigits=10;
	unsigned long long MSBsum=0;
	long int temp;
	

	for(myIter=inputVector.begin(); myIter != inputVector.end() ; ++myIter){
		currentString=(*myIter);
		if(currentString.size() !=stringLength){
			cout << "Found String with different length"<<endl;
			return -1;
		}
		
	    istringstream buf(currentString.substr(0,msbDigits));
		buf >> temp;
		MSBsum+=temp;
	}
	
	
	int currentSum=0;
	for(int currentPos=stringLength-1;currentPos>=msbDigits;--currentPos){
		for(myIter=inputVector.begin(); myIter != inputVector.end() ; ++myIter){
			currentString=(*myIter);
	    	istringstream buf(currentString.substr(currentPos,1));
			buf >> temp;
			currentSum+=temp;
		}
		currentSum = currentSum/10;
	}
	
	
	
	
	return (MSBsum+currentSum)/100;
	
}




int main (int argc, char * const argv[]) {
	
	
	cout << endl<< sumMSB()<< endl;
	 
	 
	 return 0;
}
