/*
ID: mkim142
LANG: C++
TASK: sprime  
*/
#include <iostream>
#include <cstdlib>
#include <cmath> 
#include <algorithm>
#include <vector>
#include <fstream>
using namespace std; 
bool isPrime(int x){
	for (int i = 2; i*i <= x; i++){
		if (x%i == 0) return false; 
	}
	return x != 1;  
}
bool test(int x){
	if (x == 0) return false;  
	while (x){
		if (!isPrime(x)) return false; 
		x /= 10;  
	}
	return true; 
}
int n; 
vector<int> init; 
vector<int> trail;  
ifstream fin("sprime.in");  
ofstream fout("sprime.out");  
void dfs(int i,int q,int x){
	if (i == n+1){
		if (test(q)) fout << q << endl;
		return;   
	}
	if (i == 1){
		for (int j = 0; j < init.size(); j++){
			dfs(i+1,q+init[j]*pow(10,x-1),x-1); 
		}
	}else{
		for (int j = 0; j < trail.size(); j++){
			dfs(i+1,q+trail[j]*pow(10,x-1),x-1);  
		}
	}
}
int main(){
	fin >> n;  // 1 <= n <= 8
	init.push_back(1);  
	init.push_back(2); 
	init.push_back(3); 
	init.push_back(5); 
	init.push_back(7); 
	trail.push_back(1); 
	trail.push_back(3); 
	trail.push_back(7); 
	trail.push_back(9);  
	dfs(1,0,n); 
	fin.close(); 
	fout.close(); 
	return 0;  
}
