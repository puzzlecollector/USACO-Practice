#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath> 
#include <vector> 
#include <map> 
#include <algorithm>
using namespace std; 

int baseRepresentation(int A, int n){
	int v1 = (A%10);  
	A /= 10;  
	int v2 = (A%10)*n; 
	A /= 10; 
	int v3 = (A)*n*n;  
	return (v1+v2+v3); 
}	

int main(){
	int k,A,B; 
	cin >> k; 
	for (int i = 0; i < k; i++){
		cin >> A >> B; 
		vector<int> v;  
		map<int,int> mp; 
		for (int j = 10; j <= 15000; j++){
			int val = baseRepresentation(A,j); 
			v.push_back(val); 
			mp[val] = j;    
		}
		for (int j = 10; j <= 15000; j++){
			int val = baseRepresentation(B,j); 
			if (binary_search(v.begin(),v.end(),val)){
				cout << mp[val] << " " << j << endl; 
				break; 
			}
		}
	}
	return 0; 
}
