/*
ID: mkim142
LANG: C++
TASK: palsquare 
*/
// print all integers N in range [1,300] such that N^2 is palindromic 
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <fstream> 
#include <vector> 
#include <map> 
using namespace std; 
map<int,char> mp;  
vector<char> convert_to_base_B(int b,int x){
	// convert integer x*x to base b 
	vector<char> v;  
	if (x == 0){
		v.push_back('0'); 
		return v; 
	}
	while (x){
		if (x%b >= 10){
			v.push_back(mp[x%b]);  
		}else{
			v.push_back(char(x%b+'0'));  
		}
		x /= b;  
	}
	reverse(v.begin(),v.end()); 
	return v; 
}
bool isPalindrome(vector<char> &x){
	for (int i = 0; i < x.size()/2; i++){
		if (x[i] != x[x.size()-i-1]) return false;  
	}
	return true; 
}
int main(){
	ifstream fin("palsquare.in"); 
	ofstream fout("palsquare.out");  
	int n;  
	fin >> n; 
	// initialise mp 
	for (int i = 10; i <= 20; i++){
		mp[i] = char('A'+i-10);  
	}
	for (int i = 1; i <= 300; i++){
		vector<char> v = convert_to_base_B(n,i*i);  
		if (isPalindrome(v)){ 
			vector<char> sqrtv = convert_to_base_B(n,i); 
			for (int i = 0; i < sqrtv.size(); i++){
				fout << sqrtv[i];  
			}
			fout << " "; 
			for (int i = 0; i < v.size(); i++){
				fout << v[i]; 
			}
			fout << endl; 
		}
	}
	return 0; 
}
