#define REP(i,n) for (int i=0;i<(n);i++)
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

typedef long long ll;

ll modpow(ll x, ll n, ll mod){
	if(n == 0) return 1;
	ll res = modpow(x * x % mod, n/2, mod);
	if (n & 1) res = res * x % mod;
	return res;
}