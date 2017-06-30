#define REP(i,n) for (int i=0;i<(n);i++)
#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;
const int MAX_N = 100;
long long N,W;
long long w[MAX_N+1],v[MAX_N+1];
long long dp[MAX_N+1][MAX_N+1];

long long rec(long long i,long long j){
	if (dp[i][j] >= 0){
		// すでに訪れた計算結果なら、それを返せばよい
		return dp[i][j];
	}

	long long res;
	if (i == N){
		res = 0;
	}else if(j < w[i]){
		res = rec(i+1,j);
	}else{
		//入れる場合と入れない場合を試す
		res = max(rec(i+1,j), rec(i+1,j-w[i])+ v[i]);
	}
	dp[i][j] = res;
	return res;
}

void solve(){
	memset(dp,-1,sizeof(dp));
	cout << rec(0,W) << endl;
}

int main(){
	cin >> N >> W;
	REP(i,N){
		cin >> w[i] >> v[i];
	}
	solve();
}