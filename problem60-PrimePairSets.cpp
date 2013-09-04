#include <iostream>
#include <cmath>
using namespace std;

long concatenate(int a,int b){int order=1;while(b/order>0){order *=10;};return a*order+b;}

long primePairSets(){

    const long primeBound=10000;
    const long upperBound=primeBound*primeBound;
    bool *primes=new bool[upperBound+1];primes[0]=0;primes[1]=0;
    for(int k=2;k<=upperBound;k++){primes[k]=1;}
    for(int k=0;k<=sqrt(upperBound);k++){if(primes[k]){for(int m=2;m<=upperBound/k;m++){primes[k*m]=0;}}}

    for(long first=0;first<primeBound;first++){
        if(!primes[first]){continue;}
        for(long second=first+1;second<primeBound;second++){
            
            if(!primes[second]){continue;}
            if(!primes[concatenate(first,second)]){continue;}
            if(!primes[concatenate(second,first)]){continue;}

            for(long third=second+1;third<primeBound;third++){
                if(!primes[third]){continue;}
                if(!primes[concatenate(first,third)]){continue;}
                if(!primes[concatenate(second,third)]){continue;}
                if(!primes[concatenate(third,first)]){continue;}
                if(!primes[concatenate(third,second)]){continue;}

                for(long fourth=third+1;fourth<primeBound;fourth++){
                    if(!primes[fourth]){continue;}
                    if(!primes[concatenate(first,fourth)]){continue;}
                    if(!primes[concatenate(second,fourth)]){continue;}
                    if(!primes[concatenate(third,fourth)]){continue;}
                    if(!primes[concatenate(fourth,first)]){continue;}
                    if(!primes[concatenate(fourth,second)]){continue;}
                    if(!primes[concatenate(fourth,third)]){continue;}
                        
                    for(long fifth=fourth+1;fifth<primeBound;fifth++){
                        if(!primes[fifth]){continue;}
                        if(!primes[concatenate(first,fifth)]){continue;}
                        if(!primes[concatenate(second,fifth)]){continue;}
                        if(!primes[concatenate(third,fifth)]){continue;}
                        if(!primes[concatenate(fourth,fifth)]){continue;}
                        if(!primes[concatenate(fifth,first)]){continue;}
                        if(!primes[concatenate(fifth,second)]){continue;}
                        if(!primes[concatenate(fifth,third)]){continue;}
                        if(!primes[concatenate(fifth,fourth)]){continue;}

                        cout << first<<" "<<second<<" "<<third<<" "<<fourth<<" "<<fifth<<endl;
                        return first+second+third+fourth+fifth;
                    }
                }
            }
        }
    }
    return 0;
}


int main () {cout << primePairSets() <<endl;}
