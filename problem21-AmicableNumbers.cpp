#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

vector<unsigned> properDivisors(unsigned n){
	
    vector<unsigned> output;int k,m;
    output.push_back(1);
    for(k=2;k<round(sqrt(n));++k){if(n%k==0){output.push_back(k);output.push_back(n/k);}}
    return output;
}

unsigned sumOfProperDivisors(unsigned n){
    
    int total=0;
    vector<unsigned> data=properDivisors(n);
    for(unsigned k=0;k<data.size();++k){total+=data[k];}
    return total;
}



int main (int argc, char * const argv[]) {
    
    int currentSum,output=0,upperBound=10000;
    for(unsigned k=2;k<upperBound;++k){
        currentSum=sumOfProperDivisors(k);
        if((currentSum != k) && (sumOfProperDivisors(currentSum)==k)){cout<<k<<endl;output+=k;}
    }
    cout<<"The sum is: "<< output<<endl;
	
	return 0;
}
