#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

vector<int> findDigits(int n){
    vector<int> output;
    while(n>0){output.push_back(n%10);n /=10;}
    return output;
}

vector<int> reverseAndAdd(vector<int> input){
    vector<int> output;int length=input.size();
    for(int k=0;k<length;++k){output.push_back(input[k]+input[length-1-k]);}

    int temp=0;
    for(int k=0;k<output.size()-1;++k){if(output[k]>=10){temp=output[k];output[k]=temp%10;output[k+1]+=temp/10;}}
    while(output.back()>=10){temp=output.back();output[output.size()-1]=temp%10;output.push_back(temp/10);}

    return output;
}

bool isPalindrome(vector<int> input){
    for(int k=0;k<=input.size()/2;++k){if(input[k] != input[input.size()-k-1]){return 0;}}
    return 1;
}


int findLychrelNumbers(int upperBound,int iterationBound){

    int iterations, count=upperBound-1;vector<int> data;
    for(int k=1;k<upperBound;++k){
        iterations=0;data=findDigits(k);
        while( (++iterations) < iterationBound){
            data=reverseAndAdd(data);
            if(isPalindrome(data)){--count;break;}
        }
    }
    cout << count<<endl;
    return count;
}



int main (int argc, char * const argv[]) {
    
    findLychrelNumbers(10000,50);
	return 0;
}
