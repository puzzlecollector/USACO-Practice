/*
ID: mkim142
LANG: C++
TASK: gift1
*/
#include <iostream>
#include <fstream> 
#include <cstdlib>
#include <algorithm>
#include <map> 
#include <vector> 
using namespace std; 
int main(){
	ifstream fin("gift1.in"); 
	ofstream fout("gift1.out");  
	int n; 
	fin >> n; 
	map<string,int> mp; 
	vector<string> v; 
	for (int i = 0; i < n; i++){
		string name; 
		fin >> name; 
		v.push_back(name); 
		mp[name] = 0; 
	}
	for (int i = 0; i < n; i++){
		string sender; 
		fin >> sender; 
		int x,k;  // x: money, k: to whom
		fin >> x >> k; 
		for (int i = 0; i < k; i++){
			string recipient;  
			fin >> recipient; 
			mp[recipient] += x/k; 
		}
		if (x != 0){
			mp[sender] -= x; // decreased by money given 
			mp[sender] += x%k; 
		} 
	}
	for (int i = 0; i < v.size(); i++){
		fout << v[i] << " " << mp[v[i]] << endl; 
	}
	return 0;  
}
