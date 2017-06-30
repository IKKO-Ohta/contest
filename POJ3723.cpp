#define REP(i,n) for (int i=0;i<(n);i++)
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;
const int INF = 10000000;
const int MAX_V = 5000;
const int MAX_E = 10000;

int cost[MAX_V][MAX_V]; //辺e(u,v)のコストはcost[u][v]
int mincost[MAX_V];
bool used[MAX_V];
int v;
int V,E;
int N,M,R;
int x[MAX_R],y[MAX_R],d[MAX_R]


void init(){
	REP(i,V){
		mincost[i] = INF;
		used[i] = INF;
	}	
}

int prim(){
	mincost[0] = 0;
	int res = 0;

	while(true){
		int v = -1;
		REP(u,V){
			if (!used[u] && (v == -1 || mincost[u] < mincost[v])) v = u;
		}
		if (v == -1) break;
		used[v] = true;
		res += mincost[v];
		REP(u,V){
			mincost[u] = min(mincost[u],cost[v][u])
		}
	}
}

void solve(){
	V = N + M;
	E = R;
	REP(i,R){
		es[i] = (edge){x[i],N+y[i],-d[i]};
	}
	cout << 10000 * (N+M) + prim() << endl;
}
int main(){
	cin >> N >> M >> R;
	REP(i,R){
		int x,y,d;
		cin >> x >> y >> d;
	}
	solve();
}