#include <iostream>
#include <cmath>
#include <vector>
#include <set>
#include <fstream>
using namespace std;

void findPasscode(){

    //Read File
	int buf;set<int> data;const int maxLength=10;
    ifstream inputFile ("keylog.txt");
	if(inputFile){while(inputFile >> buf){data.insert(buf);}}
    int adjMatrix[maxLength][maxLength]={0};

    //Construct Adjacency Matrix;
    int currentElement,first,second,third;
    for(set<int>::iterator myIter=data.begin(); myIter != data.end();myIter++){
        currentElement=*myIter;
        first=currentElement/100;second=(currentElement/10)%10;third=currentElement%10;
        adjMatrix[first][second]=1;adjMatrix[second][third]=1;
    }

    bool done=0;
    int source=0,destination=0,final=0;vector<int> output;
    while(!done){
        done=1;
        for(int row=0;row<maxLength;++row){
            source=0;
            for(int col=0;col<maxLength;++col){if(adjMatrix[row][col]==1){source=1;break;}}
            if(!source){
                destination=0;
                for(int test=0;test<maxLength;++test){if(adjMatrix[test][row]==1){destination=1;final=test;}}
                if(destination==1){
                    done=0;output.push_back(row);
                    for(int test=0;test<maxLength;++test){adjMatrix[test][row]=0;}
                }
            }
        }
    }
    output.push_back(final);
    for(int k=output.size()-1;k>=0;k--){cout << output[k]<<" ";};cout <<endl;
}

int main (int argc, char * const argv[]) {
	findPasscode();
}

