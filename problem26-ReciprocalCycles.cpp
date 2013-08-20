#include <iostream>
#include <cmath>
#include <set>
using namespace std;

int cycleLength(int n){
    
    while(n%2==0){n /=2;};while(n%5==0){n /=5;}
    int rem=1;int length=0;
    do{++length;rem=(10*rem)%n;}while(rem>1);
    return length;
}

int findMaxCycle(int upperBound){

    int currentLength=0,maxLength=0;
    for(int k=2;k<upperBound;++k){
        currentLength=cycleLength(k);
        if(currentLength>maxLength){cout << k << " -->  "<< currentLength<<endl;maxLength=currentLength;}}
    cout << "Longest Cycle: " << maxLength <<endl;
    return maxLength;
}

int main (int argc, char * const argv[]) {
	//cout << cycleLength(119)<<endl;
    findMaxCycle(1000);
    return 0;

}
