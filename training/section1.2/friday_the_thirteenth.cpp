/*
ID: mkim142
LANG: C++
TASK: friday
*/
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <fstream>
using namespace std; 
int freq[8]; //M(1),T(2),W(3),Th(4),F(5),S(6),Su(7) 
bool isLeap(int x){
	return ((x%100 != 0 && x%4 == 0) || (x%100 == 0 && x%400 == 0));  
}
int main(){
	ifstream fin("friday.in"); 
	ofstream fout("friday.out");  
	int N; 
	fin >> N; 
	int year = 1900, month = 1, day = 1; 
	while (year <= 1900+N-1){
		if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8
			|| month == 10 || month == 12){
			for (int i = 1; i <= 31; i++){ // simulates counting days in month 
				if (day == 8) day = 1; 
				if (i == 13){
					freq[day]++;  
				}
				day++;  
			}
		}else if (month == 4 || month == 6 || month == 9 || month == 11){
			for (int i = 1; i <= 30; i++){
				if (day == 8) day = 1; 
				if (i == 13){
					freq[day]++;  
				}
				day++; 
			}
		}else if (month == 2){
			if (isLeap(year)){
				for (int i = 1; i <= 29; i++){ 
					if (day == 8) day = 1; 
					if (i == 13){
						freq[day]++; 
					}
					day++;  
				}
			}else{
				for (int i = 1; i <= 28; i++){
					if (day == 8){
						day = 1; 
					}
					if (i == 13){
						freq[day]++;  
					}
					day++;  
				}
			}
		}
		month++; 
		if (month == 13){
			year++; 
			month = 1; 
		}
	}
	fout << freq[6] << " " << freq[7] << " "; 
	for (int i = 1; i <= 5; i++){
		if (i < 5) fout << freq[i] << " ";  
		else fout << freq[i] << endl; 
	}
	return 0; 
}
