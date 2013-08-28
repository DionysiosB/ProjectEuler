#include <iostream>
#include <fstream>
#include <sstream>
#include <set>
#include <stdlib.h>
using namespace std;

int findMinTree(){

    const int order=40;int data[order][order]={0};
    
    //Read Input;
    string line,temp;
    ifstream inputFile("network.txt");
    if(inputFile){
        int row=0,col=0;
        while(getline(inputFile,line)){
            istringstream buf(line);
            while(getline(buf,temp,',')){data[row][col++]=atoi(temp.c_str());}
            row++;col=0;
        }
    }
    inputFile.close();

    int networkWeight=0;for(int x=0;x<order;x++){for(int y=0;y<order;y++){networkWeight+=data[x][y];}}

    set<int> connected; int treeWeight=0,minEdge=0,firstNode=0,secondNode=0;
    
    connected.insert(0);
    while(connected.size()<order){
        minEdge=1000000;

        for(int x=0;x<order;x++){
            if(connected.find(x) == connected.end()){continue;}
            for(int y=0;y<order;y++){
                if(connected.find(y) != connected.end()){continue;}
                if(data[x][y]>0 && data[x][y]<minEdge){minEdge=data[x][y];firstNode=x;secondNode=y;}
            }
        }
        connected.insert(secondNode);treeWeight+=minEdge;
    }

    cout << "TotalSavings: "<< networkWeight/2-treeWeight<<endl;
    return (networkWeight/2-treeWeight);
}

int main (int argc, char * const argv[]) {
    findMinTree();
}
