#include <iostream>
using namespace std;

bool isBouncy(long n){

    while(n%10==(n/10)%10){n/=10;}
    int direction= n%10>(n/10)%10 ? 1:-1;
    n /=10;    
    while((n/10)>0){if(direction*(n%10-(n/10)%10)<0){return 1;};n/=10;} 
    return 0;
}

int main (){
    const long upperBound=2000000;
    const int thresholdPercent=99;
    long count=0;
    for(size_t k=1;k<upperBound;k++){
        if(isBouncy(k)){
            count++;
            if(100*count == k*thresholdPercent){cout<<k<<endl;break;}
        }
    }
}

