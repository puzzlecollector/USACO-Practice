/*
ID: mkim142
LANG: C++
TASK: beads
*/
#include <iostream>
#include <fstream> 
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;  
const int INF = 987654321;  
int main(){
	ifstream fin("beads.in"); 
	ofstream fout("beads.out"); 
	int n; 
	fin >> n; 
	string s; 
	fin >> s; 
	int ans = -INF;  
	for (int cut = 0; cut < s.size(); cut++){
		int i = cut-1, j = cut;  
		if (i < 0) i = s.size()-1;  
		int cnt = 0; // our counter variable for each cut we make 
		// iterate for i 
		char left_fixed = s[i]; 
		cnt++; // we are counting the first bead of left segment   
		char right_fixed = s[j]; 
		cnt++; // we are counting the first bead of right segment 
		bool stop_i = false; // when we have encountered a different bead on left, halt 
		bool stop_j = false; // when we have encountered a different bead on right, halt 
		while (true){
			if (stop_i && stop_j) break; // no point of moving anymore 
			// take care of i 
			if (!stop_i) i--; 
			if (i < 0) i = s.size()-1; 
			if (i == j) break; 
			if (left_fixed == 'w'){
				left_fixed = s[i]; 
				cnt++; 
			}else if (left_fixed == s[i]){
				cnt++; 
			}else if (s[i] == 'w' && left_fixed != s[i]){
				cnt++; 
			}else if (s[i] != 'w' && left_fixed != s[i]){
				stop_i = true; 
			}
			// take care of j 
			if (!stop_j) j++; 
			if (j > s.size()-1) j = 0;
			if (i == j) break; 
			if (right_fixed == 'w'){
				right_fixed = s[j]; 
				cnt++; 
			}else if (right_fixed == s[j]){
				cnt++; 
			}else if (s[j] == 'w' && right_fixed != s[j]){
				cnt++; 
			}else if (s[j] != 'w' && right_fixed != s[j]){
				stop_j = true; 
			}
		}
		ans = max(ans,cnt); 
	}
	fout << ans << endl; 
	return 0;  
}
