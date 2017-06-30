#define REP(i,n) for (int i=0;i<(n);i++)
#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;
const int MAX_N = 50000;
const int MAX_M = 50;
const int INF = 1000000;
int n,m;
int C[MAX_M+1];
int dp[MAX_N+1]; 



void solve(){
	for(int i = 1,i <= m , i++){
		for (int j = 0; j + C[i] <= n; j++){
			dp[j + c[i]] = min(dp[j+C[i]], dp[j]+1);
		}
	}
	cout << dp[n] << endl;
}


int main(){
	cin >> n >> m;
	for (int i = 1; i <= n; i++){
		dp[i] = INF;
	}
	dp[0] = 0;

	REP(i,m){
		cin >> C[i];
	}
	solve();
}
