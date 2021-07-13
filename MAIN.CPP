/* Submission done by AYUSH VARSHNEY
    ON 14/July/2021
    in C++14 */


#include<iostream>
using namespace std;
#include<math.h>
#include<string.h>
#include<map>
using namespace std;


//-------------------------------------------------------Function to convert dd/mm/yyyy to its corresponding day--------
string weekday[7] = {"Mon","Tue","Wed","Thur", "Fri","Sat","Sun"};

string func(int day, int month, int year){
   int mon;
   if(month > 2)
      mon = month; //for march to december month code is same as month
   else{
      mon = (12+month); //for Jan and Feb, month code will be 13 and 14
      year--; //decrease year for month Jan and Feb
   }
   int y = year % 100; //last two digit
   int c = year / 100; //first two digit
   int w = (day + floor((13*(mon+1))/5) + y + floor(y/4) + floor(c/4) + (5*c));
   w = w % 7;
   return weekday[w];
}



//--------------------------------------------------------Main Driver Function----
int main(){

  //-----------------Input Dictionary
	map<string,int> in = {{"2020-01-01",4},{"2020-01-02",4},{"2020-01-03",6},{"2020-01-04",8},{"2020-01-05",2},{"2020-01-06",-6},{"2020-01-07",2},{"2020-01-08",-2}};
	
  //-----------------Output Dictionary
  map<string,int> out = {{"Mon",0},{"Tue",0},{"Wed",0},{"Thur",0},{"Fri",0},{"Sat",0},{"Sun",0}};
	
	for(auto i: in){
		int year= stoi(i.first.substr(0,4));
		int mon = stoi(i.first.substr(6,7));
		int day = stoi(i.first.substr(9,10));
		
		string temp = func(day,mon,year);
		
		out[temp] += i.second;
	}
	
	for(auto i: out){
		cout<<i.first<<" "<<i.second<<endl;
	}
	
	return 0;
}
