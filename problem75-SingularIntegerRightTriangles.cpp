#include <iostream>
#include <cmath>
using namespace std;

long gcd (long a, long b){return (b == 0) ? a : gcd (b, a%b);}

long singularRightTriangles(){
    
    const long perimeterLimit=1500000;
    long sideLimit=1+sqrt(perimeterLimit/2),output=0;
    long a,b,c,mult,perimeter,newPerimeter;
    int *state=new int[perimeterLimit+1];
    for(int k=0;k<=perimeterLimit;k++){state[k]=0;}
    for(int m=1;m<=sideLimit;m++){
        for(int n=m+1;n<=sideLimit;n+=2){
            if(gcd(m,n)!=1){continue;}
            //a=n*n-m*m;b=2*m*n;c=m*m+n*n; perimeter=a+b+c;
            perimeter=2*n*(m+n);
            for(int mult=1;mult<=perimeterLimit/perimeter;mult++){state[mult*perimeter]++;}
        }
    }
    for(int k=0;k<=perimeterLimit;k++){if(state[k]==1){output++;}}
    return output;
}

int main () {out << singularRightTriangles() <<endl;}
