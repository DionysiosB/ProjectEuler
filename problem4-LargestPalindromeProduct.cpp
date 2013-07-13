#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int largestPalindrome(){
	
	int palindrome=1;
	
	for (int a=9; a>=0; --a) {
		for (int b=9; b>=0; --b) {
			for (int c=9; c>=0; --c) {
				palindrome=100001*a+10010*b+1100*c;
				
				for (int first=100; first<1000; ++first) {
					if ( (palindrome % first ==0) and (palindrome/first>=100) and (palindrome/first<1000)) {
						return palindrome;
					}
				}
				
			}
		}
	}
	
	return 1;

}

int main (int argc, char * const argv[]) {
	
	cout << endl<< largestPalindrome()<< endl;
    
	
	return 0;
}