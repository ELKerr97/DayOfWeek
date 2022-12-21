#include <iostream>
#include <cmath>
using namespace std;
string weekday[7] = {"Saturday","Sunday","Monday","Tuesday", "Wednesday","Thursday","Friday"};
string zellersAlgorithm(int day, int month, int year){
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
int main(){
   int day, month, year;
   char runAgain;
   bool run = true;
   while(run){
       bool invalidDay = true;
       while(invalidDay){
           cout << "Enter Day: "; cin >>day;
           if(day <= 31){
               invalidDay = false;
           } else {
               cout << "Invalid day. Please try again.\n";
           }
       }

       bool invalidMonth = true;
       while(invalidMonth){
           cout << "Enter Month: "; cin >>month;
           if(month <= 12){
               invalidMonth = false;
           } else {
               cout << "Invalid month. Please try again.\n";
           }
       }

       bool invalidYear = true;
       while(invalidYear){
           cout << "Enter Year: "; cin >>year;
           if(year >= 0){
              invalidYear = false;
           } else {
               cout << "Invalid year. Please try again.\n";
           }
       }

       cout << "It was: " <<zellersAlgorithm(day, month, year) << endl;

       bool invalidInput = true;
       while(invalidInput){
           cout << "Run again? (y/n): "; cin >> runAgain;
           if(runAgain == 'n' || runAgain == 'N'){
               cout << "Adios!" << endl;
               invalidInput = false;
               run = false;
           } else if (runAgain == 'y' || runAgain == 'Y'){
               invalidInput = false;
           } else {
               cout << "Invalid input. \n";
           }
       }

   }

}