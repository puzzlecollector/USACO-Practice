/*
ID: mkim142
LANG: C++
TASK: barn1 
*/
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <fstream> 
#include <queue> 
using namespace std;  
int M,S,C;  
int a[222];  
int main(){
	ifstream fin("barn1.in");  
	ofstream fout("barn1.out");  
	fin >> M >> S >> C; 
	for (int i = 0; i < C; i++){
		fin >> a[i]; 
	}
	sort(a,a+C);  
	int total = a[C-1]-a[0]+1;  
	// get the differences  
	priority_queue<int,vector<int>,less<int> > pq;  
	for (int i = 0; i < C-1; i++){
		pq.push(a[i+1]-a[i]);  
	}
	int greedy_uncovered = 0; 
	for (int i = 0; i < M-1; i++){
		if (pq.empty()) break; // safety check  
		greedy_uncovered += pq.top()-1; 
		pq.pop();  
	}
	int total_covered = total-greedy_uncovered; 
	fout << total_covered << endl; 
	return 0;  
}
