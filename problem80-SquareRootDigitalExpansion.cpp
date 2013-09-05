#include <iostream>
#include <boost/multiprecision/cpp_int.hpp>
#include <boost/lexical_cast.hpp>
using namespace std;
using namespace boost::multiprecision;
using namespace boost;

const int upperBound=100;


int squareRootDigitSum(size_t n){

    cpp_int a=5*n;cpp_int b=5;cpp_int temp; 
    bool done=0;
    int count=0;
    do{
        if(a>=b){a-=b;b+=10;}
        else{a=a*100;temp=b%10;b=b/10;b=b*100;b=b+temp;}
    }while(b<static_cast<cpp_int>(pow(10.0,110.0))  );
    
    string result=lexical_cast<string>(b);

    size_t output=0;
    for(size_t k=0;k<upperBound;k++){output+=result[k]-'0';}
    return output;
}

int main (){
    
    long output=0;
    for(int k=1;k<=upperBound;k++){
        if( int(sqrt(k))*int(sqrt(k))==k){continue;}
        output+=squareRootDigitSum(k);
    }
    cout << output<<endl;

}

