// https://www.acmicpc.net/problem/10675
#include <iostream> 
#include <cstdio> 
#include <climits> 
#include <algorithm> 
using namespace std; 

int A,B,N,cost,numCities,city,TravelValue = 5000; 

int main(){
	cin >> A >> B >> N; 
	for (int i = 0; i < N; i++){
		bool flag1 = false, flag2 = false;  
		cin >> cost >> numCities; 
		for (int j = 0; j < numCities; j++){
			cin >> city; 
			if (city == A) flag1 = true; 
			else if (city == B && flag1) flag2 = true; 
		}
		if (flag1 && flag2) TravelValue = min(TravelValue,cost); 
	}
	cout << (TravelValue == 5000 ? -1:TravelValue) << endl; 
	return 0; 
}
