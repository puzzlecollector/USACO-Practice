/*
ID: mkim142
LANG: C++
TASK: milk3
*/
#include <iostream>
#include <cstdlib>
#include <algorithm> 
#include <vector>
#include <queue> 
#include <fstream> 
#include <set> 
using namespace std; 
int A,B,C; 
int main(){
	ifstream fin("milk3.in"); 
	ofstream fout("milk3.out"); 
	fin >> A >> B >> C; 
	vector<int> cap(3); // capacities in buckets A,B and C 
	cap[0] = cap[1] = 0;  
	cap[2] = C;  
	queue< vector<int> > q; 
	q.push(cap); 
	set< vector<int> > visited; 
	visited.insert(cap); 
	vector<int> ans;  // list of answers 
	while (!q.empty()){
		vector<int> cur = q.front(); q.pop();
		vector<int> buffer = cur;  
		if (cur[0] == 0){
			ans.push_back(cur[2]); 
		}
		int move = 0; 
		if (cur[0] != 0){
			// pour from a to b 	
			move = min(B-cur[1],cur[0]);   
			cur[0] -= move; 
			cur[1] += move;  
			if (!visited.count(cur)){
				visited.insert(cur);  
				q.push(cur);  
			}
			cur = buffer;  
			// pour from a to c 
			move = min(C-cur[2],cur[0]);  
			cur[0] -= move;  
			cur[2] += move;  
			if (!visited.count(cur)){
				visited.insert(cur); 
				q.push(cur); 
			}
			cur = buffer; 
		}
		if (cur[1] != 0){
			// pour from b to a 	
			move = min(A-cur[0],cur[1]);  
			cur[1] -= move;  
			cur[0] += move;   
			if (!visited.count(cur)){
				visited.insert(cur);  
				q.push(cur);  
			}
			cur = buffer;  
			// pour from b to c 
			move = min(C-cur[2],cur[1]); 
			cur[1] -= move; 
			cur[2] += move; 
			if (!visited.count(cur)){
				visited.insert(cur); 
				q.push(cur); 
			}
			cur = buffer; 
		}
		if (cur[2] != 0){
			// pour from c to a 
			move = min(A-cur[0],cur[2]); 
			cur[2] -= move;  
			cur[0] += move; 
			if (!visited.count(cur)){
				visited.insert(cur); 
				q.push(cur); 
			}
			cur = buffer;  
			// pour from c to b  
			move = min(B-cur[1],cur[2]);  
			cur[2] -= move;  
			cur[2] += move; 
			if (!visited.count(cur)){
				visited.insert(cur); 
				q.push(cur); 
			}
			cur = buffer; 
		}	
	}
	sort(ans.begin(),ans.end());  
	for (int i = 0; i < ans.size(); i++){
		if (i == ans.size()-1) fout << ans[i] << endl; 	
		else fout << ans[i] << " "; 
 	}
	return 0; 
}
