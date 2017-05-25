#include <iostream>
#include <cmath>
using namespace std;

int idempotents(long upperBound){
    long long output=0;
    for(long n=1;n<=upperBound;n++){
        if(n%10000==0){cout<<n<<endl;}
        for(long a=n-1;a>=1;a--){
            if( a * (a-1) == n*( a* (a-1) / n ) ){output +=a;break;}
        }
    }
    return output;
}

int main(){cout<< idempotents(10000000)<<endl;}
