#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

unsigned long specialIsoscelesTriangles(int N){

	long x=0,y=-1,xnew,ynew,output=0;
    for(int n=1;n<=N;n++){
		xnew=-9*x-4*y+4;
		ynew=-20*x-9*y+8;
		x=xnew;y=ynew;
		output+=abs(y);
		cout << output<<endl;
	}
    return output;
}

int main (){cout << specialIsoscelesTriangles(12)<<endl;}
