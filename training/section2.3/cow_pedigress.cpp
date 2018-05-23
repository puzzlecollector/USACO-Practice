/*
ID: mkim142
LANG: C++
TASK: nocows 
*/
const int mod = 9901;  
#include <iostream>
#include <fstream> 
#include <cstdlib>
#include <algorithm>
#include <cstring> 
using namespace std;  
int cache[205][205]; 
int solve(int a,int b){
	if (a == 0 || b == 0) return 0;  
	if (a == 1) return 1; 
	int &ret = cache[a][b]; 
	if (ret != -1) return ret;  
	ret = 0; 
	for (int i = 1; i < a-1; i++){
		ret = (ret + solve(i,b-1)*solve(a-i-1,b-1))%mod; 
	}
	return ret;  
}
int main(){
	ifstream fin("nocows.in"); 
	ofstream fout("nocows.out"); 
	int N,K; 
	fin >> N >> K;  
	memset(cache,-1,sizeof(cache)); 
	int ans = (solve(N,K)-solve(N,K-1)+mod)%mod; 
	fout << ans << endl; 
	return 0;  
}
