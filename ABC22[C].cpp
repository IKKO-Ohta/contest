#define REP(i,n) for (long long i=0;i<(n);i++)
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;
const long long INF = 1000000000000;
const long long MAX_N = 400;
vector<long long> g[MAX_N];
long long d[MAX_N][MAX_N]; //距離表
long long sd[MAX_N];
long long n,m;

// thanks to http://abc022.contest.atcoder.jp/submissions/1404647
 
void init(){
	REP(i,n){
		REP(j,n){
			d[i][j] = INF;
		}
	}
}
 
void warshall_floyd(){
	REP(k,n){
		REP(i,n){
			REP(j,n){
				d[i][j] = min(d[i][j],d[i][k]+d[k][j]);
			}
		}
	}
}
 
int main(){
	cin >> n >> m;
 
	init();
	REP(i,m){
		long long a,b,c;
		cin >> a >> b >> c;
		a--;b--;
		if (a != 0 && b != 0){
			d[a][b]=c;
			d[b][a]=c;
		}else{
			g[a].push_back(b);
			g[b].push_back(a);
			if (a == 0) sd[b] = c;
			else sd[a] = c;
		}
	}
 
	warshall_floyd();
 
	long long mincost;
	mincost = INF;
	REP(i,g[0].size()){
		REP(j,g[0].size()){
			if (i == j) continue;
			mincost = min(mincost, d[g[0][i]][g[0][j]] + sd[g[0][i]] + sd[g[0][j]]);
		}
	}
	if (mincost >= INF) cout << -1 << endl;
	else cout << mincost << endl;
}