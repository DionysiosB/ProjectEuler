#include <iostream>
#include <cmath>
#include <vector>
#include <iostream>
#include <fstream>
using namespace std;

vector<int> readInput(char * inputFilename) {
	
	vector<int> output;
	string line;
	
	ifstream myfile (inputFilename);
	if (myfile.is_open())
	{
		while ( myfile.good() )
		{
			getline (myfile,line);
			cout << line << endl;
		}
		myfile.close();
	}
	
	else cout << "Unable to open file\n"; 
	
	return output;
}



int maxMatProd(){
	
	char * fileName="inputFile.txt";
	readInput(fileName);
	return 0;
}



int main (int argc, char * const argv[]) {
	 cout << endl<< maxMatProd()<< endl;
	 
	 
	 return 0;
}
