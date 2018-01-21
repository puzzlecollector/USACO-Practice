/*
ID: mkim142
LANG: C++
TASK: milk2
*/
#include <iostream>
#include <algorithm>
#include <fstream>
#include <cstdlib> 
using namespace std; 
typedef pair<int,int> P;  
P a[5555]; 
const int INF = 987654321;  
int main(){
	ifstream fin("milk2.in"); 
	ofstream fout("milk2.out");  
	int n; 
	fin >> n;  
	for (int i = 0; i < n; i++){
		fin >> a[i].first >> a[i].second;  
	}
	sort(a,a+n); 
	int idle = 0, active = 0; 
	int continuous = 0; 
	int prev_time = INF;    
	for (int i = 0; i < n; i++){
		if (a[i].first <= prev_time){ // there is a continuous milking process going on 
			if (i == 0){
				continuous += a[i].second-a[i].first; 
				prev_time = a[i].second; 
			}else{
				if (prev_time < a[i].second){
					continuous += (a[i].second-a[i].first)-(prev_time-a[i].first);  
					prev_time = a[i].second; 
				}
			}
		}else if (a[i].first > prev_time){ // continouous milking process ended 
			idle = max(idle,a[i].first-prev_time);  
			// adjust prev_time 
			prev_time = a[i].second;
			// adjust continous milking time   
			continuous = a[i].second-a[i].first; 
		}
		active = max(active,continuous);   
	}
	fout << active << " " << idle << endl; 
	return 0; 
}
