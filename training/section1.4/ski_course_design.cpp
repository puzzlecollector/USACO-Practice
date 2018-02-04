/*
ID: mkim142
LANG: C++
TASK: skidesign 
*/
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath> 
#include <fstream>
using namespace std; 
int h[1005]; 
const int INF = 987654321;  
int main(){
	ifstream fin("skidesign.in");  
	ofstream fout("skidesign.out");  
	int n; 	
	fin >> n; 
	int maxval = -1; 
	for (int i = 0; i < n; i++){
		fin >> h[i];
		maxval = max(maxval,h[i]);   
	}
	int mincost = INF; 
	for (int i = 0;; i++){
		int start = i, end = i+17; 
		if (end > maxval) break;
		int cost = 0; 
		for (int j = 0; j < n; j++){
			if (h[j] < start) cost += (start-h[j])*(start-h[j]); 
			else if (h[j] > end) cost += (end-h[j])*(end-h[j]); 
		}
		mincost = min(mincost,cost); 
	}
	fout << mincost << endl; 
	return 0;  
}
