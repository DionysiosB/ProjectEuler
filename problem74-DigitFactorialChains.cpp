#include <iostream>
#include <cmath>
#include <set>
using namespace std;

long factorial(int d){long output=1;for(int k=1;k<=d;k++){output *=k;};return output;}
long digitFactorial(long n){long output=0;while(n>0){output+=factorial(n%10);n /=10;};return output;}

long digitFactorialChains(long upperBound){
    const int target=60;set<int> chain;int temp=0,output=0;
    for(int n=1;n<upperBound;n++){
        chain.clear();temp=n;
        while(chain.find(temp)==chain.end()){chain.insert(temp);temp=digitFactorial(temp);}
        if(chain.size()==target){output++;}
    }
    return output;
}

int main (){cout << digitFactorialChains(1000000) << endl;}
