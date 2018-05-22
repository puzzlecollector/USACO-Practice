/*
ID: mkim142
LANG: C++
TASK: lamps 
*/
#include <iostream>
#include <fstream>  
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <set> 
using namespace std; 
// bit: (1)(2)(3)(4) 
int seq[105]; 
int bitcnt(int x){
	int cnt = 0; 
	while (x){
		cnt += (x&1);  
		x >>= 1;  
	}
	return cnt;  
}
int main(){
	ifstream fin("lamps.in"); 
	ofstream fout("lamps.out");  
	int N,C; 
	fin >> N >> C; 
	int on,off; 
	vector<int> on_info, off_info;  
	while (1){
		fin >> on; 
		if (on == -1) break;
		on_info.push_back(on);    
	} 
	while (1){
		fin >> off; 
		if (off == -1) break; 
		off_info.push_back(off); 
	}
	set<string> ans; 
	for (int i = 0; i < (1<<4); i++){
		int x = i; 
		if ((bitcnt(x) > C) || ((C-bitcnt(x))%2 != 0)) continue; 
		for (int j = 1; j <= N; j++){
			seq[j] = 1;  
		}
		int idx = 0;  
		while (x){
			if (x&1){
				if (idx == 0){
					for (int j = 1; j <= N; j += 3){
						seq[j] = (seq[j] == 0 ? 1 : 0); 
					}
				}else if (idx == 1){
					for (int j = 2; j <= N; j += 2){
						seq[j] = (seq[j] == 0 ? 1 : 0);  
					}
				}else if (idx == 2){
					for (int j = 1; j <= N; j += 2){
						seq[j] = (seq[j] == 0 ? 1 : 0); 
					}
				}else if (idx == 3){
					for (int j = 1; j <= N; j++){
						seq[j] = (seq[j] == 0 ? 1 : 0); 
					}
				}
			}
			x >>= 1;  
			idx++; 
		}
		bool pass = true; 
		for (int j = 0; j < on_info.size(); j++){
			if (!seq[on_info[j]]) pass = false; 
		}
		if (!pass) continue; 
		for (int j = 0; j < off_info.size(); j++){
			if (seq[off_info[j]]) pass = false;  
		}
		if (!pass) continue;  
		string t = ""; 
		for (int j = 1; j <= N; j++){
			t += (seq[j] == 1 ? "1" : "0");  
		}	
		ans.insert(t); 
	}
	if (ans.empty()){
		fout << "IMPOSSIBLE" << endl; 
	}else{
		for (set<string>::iterator it = ans.begin(); it != ans.end(); it++){
			fout << *it << endl; 
		}
	}
	return 0;  
}
