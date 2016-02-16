// I accidentally named fields villages...well whatever. 
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <climits> 
using namespace std;

int BessieTime[17][17], ElsieTime[17][17];  
int BessieCanReach[20000], ElsieCanReach[20000];  
int n,m,x,y; 

void chkBessie(int currentVillage, int Time){
	if (currentVillage == n){
		// if we reached the nth village 
		// Bessie can reach the destination using time Time.  
		BessieCanReach[Time] = 1;  
		return;  
	}
	for (int i = currentVillage+1; i <= n; i++){
		if (BessieTime[currentVillage][i] > 0){
			chkBessie(i,Time+BessieTime[currentVillage][i]);  
		}
	}
} 

void chkElsie(int currentVillage, int Time){
	if (currentVillage == n){
		ElsieCanReach[Time] = 1; 
		return; 
	}
	for (int i = currentVillage+1; i <= n; i++){
		if (ElsieTime[currentVillage][i] > 0){
			chkElsie(i,Time+ElsieTime[currentVillage][i]);  
		}
	}
}
	
int main(){	
	cin >> n >> m; 
	for (int i = 0; i < m; i++){
		cin >> x >> y; // enter villages 
		cin >> BessieTime[x][y] >> ElsieTime[x][y]; 
	}	
	chkBessie(1,0);  
	chkElsie(1,0);  
	int ans = -1;  
	for (int i = 0; i < 20000; i++){
		if (BessieCanReach[i] && ElsieCanReach[i]){
			ans = i; 
			break; 
		}
	}
	if (ans == -1) cout << "IMPOSSIBLE" << endl; 
	else cout << ans << endl; 
	return 0; 	
}
