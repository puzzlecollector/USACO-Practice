/*
speed = distance/time
distance = speed * time 
time = distance/speed 
*/

#include <iostream>
#include <cstdlib>
#include <deque> 
#include <cmath> 
#include <algorithm> 
#include <utility> 
using namespace std;  

typedef pair<char,int> P; 
#define mp make_pair
#define pb push_back

int main(){
	deque<double> DistanceInfo; 
	deque<double> TimeInfo;  
	double speed = 1.0, curD = 0.0, curT = 0.0,num;   
	char c; 
	int N; 
	cin >> N;  
	for (int i = 0; i < N; i++){
		cin >> c >> num;
		if (c == 'D'){
			DistanceInfo.pb(num); 
		}else if (c == 'T'){
			TimeInfo.pb(num);  
		}
	}
	DistanceInfo.pb(1000);  
	while (DistanceInfo.size() > 0 || TimeInfo.size() > 0){
		bool nextComesTime = false; 
		if (DistanceInfo.empty()){
			nextComesTime = true; 
		}else if (!DistanceInfo.empty() && !TimeInfo.empty()){
			if (TimeInfo.front() < curT + (DistanceInfo.front()-curD)*speed){
				nextComesTime = true;  
			}
		}
		if (nextComesTime){
			curD += (TimeInfo.front()-curT)/speed;  
			curT = TimeInfo.front(); 
			TimeInfo.pop_front(); 
		}else{
			curT += (DistanceInfo.front()-curD)*speed; 
			curD = DistanceInfo.front(); 
			DistanceInfo.pop_front(); 
		}
		++speed; 
	}
	cout << ceil(curT) << endl; 
	return 0; 
}
