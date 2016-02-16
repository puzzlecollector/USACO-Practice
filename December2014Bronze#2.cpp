// USACO Crosswords 
// let's just brute force. It will take no time as 
// the max size of the grid is 50x50
#include <iostream>
#include <cstdio> 
#include <cstdlib>
#include <algorithm> 
#include <cstdio> 
#include <vector> 
#include <utility> 
using namespace std; 

int main(){
	vector< pair<int,int> > coordinates; 
	char grid[52][52];  
	int n,m,x,y,cnt = 0; 
	cin >> n >> m; 
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			cin >> grid[i][j];  
		}
	}
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			if (grid[i][j] == '#') continue; 
			else if (grid[i][j] == '.'){
				bool horizontal = false, vertical = false; 
				x = i+1, y = j+1; 
				// check horizontal first 
				if ((j+2 < m) && ((j-1 < 0) || (grid[i][j-1] == '#')) && (grid[i][j+1] == '.' && grid[i][j+2] == '.')){
					horizontal = true; 
				}
				// check vertical next 
				if ((i+2 < n) && ((i-1 < 0) || (grid[i-1][j] == '#')) && (grid[i+1][j] == '.' && grid[i+2][j] == '.')){
					vertical = true;  
				}
				if (horizontal || vertical){
					coordinates.push_back(make_pair(x,y));  
					++cnt; 
				}
			}
		}
	}
	cout << cnt << endl; 
	for (int i = 0; i < coordinates.size(); i++){
		cout << coordinates[i].first << " " << coordinates[i].second << endl;   
	}
	return 0; 
}
