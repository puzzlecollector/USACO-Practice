/*
ID: mkim142
LANG: C++
TASK: pprime 
*/
#include <iostream>
#include <cstdlib>
#include <algorithm> 
#include <vector>
#include <fstream> 
using namespace std;  
bool isPrime(int x){
	for (int i = 2; i*i <= x; i++){
		if (x%i == 0) return false; 
	}
	return x != 1;  
}
bool chk(int x,int a,int b){
	return (x >= a && x <= b); 
}
int main(){
	ifstream fin("pprime.in");  
	ofstream fout("pprime.out"); 
	int a,b; 
	fin >> a >> b; 
	if (chk(5,a,b)) fout << 5 << endl; 
	if (chk(7,a,b)) fout << 7 << endl;  
	if (chk(11,a,b)) fout << 11 << endl; 
	// three digit palindromic primes 
	for (int d1 = 1; d1 <= 9; d1 += 2){
		for (int d2 = 0; d2 <= 9; d2++){
			int x = d1*100+d2*10+d1; 
			if (isPrime(x) && chk(x,a,b)) fout << x << endl; 
		}
	}
	// four digit palindromic primes 
	for (int d1 = 1; d1 <= 9; d1 += 2){
		for (int d2 = 0; d2 <= 9; d2++){
			int x = d1*1000+d2*100+d2*10+d1; 
			if (isPrime(x) && chk(x,a,b)) fout << x << endl;  
		}
	}
	// five digit palindromic primes 
	for (int d1 = 1; d1 <= 9; d1 += 2){
		for (int d2 = 0; d2 <= 9; d2++){
			for (int d3 = 0; d3 <= 9; d3++){
				int x = d1*10000+d2*1000+d3*100+d2*10+d1; 
				if (isPrime(x) && chk(x,a,b)) fout << x << endl; 
			}
		}
	}
	// six digit palindromic primes 
	for (int d1 = 1; d1 <= 9; d1 += 2){
		for (int d2 = 0; d2 <= 9; d2++){
			for (int d3 = 0; d3 <= 9; d3++){
				int x = d1*100000+d2*10000+d3*1000+d3*100+d2*10+d1;  
				if (isPrime(x) && chk(x,a,b)) fout << x << endl; 
			}
		}
	}
	// seven digit palindromic primes 
	for (int d1 = 1; d1 <= 9; d1 += 2){
		for (int d2 = 0; d2 <= 9; d2++){
			for (int d3 = 0; d3 <= 9; d3++){
				for (int d4 = 0; d4 <= 9; d4++){
					int x = d1*1000000+d2*100000+d3*10000+d4*1000+d3*100+d2*10+d1;  
					if (isPrime(x) && chk(x,a,b)) fout << x << endl; 
				}
			}
		}
	}
	// eight digit palindromic primes 
	for (int d1 = 1; d1 <= 9; d1 += 2){
		for (int d2 = 0; d2 <= 9; d2++){
			for (int d3 = 0; d3 <= 9; d3++){
				for (int d4 = 0; d4 <= 9; d4++){
					int x = d1*10000000+d2*1000000+d3*100000+d4*10000+d4*1000+d3*100+d2*10+d1;  
					if (isPrime(x) && chk(x,a,b)) fout << x << endl; 
				}
			}
		}
	}
	fin.close(); 
	fout.close(); 
	return 0; 
}
