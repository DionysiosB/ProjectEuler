#include <iostream>
#include <cmath>
using namespace std;

int monthDays(int year,int month){

    if(month==1 || month==3 || month==5 || month==7 || month==8 || month==10 || month==12){return 31;}
    else if (month==4 || month==6 || month==9 || month==11){return 30;}
    else if (month==2) {
        if(year % 400 == 0){return 29;}
        else if (year % 100 == 0) {return 28;}
        else if (year % 4 == 0) {return 29;}
        else {return 28;}
    }
    cout << "Error!" <<endl;
    return 0;
}

string names(int n){
    if(n==1){return "JAN";}
    if(n==2){return "FEB";}
    if(n==3){return "MAR";}
    if(n==4){return "APR";}
    if(n==5){return "MAY";}
    if(n==6){return "JUN";}
    if(n==7){return "JUL";}
    if(n==8){return "AUG";}
    if(n==9){return "SEP";}
    if(n==10){return "OCT";}
    if(n==11){return "NOV";}
    if(n==12){return "DEC";}
    return "DONT KNOW!!!";
}    

int countSundays(){

    const int upperLimit=2000;
    const int firstDay=2;const int firstMonth=1;const int firstYear=1901;
    int dayCount=firstDay,monthCount=firstMonth,yearCount=firstYear;
    int sundayCount=0;

    while(yearCount<=upperLimit){
        dayCount+=monthDays(yearCount,monthCount);
        ++monthCount;
        if(monthCount>12){yearCount++;monthCount=1;}
        if(dayCount % 7 == 0){cout << names(monthCount) <<"  " << yearCount <<endl;++sundayCount;}
    }

    cout << "Total Sundays: " << sundayCount<<endl;
    return sundayCount;
}

int main (int argc, char * const argv[]) {
    countSundays();
	return 0;
}
