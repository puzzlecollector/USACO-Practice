#include <iostream>
#include <cstdlib> 
#include <cstdio> 
#include <algorithm> 
#include <utility> 
using namespace std;

int N,size,position; 
pair<int,int> a[4001];   

int main(){
	scanf("%d\n",&N);  
	for (int i = 0; i < N; i++){
		// get input this way so that it's easier to sort.  
		scanf("%d%d",&a[i].second,&a[i].first);  
	}
	sort(a,a+N);   
	int ans = 0; 
	for (int i = 0; i < N-1; i++){
		int area = a[i+1].first-a[i].first; 
		int leftMost = i, rightMost = i+1;  
		while (leftMost >= 0 && rightMost <= N-1){
			bool broke = false; 
			int currentDistance = a[rightMost].first - a[leftMost].first; 
			if (currentDistance > a[leftMost].second){
				--leftMost;  
				broke = true;  
			}
			if (currentDistance > a[rightMost].second){
				++rightMost; 
				broke = true; 
			}
			if (!broke){
				// Bessie could not escape from the haybales, so there is no point 
				// in continuing.  
				break;  
			}
		}
		if (leftMost >= 0 && rightMost <= N-1){
			// sum of areas that bessie could not break out from. 
			ans += area; 
		}
	}
	printf("%d\n",ans);  
	return 0; 
}
