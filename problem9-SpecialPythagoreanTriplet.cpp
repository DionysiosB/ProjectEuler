#include <iostream>
#include <cmath>
#include <vector>
#include <string>
using namespace std;

int PythaProd(int pSum){
	
	int c;
	for (int a=1; a<pSum/2; ++a) {
		for (int b=a; b<pSum/2; ++b) {
			c=pSum-a-b;
			if (pow(1.0*a,2)+pow(1.0*b,2)==pow(1.0*c,2)) {
				cout << "  a:" << a << "  b:" <<b<< "  c:" <<c <<endl;
				return a*b*c;
			}
		}
	}
	
	return 0;
	
}



int main (int argc, char * const argv[]) {
	
	cout << PythaProd(1000) <<endl;
	
	return 0;


}