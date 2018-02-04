/*
ID: mkim142
LANG: C++
TASK: ariprog 
*/
#include <iostream>
#include <cstdlib>
#include <fstream> 
#include <set> 
#include <vector> 
#include <algorithm>
using namespace std; 
int n,m;  
int s[200000];  
bool chk(int a,int b){
	for (int i = 1; i <= n; i++){
		if (!s[a+(i-1)*b]) return false; 
	}	
	return true;  
}
int main(){
	ifstream fin("ariprog.in"); 
	ofstream fout("ariprog.out");  
	fin >> n >> m; 
	for (int i = 0; i <= m; i++){
		for (int j = 0; j <= m; j++){
			s[i*i+j*j] = 1;  
		}
	} 
  // actually we can improve this part! but whatever it still worked 
	vector< pair<int,int> > v;  
	for (int a = 0;a <= 2*m*m;a++){
		for (int b = 1;a+(n-1)*b <= 2*m*m;b++){
			if (chk(a,b)){
				v.push_back(make_pair(b,a));  
			}
		}
	}
	sort(v.begin(),v.end()); 
	if (v.empty()) fout << "NONE" << endl;
	else{
		for (int i = 0; i < v.size(); i++){
			fout << v[i].second << " " << v[i].first << endl; 
		}
	}
	return 0;  
}
