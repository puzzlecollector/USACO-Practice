/*
ID: mkim142
LANG: C++
TASK: ride
*/

#include <iostream>
#include <fstream>
using namespace std; 
int main(){
	ifstream fin("ride.in"); 
	ofstream fout("ride.out"); 
	string s1,s2; 
	fin >> s1 >> s2; 
	int prod1 = 1, prod2 = 1; 
	for (int i = 0; i < s1.size(); i++){
		prod1 *= (s1[i]-'A'+1);  
		prod1 %= 47; 
	}
	for (int i = 0; i < s2.size(); i++){
		prod2 *= (s2[i]-'A'+1); 
		prod2 %= 47; 
	}
	if (prod1 == prod2) fout << "GO" << endl; 
	else fout << "STAY" << endl; 
	return 0;  
}
