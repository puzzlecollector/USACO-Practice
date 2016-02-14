// This time, I implemented the actual binary serach instead of using STL 
// in this case, I don't have to create a map, thus I get to save memory. 
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

int binarySearch(vector<int>& v, int low, int high, int key){
	while (low <= high){
		int mid = (low+high)/2; 
		if (v[mid] == key) return mid; 
		else if (v[mid] < key) low = mid+1;  
		else if (v[mid] > key) high = mid-1;  
	}
	return -1;  
}

int main(){
	int k,A,B; 
	cin >> k; 
	for (int i = 0; i < k; i++){
		cin >> A >> B; 
		vector<int> v;  
		// map<int,int> mp; 
		for (int j = 10; j <= 15000; j++){
			int val = baseRepresentation(A,j); 
			v.push_back(val); 
			// mp[val] = j;    
		}
		for (int j = 10; j <= 15000; j++){
			int val = baseRepresentation(B,j); 
			int pos = binarySearch(v,0,(int)v.size()-1,val);  
			if (pos != -1){
				cout << pos+10 << " " << j << endl;
				break; 
			}
		}
	}
	return 0; 
}
