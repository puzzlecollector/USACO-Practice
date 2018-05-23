/*
ID: mkim142
LANG: C++
TASK: prefix 
*/
#include <iostream>
#include <fstream> 
#include <cstdlib>
#include <algorithm>
#include <cstring> 
#include <vector> 
using namespace std; 
int dp[200005];  
int main(){
	ifstream fin("prefix.in");
	ofstream fout("prefix.out"); 
	vector<string> dictionary; 
	while (1){
		string word; 
		fin >> word; 
		if (word == ".") break; 
		dictionary.push_back(word); 
	}
	string s,l;  
	while (fin >> l){
		s += l;  
	}
	int n = s.size(); 
	int ans = 0; 
	for (int i = 0; i <= n; i++){
		for (int j = 0; j < dictionary.size(); j++){
			int start = i-dictionary[j].size(); 
			if (start < 0) continue;  
			if (s.substr(start,dictionary[j].size()) != dictionary[j]) continue; 
			if (start > 0 && dp[start] == 0) continue; 
			dp[i] = 1; 
			ans = i; 
			break; 
		}
	}
	fout << ans << endl; 
	return 0; 
}
