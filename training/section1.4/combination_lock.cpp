/*
ID: mkim142
LANG: C++
TASK: combo
*/
#include <iostream>
#include <fstream> 
#include <cstdlib>
#include <vector> 
#include <algorithm>
#include <set> 
using namespace std; 
struct combination{
	int a,b,c; 
	combination() {}
	combination(int _a,int _b,int _c): a(_a), b(_b), c(_c) {}
	inline bool operator < (const combination &comb) const {
		return a < comb.a && b < comb.b && c < comb.c;  
	}
};  
// it's not clever, but we may brute force again 
vector<int> jl,jm,jr; // for john 
vector<int> ll,lm,lr; // for locksmith 
void dfs(set< vector<int> > &st,int i,int type,int x,int y,int z){
	if (i == 3){ 
		vector<int> t; 
		t.push_back(x); 
		t.push_back(y); 
		t.push_back(z); 
		st.insert(t); 
		return; 
	}
	if (type == 0){ // if type is 0, then we are looking at John's case 
		if (i == 0){
			for (int j = 0; j < jl.size(); j++){
				dfs(st,i+1,type,jl[j],y,z); 
			}
		}else if (i == 1){
			for (int j = 0; j < jm.size(); j++){
				dfs(st,i+1,type,x,jm[j],z);  
			}
		}else if (i == 2){
			for (int j = 0; j < jr.size(); j++){
				dfs(st,i+1,type,x,y,jr[j]);  
			}
		}
	}else if (type == 1){ // if type is 1 then we are looking at locksmith's case 
		if (i == 0){
			for (int j = 0; j < ll.size(); j++){
				dfs(st,i+1,type,ll[j],y,z); 
			}
		}else if (i == 1){
			for (int j = 0; j < lm.size(); j++){
				dfs(st,i+1,type,x,lm[j],z); 
			}
		}else if (i == 2){
			for (int j = 0; j < lr.size(); j++){
				dfs(st,i+1,type,x,y,lr[j]);  
			}
		}
	}
}
int main(){
	ifstream fin("combo.in"); 
	ofstream fout("combo.out"); 
	int n; 
	fin >> n;  
	vector<int> john(3), locksmith(3);  
	fin >> john[0] >> john[1] >> john[2];  
	fin >> locksmith[0] >> locksmith[1] >> locksmith[2];
	for (int i = 0; i < 3; i++){
		if (i == 0){
			// fill jl 
			jl.push_back(john[0]);  	
			jl.push_back((john[0]-1+n)%n == 0 ? n :(john[0]-1+n)%n);  
			jl.push_back((john[0]-2+n)%n == 0 ? n :(john[0]-2+n)%n);  
			jl.push_back((john[0]+1)%n == 0 ? n : (john[0]+1)%n); 
			jl.push_back((john[0]+2)%n == 0 ? n : (john[0]+2)%n);  
			// fill  ll  
			ll.push_back(locksmith[0]);  	
			ll.push_back((locksmith[0]-1+n)%n == 0 ? n :(locksmith[0]-1+n)%n);  
			ll.push_back((locksmith[0]-2+n)%n == 0 ? n :(locksmith[0]-2+n)%n);  
			ll.push_back((locksmith[0]+1)%n == 0 ? n : (locksmith[0]+1)%n); 
			ll.push_back((locksmith[0]+2)%n == 0 ? n : (locksmith[0]+2)%n); 
		}else if (i == 1){
			jm.push_back(john[1]);  	
			jm.push_back((john[1]-1+n)%n == 0 ? n :(john[1]-1+n)%n);  
			jm.push_back((john[1]-2+n)%n == 0 ? n :(john[1]-2+n)%n);  
			jm.push_back((john[1]+1)%n == 0 ? n : (john[1]+1)%n); 
			jm.push_back((john[1]+2)%n == 0 ? n : (john[1]+2)%n);  
			lm.push_back(locksmith[1]);  	
			lm.push_back((locksmith[1]-1+n)%n == 0 ? n :(locksmith[1]-1+n)%n);  
			lm.push_back((locksmith[1]-2+n)%n == 0 ? n :(locksmith[1]-2+n)%n);  
			lm.push_back((locksmith[1]+1)%n == 0 ? n : (locksmith[1]+1)%n); 
			lm.push_back((locksmith[1]+2)%n == 0 ? n : (locksmith[1]+2)%n); 
		}else if (i == 2){
			jr.push_back(john[2]);  	
			jr.push_back((john[2]-1+n)%n == 0 ? n :(john[2]-1+n)%n);  
			jr.push_back((john[2]-2+n)%n == 0 ? n :(john[2]-2+n)%n);  
			jr.push_back((john[2]+1)%n == 0 ? n : (john[2]+1)%n); 
			jr.push_back((john[2]+2)%n == 0 ? n : (john[2]+2)%n);  
			// fill  ll  
			lr.push_back(locksmith[2]);  	
			lr.push_back((locksmith[2]-1+n)%n == 0 ? n :(locksmith[2]-1+n)%n);  
			lr.push_back((locksmith[2]-2+n)%n == 0 ? n :(locksmith[2]-2+n)%n);  
			lr.push_back((locksmith[2]+1)%n == 0 ? n : (locksmith[2]+1)%n); 
			lr.push_back((locksmith[2]+2)%n == 0 ? n : (locksmith[2]+2)%n); 
		}
	}
	// try all possibilities 
	set< vector<int> > st; 
	// consider john's case first 
	dfs(st,0,0,0,0,0);  
	// consider locksmith's case next  
	dfs(st,0,1,0,0,0);  
	fout << st.size() << endl; 
	return 0; 
}
