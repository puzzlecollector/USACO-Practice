// pos is given in increasing order. 
// we actually don't have to care about pos as they are all in distinct order as well. 
#include <iostream> 
#include <cstdlib> 
#include <cstdio> 
#include <algorithm> 
using namespace std; 

typedef long long ll; 
ll a[100001];  

int main(){
	int n,group = 1; 
	ll pos;  
	cin >> n; 
	for (int i = 0; i < n; i++){
		cin >> pos >> a[i];  
	}
	ll comp = a[n-1];  
	for (int i = n-2; i >= 0; i--){
		if (a[i] > comp){
			continue;  // cows group 
		}else{
			++group; 
		}
		comp = min(comp,a[i]);  
	}
	cout << group << endl; 
	return 0; 
}
