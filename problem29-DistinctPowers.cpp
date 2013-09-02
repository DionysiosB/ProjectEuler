#include <iostream>
#include <set>
using namespace std;

int distinctPowers(){
    
    const int a=2,b=100;int output=0;     
    //Powers of 2:
    set<int> temp;for(int k=1;k<=6;k++){for(int m=a;m<=b;m++){temp.insert(k*m);}}
    output+=temp.size();
    //Powers of 3:
    temp.clear();for(int k=1;k<=4;k++){for(int m=a;m<=b;m++){temp.insert(k*m);}}
    output+=temp.size();
    //Powers of 5,6,7,10:
    output+=4*50;
    //All the rest:
    output+=99*85;
    return output;
}

int main () {
	cout << distinctPowers() <<endl;
}
