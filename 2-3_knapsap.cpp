//naive knapsap

#define REP(i,n) for (int i=0;i<(n);i++)
#define RREP(i,n) for (int i=(n)-1;i>=0;i--)
#include <iostream>
#include <algorithm>
using namespace std;
const int MAX_N = 100;
int w[MAX_N],v[MAX_N];

int rec(int i,int j){
	int res;
	if (i == n){
		//もう品物は残っていない
		res = 0;
	}else if(j < W[i]){
		//この品物は入らない
	res = rec(i+1,j);
	}else{
		//入れる場合と入れない場合を試す
		res = max(rec(i+1,j), rec(i+1,j-w[i])+ v[i]);
	}
	return res;
}

void solve(){
	cout << rec(0,W) << endl;
}

// memo rec knapsap

int db[MAX_N+1][MAX_N+1];

int rec(int i,int j){
	if (dp[i][j] >= 0){
		// すでに訪れた計算結果なら、それを返せばよい
		return dp[i][j];
	}

	int res;
	if (i == n){
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



//dp <RREP>

int db[MAX_N+1][MAX_W+1];

void solve(){
	RREP(i,n){
		REP(j,W){
			if(j < W[i]){
				dp[i][j] = dp[i+1][j]
			}else{
				dp[i][j] = max(dp[i+1][j]l,dp[i+1][j-w[i]]+v[i])
			}
		}
	}
	cout << dp[0][W] << endl;
}