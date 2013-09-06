#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <cmath>
using namespace std;

long largestExponential() {
	string line;int commaPos;
    unsigned long base,exp;size_t counter=0,maxLine=0;double currentMax=0;
	ifstream inputFile ("base_exp.txt");
	if(inputFile){		
		while(getline(inputFile,line)){
			counter++;
            commaPos=line.find(",");
		    base=atoi(line.substr(0,commaPos).c_str());
			exp=atoi(line.substr(commaPos+1).c_str());
            if(exp*log(base)>currentMax){currentMax=exp*log(base);maxLine=counter;}
        }
	}
	inputFile.close();
    return maxLine;
}

int main () {cout<< largestExponential()<<endl; }
