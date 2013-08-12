#include <iostream>
using namespace std;

int maxRightTriangles(int upperBound){

    int total=0,maxTotal=0,maxP=0;
    for(int p=3;p<=upperBound;++p){
        total=0;
        for(int a=1;a<=p/2;++a){for(int b=1;b<=a;++b){if(a*a+b*b==(p-a-b)*(p-a-b) ){++total;}}}
        if(total>maxTotal){maxTotal=total;maxP=p;}
    }
    return maxP;
}

int main (int argc, char * const argv[]) {
    cout << maxRightTriangles(1200)<<endl;
	return 0;
}
