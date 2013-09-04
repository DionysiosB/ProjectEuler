#include <iostream>
#include <cmath>
using namespace std;

long gcd (long a, long b){return (b == 0) ? a : gcd (b, a%b);}

long pythagoreanTiles(long upperBound){
    long upperLimit=1+sqrt(upperBound/2),output=0;
    long a,b,c,perimeter;
    for(int n=2;n<=upperLimit;n++){
        for(int m=1+(n%2);m<n;m+=2){
            if(gcd(m,n)!=1){continue;}
            a=n*n-m*m;b=2*m*n;c=m*m+n*n;
            if(c%(b-a)==0){output+=upperBound/(a+b+c);}}
    }
    return output;
}

int main () {
	cout << pythagoreanTiles(100000000) <<endl;
}
