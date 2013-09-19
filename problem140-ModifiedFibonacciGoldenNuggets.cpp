#include <iostream>
#include <cmath>
#include <vector>
#include <set>
using namespace std;

void pellSolver(size_t n){
	
	long long xinitial[]={0,0,-3,-3,-4,-4,2,2};
	long long yinitial[]={-1,1,-2,2,-5,5,-7,7};
	set<unsigned long long> outputSet;
	
	for(unsigned k=0;k<8;k++){
		long long x=xinitial[k],y=yinitial[k];
		long long xnew=0,ynew=0;
		for(size_t count=0;count<n;count++){
			xnew=-9*x-4*y-14;
			ynew=-20*x-9*y+-28;
			x=xnew;y=ynew;
			if(x>0){outputSet.insert(x);};
		}
	}
	
	long long output=0;unsigned count;
	for(set<unsigned long long>::iterator myIter=outputSet.begin(); myIter != outputSet.end(); myIter++) {
		output+=(*myIter);
		count++;
		if(count>=n){break;}
		}
	cout << output<<endl;
	
}

int main(){pellSolver(30);}
