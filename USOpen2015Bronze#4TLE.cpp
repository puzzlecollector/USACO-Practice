// receives time limit error if we search all possible paths and then pick palindromes. 
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <string> 
#include <vector> 
using namespace std; 

int N; 
char grid[19][19];  

bool isPalindrome(string s){
	string t = s; 
	reverse(t.begin(),t.end());  
	return (t == s); 
}


void dfs(int x, int y, vector<string>& v, string curr){
	if (x == N-1 && y == N-1){
		string t = curr+grid[x][y];  
		if (isPalindrome(t) && find(v.begin(),v.end(),t) == v.end()) v.push_back(t); 
		return; 
	}else{
		if (x+1 < N) dfs(x+1,y,v,curr+grid[x][y]);  
		if (y+1 < N) dfs(x,y+1,v,curr+grid[x][y]);  
	}
}

int main(){
	cin >> N; 
	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){
			cin >> grid[i][j];  
		}
	}
	vector<string> v; 
	dfs(0,0,v,""); 
	cout << v.size() << endl; 
	/*
	for (int i = 0; i < v.size(); i++){
		cout << v[i] << endl; 
	}*/ 
	return 0; 
}
