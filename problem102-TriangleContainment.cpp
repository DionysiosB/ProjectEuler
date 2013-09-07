#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <vector>
#include <cmath>
using namespace std;

vector<int> splitCSV(string input,char delim){
    vector<int> output;stringstream lineStream(input);string temp;
	while(getline(lineStream,temp,delim)){output.push_back(atoi(temp.c_str()));}
    return output;
}

long triangleContainment() {
	string line;vector<int> points;
	int count=0;
	float det,detA,detB,a,b;
	
	ifstream inputFile ("triangles.txt");
	if(inputFile){		
		while(getline(inputFile,line)){
			points=splitCSV(line,',');
			det=points[0]*points[3]-points[1]*points[2];
			detA=points[2]*points[5]-points[3]*points[4];
			detB=points[1]*points[4]-points[0]*points[5];
			if(det==0){return 0;}
			a=detA/det,b=detB/det;
			if(a>0 && b>0){count++;}
        }
	}
	inputFile.close();
    return count;
}

int main () {cout<< triangleContainment()<<endl;}
