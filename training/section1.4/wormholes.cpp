/*
ID: mkim142
LANG: C++
TASK: wormhole 
*/
// there is a very nice tutorial from Brian Dean available at : http://www.usaco.org/current/data/sol_wormhole.html
#include <iostream>
#include <fstream> 
#include <cstdlib>
#include <algorithm> 
#include <vector> 
using namespace std; 
#define MAXN 15 
int N,X[MAXN],Y[MAXN];  
int partner[MAXN]; 
int next_on_right[MAXN];  
bool cycle_exists(){
	for (int start = 1; start <= N; start++){
		int pos = start; 
		for (int cnt = 0; cnt < N; cnt++){
			pos = next_on_right[partner[pos]];  
		}
		if (pos != 0) return true;  
	}
	return false;  
}
int solve(){
	int i, total = 0; 
	for (i = 1; i <= N; i++){
		if (partner[i] == 0) break; 
	}
	// everyone paired? 
	if (i > N){
		if (cycle_exists()) return 1; 
		return 0;  
	}
	for (int j = i+1; j <= N; j++){
		if (partner[j] == 0){
			partner[i] = j; 
			partner[j] = i; 
			total += solve(); 
			partner[i] = partner[j] = 0;  
		}
	}
	return total; 
}
int main(){
	ifstream fin("wormhole.in");  
	ofstream fout("wormhole.out"); 
	fin >> N;  
	for (int i = 1; i <= N; i++){
		fin >> X[i] >> Y[i];  
	}
	fin.close(); 
	for (int i = 1; i <= N; i++){
		for (int j = 1; j <= N; j++){
			if (X[j] > X[i] && Y[i] == Y[j]){
				// j right of i 
				if (next_on_right[i] == 0 || 
					X[j]-X[i] < X[next_on_right[i]]-X[i]){
					next_on_right[i] = j;  
				}
			}
		}
	}
	fout << solve() << endl; 
	return 0; 
}
