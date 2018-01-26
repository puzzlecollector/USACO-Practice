/*
ID: mkim142
LANG: C++
TASK: dualpal 
*/
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <fstream> 
using namespace std; 
vector<int> convert_to_base_b(int b,int x){
	// convert integer x to base b
	vector<int> v; 
	if (x == 0){
		v.push_back(0); 
		return v; 
	}
	while (x){
		v.push_back(x%b); 
		x /= b;  
	}
	reverse(v.begin(),v.end());  
	return v;  
}
bool isPalindrome(vector<int> &x){
	for (int i = 0; i < x.size(); i++){
		if (x[i] != x[x.size()-i-1]) return false; 
	}
	return true; 
}
int main(){
	int N,S; 
	ifstream fin("dualpal.in"); 
	ofstream fout("dualpal.out");  
	fin >> N >> S;  
	int totalCnt = 0;  
	for (int i = S+1;;i++){
		if (totalCnt == N) break; 
		int curCnt = 0; 
		for (int b = 2; b <= 10; b++){
			vector<int> v = convert_to_base_b(b,i);  
			if (isPalindrome(v)) curCnt++; 
		}
		if (curCnt >= 2){
			totalCnt++;  
			fout << i << endl; 
		}
	}
	return 0; 
}
