#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;

int wordScore(string input){
    int output=0;
    for(int k=0;k<input.size();++k){if(input[k]>='A' && input[k]<='Z'){output+=input[k]-'A'+1;}}
    return output;
}

long nameScores(){
    string currentName;
    ifstream inputFile("names.txt");
    vector<string> data;
    long totalScore=0;

    if(inputFile){while(getline(inputFile,currentName,',')){data.push_back(currentName);}}
    sort(data.begin(),data.end());

    for(int k=0;k<data.size();++k){totalScore+=(k+1)*wordScore(data[k]);}
    cout <<"Total Score: "<< totalScore <<endl;
    return totalScore;
}

int main (int argc, char * const argv[]) {
    nameScores();
	return 0;
}
