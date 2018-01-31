/*
ID: mkim142
LANG: C++
TASK: crypt1 
*/
#include <iostream> 
#include <cstdlib>
#include <algorithm> 
#include <cstring> 
#include <vector> 
#include <fstream> 
using namespace std; 
#define IOFAST() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); 
int present[10];  
bool chk(int x){
	// x is nonzero 
	while (x){
		if (!present[x%10]) return false; 
		x /= 10;   
	}
	return true;  
}
int len(int x){
	int cnt = 0; 
	while (x){
		cnt++; 
		x /= 10; 
	}
	return cnt;  
}
// brute force search 
int dfs(vector<int> &v,int i,int a,int b,int c,int d,int e){
	if (i == 5){
		int foo = a*100+b*10+c;   
		int foo2 = d*10+e;  
		int bar = foo*e;  // abc*e 
		if (!chk(bar) || (len(bar) > 3)) return 0;  
		int baz = foo*d; // abc*d 
		if (!chk(baz) || (len(baz) > 3)) return 0; 
		int qux = baz*10+bar;  
		if (!chk(qux) || (len(qux) > 4)) return 0;  
		return 1; // if we passed all tests 
	}
	int res = 0;  
	for (int j = 0; j < v.size(); j++){
		if (i == 0){
			res += dfs(v,i+1,v[j],b,c,d,e); 
		}else if (i == 1){
			res += dfs(v,i+1,a,v[j],c,d,e);  
		}else if (i == 2){
			res += dfs(v,i+1,a,b,v[j],d,e);  
		}else if (i == 3){
			res += dfs(v,i+1,a,b,c,v[j],e); 
		}else if (i == 4){
			res += dfs(v,i+1,a,b,c,d,v[j]); 
		}
	}
	return res;  
}
int main(){
	IOFAST(); 
	ifstream fin("crypt1.in"); 
	ofstream fout("crypt1.out"); 
	int n; 
	fin >> n; 
	vector<int> v(n); 
	for (int i = 0; i < n; i++){ // n separated non-zero digits given  
		fin >> v[i]; 
		present[v[i]] = 1;  
	}  
	int ans = dfs(v,0,0,0,0,0,0);  
	fout << ans << endl; 
	return 0;  
}
