#include <iostream>
#include <cstdio> 
#include <cmath> 
#include <cstdlib>
#include <algorithm> 
using namespace std; 

int R,C,cnt; 
char grid[16][16];  

void recur(int startR, int startC){
	if (startR == R-1 && startC == C-1){
		++cnt; 
		return; 
	}
	for (int i = 1; i < R; i++){
		for (int j = 1; j < C; j++){
			if (startR+i < R && startC+j < C && grid[startR][startC] != grid[startR+i][startC+j]){
				recur(startR+i,startC+j);  
			}
		}
	}
}

int main(){
	cin >> R >> C; 
	for (int i = 0; i < R; i++){
		for (int j = 0; j < C; j++){
			cin >> grid[i][j];  
		}
	}
	recur(0,0);  
	cout << cnt << endl; 
	return 0; 
}
