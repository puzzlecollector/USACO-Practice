/*
ID: mkim142
LANG: C++
TASK: milk 
*/
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <fstream>
using namespace std; 
typedef pair<int,int> P;  
int N,M;  
P f[5005]; 
int main(){
	ifstream fin("milk.in"); 
	ofstream fout("milk.out");  
	fin >> N >> M;  
	for (int i = 0; i < M; i++){
		fin >> f[i].first >> f[i].second;   
	}
	sort(f,f+M); // sorted according to increasing values of p
	int minPrice = 0; 
	for (int i = 0; i < M; i++){
		if (f[i].second <= N){
			minPrice += f[i].first*f[i].second; 
			N -= f[i].second; 
		}else{
			minPrice += f[i].first*N;  
			N = 0;  
		}
	}
	fout << minPrice << endl; 
	return 0; 
}
