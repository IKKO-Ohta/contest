#define REP(i,n) for (int i=0;i<(n);i++)
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int prime[MAX_N];
bool is_prime[MAX_N + 1]; // is_prime[i] がtrueならばiは素数

// n以下の素数の数を数える
int sieve(int n){
	int p = 0;
	REP(i,n) is_prime[i] = true;
	is_prime[0] = is_prime[1] = false;
	for (int i = 2; i < n; ++i){
		if(is_prime[i]){
			prime[p++] = i;
			for (int j = 2 * i; j <= n; j += 1)	is_prime[j] = false;
		}
	}
	return p
}