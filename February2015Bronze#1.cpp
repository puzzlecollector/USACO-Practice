#include <iostream>
#include <cstdlib> 
#include <string> 
using namespace std;  

int main(){
	string s,t; 
	cin >> s >> t;  
	string r = ""; 
	for (int i = 0; i < s.size(); i++){
		r += s[i]; 
		if (r.size() >= t.size() && r.substr(r.size()-t.size()) == t){
			// cutting off string from the end. 
			r.resize(r.size()-t.size());  
		}
	}
	cout << r << endl; 
	return 0; 
}
