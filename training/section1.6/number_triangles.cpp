/*
ID: mkim142
LANG: C++
TASK: numtri 
*/
#include <iostream>
#include <fstream> 
#include <cstdlib>
#include <cstring> 
#include <algorithm> 
using namespace std; 
int n; 
int a[1001][1001]; 
int cache[1001][1001]; 
int solve(int x,int y){
	if (x == n) return 0;  
	int &ret = cache[x][y]; 
	if (ret != -1) return ret;  
	return ret = a[x][y]+max(solve(x+1,y),solve(x+1,y+1));  
}
int main(){
	ifstream fin("numtri.in"); 
	ofstream fout("numtri.out");  
	fin >> n; 
	for (int i = 1; i <= n; i++){
		for (int j = 0; j < i; j++){
			fin >> a[i-1][j];  
		}
	}
	memset(cache,-1,sizeof(cache));  
	int ans = solve(0,0);  
	fout << ans << endl; 
	fin.close(); 
	fout.close(); 
	return 0; 
}
