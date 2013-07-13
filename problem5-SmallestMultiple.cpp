#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int evenlyDivided(int n){
	
	int factorList[n-1];
	for (int k=2; k<=n; ++k) factorList[k-2]=k;
	
	for (int m=0; m<n-2; ++m)
		for (int u=m+1; u<n-1; ++u)
			if (factorList[u] % factorList[m] == 0 ) factorList[u]= factorList[u]/factorList[m];
	
	int output = 1;
	for (int k=0; k<n-1; ++k) {
		cout << factorList[k] << "   ";
		output *= factorList[k];
	}
	
	return output;

}

int main (int argc, char * const argv[]) {
	
	cout << endl<< evenlyDivided(20)<< endl;
    
	
	return 0;
}