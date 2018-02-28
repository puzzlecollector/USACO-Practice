/*
ID: mkim142
LANG: C++
TASK: subset 
*/
#include <iostream>
#include <fstream> 
#include <cstdlib>
#include <cstring> 
#include <algorithm> 
using namespace std; 
int n,sum; 
int cache[41][801]; 
int cnt(int i,int trail){
	if (i == n+1) return 0; 
	if (trail == sum/2) return 1; 
	int &ret = cache[i][trail]; 
	if (ret != -1) return ret; 
	return ret = cnt(i+1,trail)+cnt(i+1,trail+i);  
}
int main(){
	ifstream fin("subset.in"); 
	ofstream fout("subset.out");  
	fin >> n; 
	sum = n*(n+1)/2; 
	if (sum%2 == 1) fout << 0 << endl; 
	else{
		memset(cache,-1,sizeof(cache)); 
		fout << cnt(1,0) << endl; 
	} 
  fin.close(); 
  fout.close();  
	return 0;  
}	
