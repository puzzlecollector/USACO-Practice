#include <iostream>
#include <cstdlib>
#include <vector> 
#include <utility> 
#include <map> 
#include <algorithm> 
using namespace std;  

#define MAXN 100010
#define INF 1000000010

int main(){
	int n; 
	cin >> n; 
	vector< pair<int,char> > a(n);  
	for (int i = 0; i < n; i++){
		cin >> a[i].first >> a[i].second; 
	}
	sort(a.begin(),a.end()); // sorts according to a[i].first.  
	int ps = 0;  
	int result = 0; 
	vector< pair<int,int> > v[2]; // partialsum,pos
	for (int i = 0; i < n; i++){
		if (v[ps&1].empty() || v[ps&1].back().first < ps){
			v[ps&1].push_back(make_pair(ps,a[i].first));   
		}
		ps += (a[i].second == 'W' ? -1 : 1);  
		if (!v[ps&1].empty() && ps <= v[ps&1].back().first){
			result = max(result,a[i].first-lower_bound(v[ps&1].begin(),v[ps&1].end(),make_pair(ps,-INF))->second); 
		}
	}
	cout << result << endl;
	return 0; 
}
