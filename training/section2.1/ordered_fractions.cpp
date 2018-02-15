/*
ID: mkim142
LANG: C++
TASK: frac1 
*/
#include <iostream>
#include <fstream> 
#include <cstdlib>
#include <algorithm>
#include <vector> 
using namespace std; 
struct fr{ 
	int a,b; // this represents a/b 
	fr(){} 
	fr(int _a,int _b): a(_a),b(_b){}
};  	
bool cmp(fr &x,fr &y){
	return x.a*y.b < y.a*x.b;  
}
bool func(fr &x,fr &y){
	return (x.a == y.a && x.b == y.b); 
}
int gcd(int a,int b){
	if (b == 0) return a; 
	return gcd(b,a%b);  
}
int main(){
	ifstream fin("frac1.in"); 
	ofstream fout("frac1.out");  
	int n; 
	fin >> n; 
	vector<fr> v; 
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= i-1; j++){
			v.push_back(fr(j,i));  
		}
	}
	v.push_back(fr(0,1));  
	v.push_back(fr(1,1)); 
	sort(v.begin(),v.end(),cmp);  
	for (int i = 0; i < v.size(); i++){
		int g = gcd(v[i].a,v[i].b); 
		if (g == 0 || g == 1) continue;  
		v[i].a /= g; 
		v[i].b /= g;  
	}
	v.erase(unique(v.begin(),v.end(),func),v.end());  
	for (int i = 0; i < v.size(); i++){
		fout << v[i].a << "/" << v[i].b << endl; 
	}
	fin.close(); 
	fout.close(); 
	return 0;  
}
