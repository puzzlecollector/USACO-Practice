#include <iostream>
#include <cstdlib>
#include <algorithm>
using namespace std; 

int grid[205][205]; 
#define INF 987654321

int main(){
	int N,M,K,Q;  
	cin >> N >> M >> K >> Q; 
	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){
			if (i != j) grid[i][j] = INF; 
		}
	}
	for (int i = 0; i < M; i++){
		int from,to,cost; 
		cin >> from >> to >> cost; 
		--from, --to; 
		grid[from][to] = cost; // one way (directed) graph so no need to set grid[to][from] = cost; 
	}
	// process floyd-warshall algorithm 	
	for (int k = 0; k < N; k++){
		for (int i = 0; i < N; i++){
			for (int j = 0; j < N; j++){
				grid[i][j] = min(grid[i][j],grid[i][k]+grid[k][j]);  
			}
		}
	}
	// get input for trips
	long long totalCost = 0, validTrips = 0; // it is possible that the totalCost may result in an overflow. So use data type long long. 
	for (int i = 0; i < Q; i++){
		int from,to; 
		cin >> from >> to; 
		--from,--to; 
		int cost = INF; 
		for (int j = 0; j < K; j++){
			cost = min(cost,grid[from][j]+grid[j][to]);  
		}
		if (cost != INF){
			// i.e. if there exists a path for this trip. 
			// the cost for this trip calculated by floyd warshall must be minimum 
			// and it must also pass through at least one hub. 
			totalCost += cost; 
			++validTrips; 
		}
	}
	cout << validTrips << endl;
	cout << totalCost << endl; 
	return 0; 
}
