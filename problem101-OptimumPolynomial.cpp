#include <iostream>
#include <cmath>
using namespace std;

long long evaluatePolynomial(int n){
    long long output=(long long)(1-n+pow(1.0*n,2)-pow(1.0*n,3)+pow(1.0*n,4)-pow(1.0*n,5)+pow(1.0*n,6)-pow(1.0*n,7)+pow(1.0*n,8)-pow(1.0*n,9)+pow(1.0*n,10));
    return output;
}

long optimumPolynomial(){

}



int main(){cout<< evaluatePolynomial(-1)<<endl;}
