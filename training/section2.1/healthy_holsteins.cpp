/*
ID: mkim142
LANG: C++
TASK: holstein 
*/
#include <iostream>
#include <fstream>
#include <algorithm> 
#include <vector> 
using namespace std;  
ifstream fin("holstein.in"); 
ofstream fout("holstein.out");  
const int INF = 2e9+11;
int minval = INF, minCnt = INF;    
int V,G; 
vector<int> a; 
vector<int> g[16];  
bool ok(vector<int> &x,vector<int> &y){
	// all elements of y must be geq all elements of x
	for (int i = 0; i < y.size(); i++){
		if (y[i] < x[i]) return false; 
	}
	return true; 
}
int bitCnt(int x){
	int cnt = 0; 
	while (x){
		cnt += x&1;  
		x >>= 1; 
	}
	return cnt;  
}
int solve(int i,vector<int> &b,int selected){
	if (i == G){
		if (ok(a,b)){
			if (bitCnt(selected) <= minCnt){
				if (bitCnt(selected) == minCnt){
					if (minval > selected){
						minval = selected; 
					}
				}else{
					minCnt = bitCnt(selected);  
					minval = selected;  
				}
			}
			return 0; 
		}
		return INF;  
	}
	int ret = solve(i+1,b,selected); 
	for (int j = 0; j < g[i].size(); j++){
		b[j] += g[i][j];  
	}
	ret = min(ret,1+solve(i+1,b,selected | (1<<i))); 
	for (int j = 0; j < g[i].size(); j++){
		b[j] -= g[i][j];  
	} 
	return ret; 
}
void produce_ans(int x){
	int cnt = 0, track = 0; 
	vector<int> chosen; 
	while (x){
		cnt += x&1; 
		if (x&1){
			chosen.push_back(track); 
		}
		x >>= 1; 
		track++;  
	}
	fout << cnt << " "; 
	for (int i = 0; i < chosen.size(); i++){
		if (i == chosen.size()-1) fout << chosen[i]+1 << endl;
		else fout << chosen[i]+1 << " ";   
	}
}
int main(){
	fin >> V; 
	a.reserve(V); 
	for (int i = 0; i < V; i++){
		fin >> a[i];  
	}
	fin >> G; 
	for (int i = 0; i < G; i++){
		for (int j = 0; j < V; j++){
			int x; 
			fin >> x; 
			g[i].push_back(x);  
		}
	}
	vector<int> b(V,0);  
	int ans = solve(0,b,0);  
	produce_ans(minval); 
	fin.close(); 
	fout.close(); 
	return 0; 
}
