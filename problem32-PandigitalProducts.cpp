#include <iostream>
#include <set>
#include <cmath>
using namespace std;

set<int> findDigits(set<int> output,long n){
    while(n>0){
        if( output.find(n%10)== output.end() ){output.insert(n%10);n /=10;}
        else{output.clear();break;}
    }
    return output;
}

long findPangrams(long upperBound){

    set<int> temp;set<long> output;long total=0;
    for(long a=1;a<upperBound;++a){
        for(long b=1;b<min(a,upperBound/a);++b){
            temp.clear();
            temp=findDigits(temp,a);if(temp.empty()){continue;}
            temp=findDigits(temp,b);if(temp.empty()){continue;}
            temp=findDigits(temp,a*b);if(temp.empty()){continue;}
            if(temp.size()==9 && temp.find(0)==temp.end()){output.insert(a*b);}
        }
    }
    cout << endl;
    for(set<long>::iterator myIter=output.begin();myIter != output.end();++myIter){cout << (*myIter)<<endl;total+=(*myIter);}
    cout << total <<endl;
    return total;
}

int main (int argc, char * const argv[]) {
    findPangrams(10000);
	return 0;
}
