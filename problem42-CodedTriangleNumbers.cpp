#include <iostream>
#include <fstream>
#include <sstream>
#include <cmath>
using namespace std;

void triangleCodedNumbers(){

    ifstream inputFile("words.txt");
    string currentWord;
    int n=0,wordScore=0,totalTriangles=0;

    if(inputFile){
        while(getline(inputFile,currentWord,',')){
            wordScore=0;
            currentWord=currentWord.substr(1,currentWord.size()-2);
            for(int k=0;k<currentWord.size();++k){wordScore+=(currentWord[k]-'A'+1);}
            n=int(sqrt(2*wordScore));
            if(n*(n+1)==2*wordScore){++totalTriangles;}
        }
        cout << "Triangles: "<< totalTriangles<<endl;
    }
}

int main (int argc, char * const argv[]) {
    triangleCodedNumbers();
	return 0;
}
