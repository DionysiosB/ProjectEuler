#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

vector<int> findDigits(int n){
    vector<int> output;
    while(n>0){output.push_back(n%10);n /=10;}
    return output;
}

int vectorSum(vector<int> input){
    int output=0;
    for(int k=0;k<input.size();++k){output+=input[k];}
    return output;
}

vector<int> vectorProduct(vector<int> first,vector<int> second){
    int a=first.size(),b=second.size(),currentTotal=0;
    vector<int> output;
    for(int n=0;n<a+b-1;++n){
        currentTotal=0;
        for(int p=0;p<=min(a-1,n);++p){if(n-p>=0 && n-p<b){currentTotal+=first[p]*second[n-p];}}
        output.push_back(currentTotal);
    }

    int temp=0;
    for(int k=0;k<output.size()-1;++k){if(output[k]>=10){temp=output[k];output[k]=temp%10;output[k+1]+=temp/10;}}
    while(output.back()>=10){temp=output.back();output[output.size()-1]=temp%10;output.push_back(temp/10);}
    return output;
}

int maxDigitSum(int upperBound){

    vector<int> numberDigits,output;
    int maxSum=0;int currentSum=0;

    for(int a=1;a<=upperBound;++a){
        numberDigits=findDigits(a);
        output=findDigits(a);
        for(int b=2;b<upperBound;++b){
            output=vectorProduct(output,numberDigits);
            currentSum=vectorSum(output);
            if(currentSum>maxSum){maxSum=currentSum;}
        }
    }
    cout << maxSum<<endl;
    return maxSum;
}

int main (int argc, char * const argv[]) {

    maxDigitSum(100);
	return 0;
}
