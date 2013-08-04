#include <iostream>
#include <cmath>
#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

int numDict(int x){

	int smallArray[]={0,strlen("one"),strlen("two"),strlen("three"),strlen("four"),strlen("five"),strlen("six"),strlen("seven"),strlen("eight"),strlen("nine"),strlen("ten"),strlen("eleven"),strlen("twelve"),strlen("thirteen"),strlen("fourteen"),strlen("fifteen"),strlen("sixteen"),strlen("seventeen"),strlen("eighteen"),strlen("nineteen")};
	int midArray[]={0,0,strlen("twenty"),strlen("thirty"),strlen("forty"),strlen("fifty"),strlen("sixty"),strlen("seventy"),strlen("eighty"),strlen("ninety")};
	int largeArray[]={strlen("and"),0,strlen("hundred"),strlen("thousand")};
	
	int totalLength=0;
	int temp;
		
	for(int counter=1;counter<=x;++counter){
		temp=(counter/1000)%10;
		if(temp>0) totalLength+=smallArray[temp]+largeArray[3];		
		
		temp=(counter/100)%10;
		if(temp>0) {
			totalLength+=smallArray[temp]+largeArray[2];
			if(counter%100>0) totalLength+=largeArray[0];
		}
		
		temp=counter%100;
		if(temp>=1  && temp<=19) totalLength+=smallArray[temp];
		if(temp>=20 && temp<=99) totalLength+=midArray[(temp/10)%10]+smallArray[temp%10];
				
	}
	
	return totalLength;
	
}





int main (int argc, char * const argv[]) {
	
	cout <<endl << numDict(1000)<<endl;
	
	return 0;
}
