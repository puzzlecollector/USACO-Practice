/*
ID: mkim142
LANG: C++
TASK: namenum 
*/
#include <iostream>
#include <cstdlib>
#include <vector> 
#include <set> 
#include <algorithm> 
#include <fstream> 
using namespace std; 
set<string> nameList; 
string no;  
void dfs(vector<string> &ans,string k,int i){ // at most 3^12 calculations 
	if (i == no.size() && nameList.count(k)){
		ans.push_back(k); 
		return;  
	}
	if (no[i] == '2'){
		dfs(ans,k+"A",i+1);  
		dfs(ans,k+"B",i+1);  
		dfs(ans,k+"C",i+1);  
	}else if (no[i] == '3'){
		dfs(ans,k+"D",i+1); 
		dfs(ans,k+"E",i+1); 
		dfs(ans,k+"F",i+1); 
	}else if (no[i] == '4'){
		dfs(ans,k+"G",i+1);  
		dfs(ans,k+"H",i+1);  
		dfs(ans,k+"I",i+1);  
	}else if (no[i] == '5'){
		dfs(ans,k+"J",i+1);  
		dfs(ans,k+"K",i+1);  
		dfs(ans,k+"L",i+1); 
	}else if (no[i] == '6'){
		dfs(ans,k+"M",i+1); 
		dfs(ans,k+"N",i+1); 
		dfs(ans,k+"O",i+1); 
	}else if (no[i] == '7'){
		dfs(ans,k+"P",i+1); 
		dfs(ans,k+"R",i+1);  
		dfs(ans,k+"S",i+1); 
	}else if (no[i] == '8'){
		dfs(ans,k+"T",i+1); 
		dfs(ans,k+"U",i+1);  
		dfs(ans,k+"V",i+1); 
	}else if (no[i] == '9'){
		dfs(ans,k+"W",i+1);  
		dfs(ans,k+"X",i+1);  
		dfs(ans,k+"Y",i+1);  
	}
}
int main(){
	ifstream datain("dict.txt");  
	string name; // get names from dict.txt.   
	while (datain >> name){
		nameList.insert(name); 
	}
	ifstream fin("namenum.in"); 
	ofstream fout("namenum.out");  
	fin >> no; 
	vector<string> ans;  
	dfs(ans,"",0);  
	if (ans.empty()){
		fout << "NONE" << endl; 
	}else{
		sort(ans.begin(),ans.end()); 
		for (int i = 0; i < ans.size(); i++){
			fout << ans[i] << endl; 
		} 
	}
	return 0; 
}
