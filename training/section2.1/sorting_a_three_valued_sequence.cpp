/*
ID: mkim142
LANG: C++
TASK: sort3 
*/
#include <iostream>
#include <fstream> 
#include <cstdlib>
#include <algorithm> 
using namespace std; 
int a[1001],b[1001]; 
int main(){	
	ifstream fin("sort3.in"); 
	ofstream fout("sort3.out"); 
	int n; 
	fin >> n; 
	for (int i = 0; i < n; i++){
		fin >> a[i]; 
		b[i] = a[i]; 
	}
	sort(b,b+n); 
	int cnt = 0; 
	for (int i = 0; i < n; i++){
		if (a[i] != b[i]){
			for (int j = i+1; j < n; j++){
				if (a[j] == b[i] && a[i] == b[j]){
					cnt++; 
					swap(a[i],a[j]); 
					break; 
				}
			}
		}
	}
	for (int i = 0; i < n; i++){
		if (b[i] != a[i] && a[i] == 1){
			cnt += 2;  // Swap 1 and 2. Then swap 2 and 3.  
		}
	}
	fout << cnt << endl; 
	fin.close(); 
	fout.close(); 
	return 0;  
}
