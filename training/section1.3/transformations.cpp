/*
ID: mkim142
LANG: C++
TASK: transform 
*/
#include <iostream>
#include <cstdlib>
#include <algorithm> 
#include <vector> 
#include <fstream> 
using namespace std;  
#define MAXN 11 
int n; // dimension of the grid 
char grid[MAXN][MAXN];  
char target[MAXN][MAXN]; 
void rotate_90_degrees_cw(char a[MAXN][MAXN]){
	int layers = n/2;  
	for (int i = 0; i < layers; i++){
		int first = i, last = n-first-1; 
		for (int j = first; j < last; j++){
			int offset = j-first; 
			char top = a[first][j]; 
			char right = a[j][last];  
			char bottom = a[last][last-offset];  
			char left = a[last-offset][first];  
			// move 
			a[first][j] = left; 
			a[j][last] = top;  
			a[last][last-offset] = right;  
			a[last-offset][first] = bottom;  
		}
	}
}
bool equal(char a[MAXN][MAXN],char b[MAXN][MAXN]){
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			if (a[i][j] != b[i][j]) return false; 
		}
	}
	return true; 
}
void reflect(char a[MAXN][MAXN]){
	for (int i = 0; i < n; i++){
		reverse(a[i],a[i]+n);  
	}
}
int main(){
	ifstream fin("transform.in");  
	ofstream fout("transform.out"); 
	fin >> n; 
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			fin >> grid[i][j]; 
		}
	}
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			fin >> target[i][j]; 
		}
	}
	int ans = MAXN;
	if (equal(grid,target)){
		// No Change 
		ans = min(ans,6);  
	}
	// rotate 90 degrees 
	rotate_90_degrees_cw(grid);  
	if (equal(grid,target)){
		ans = min(ans,1);
	}
	// rotate 180 degrees  
	rotate_90_degrees_cw(grid); 
	if (equal(grid,target)){
		ans = min(ans,2);
	}
	// rotate 270 degrees 
	rotate_90_degrees_cw(grid);  
	if (equal(grid,target)){
		ans = min(ans,3);
	}
	// reflected then rotation 
	rotate_90_degrees_cw(grid); // set the grid back to initial position. 
	reflect(grid); // reflect the grid 
	if (equal(grid,target)){
		ans = min(ans,4);
	}
	rotate_90_degrees_cw(grid); // 90 degrees rotation 
	if (equal(grid,target)){
		ans = min(ans,5); 
	}
	rotate_90_degrees_cw(grid);  // 180 degrees rotation 
	if (equal(grid,target)){
		ans = min(ans,5); 
	}
	rotate_90_degrees_cw(grid); // 270 degrees rotation 
	if (equal(grid,target)){
		ans = min(ans,5);  
	}
	ans = min(ans,7); // invalid transformation 
	fout << ans << endl;
	return 0;  
}
