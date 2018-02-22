/*
ID: mkim142
LANG: C++
TASK: hamming 
*/
#include <iostream>
#include <fstream> 
#include <cstdlib>
#include <cstring> 
#include <algorithm>
#include <vector> 
#include <set> 
using namespace std;
#define IOFAST() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); 
int N,B,D;  
int hamming(int x,int y){
	int z = x^y; 
	int cnt = 0;  
	while (z){
		cnt += (z&1); 
		z >>= 1; 
	}
	return cnt; 
}
int main(){
	ifstream fin("hamming.in"); 
	ofstream fout("hamming.out"); 
	fin >> N >> B >> D; 
	vector<int> v; 
	v.push_back(0); 
	for (int i = 1; i < (1<<B); i++){
		bool passed_test = true; 
		for (int j = 0; j < v.size(); j++){
			if (hamming(v[j],i) < D){
				passed_test = false; 
				break;  
			}
		}
		if (passed_test){
			v.push_back(i);  
		}
	}
	for (int i = 0,temp = 1; i < N; i++,temp++){
		if (temp == 10){
			fout << v[i] << endl; 
			temp = 0; 
		}else if (i == N-1){
			fout << v[i] << endl; 
		}else{
			fout << v[i] << " "; 
		}
	}
	fin.close(); 
	fout.close(); 
	return 0;  
} 
