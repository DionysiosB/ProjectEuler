#include <iostream>
#include <cmath>
#include <math.h>
using namespace std;

int countSummations(){
    const int upperBound=10000;
    const int target = 1000000;
    const unsigned long largeInt=10*target;
    unsigned long long *p=new unsigned long long [upperBound];
    unsigned long long *q=new unsigned long long[upperBound];
    p[0]=1;p[1]=1;

    q[0]=1;q[1]=1;
    for(int k=2;k<upperBound;k++){q[k]=0;p[k]=0;}
    

    long temp=0;int sign=0;
    for(int n=2;n<upperBound;n++){

        for(int m=-n;m<=n;m++){
            temp=m*(3*m-1)/2;
            if(temp>n || temp<=0){continue;}
            sign= (m-1)%2==0 ? 1:-1;
            p[n]+=sign*p[n-temp];
        }
        p[n] %= largeInt;  //I GIVE UP. CANNOT UNDERSTAND WHY THE MOD OPERATOR DOES NOT WORK FOR LARGE NUMBERS
        cout << n<<"--->"<<p[n]<<endl;
        if(p[n]%target==0){cout << n<<"--->"<<p[n]<<endl;}
    }
    return 0;
}

int main (int argc, char * const argv[]) {
    countSummations();
}
