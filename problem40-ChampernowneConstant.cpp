#include <iostream>
#include <cmath>
using namespace std;

int champernownConstant(){

    int upperBound=1000000;
    int total=1,diff=0,temp=0;
    int next=0,nextPower=10,outputConstant=1;

    for(int k=2;k<=upperBound;++k){
        next=int(1+log10(k));
        if(total+next>=nextPower){
            diff=total+next-nextPower;
            temp=( k/int(pow(10.0,diff))  )%10;
            outputConstant*=temp;
            nextPower *=10;
            if(nextPower>upperBound){break;}
        }
        total+=next;
    }
    cout << "Constant: "<<outputConstant<<endl;
}

int main (int argc, char * const argv[]) {
    champernownConstant();
	return 0;
}
