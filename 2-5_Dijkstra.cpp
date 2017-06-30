#define REP(i,n) for (int i=0;i<(n);i++)
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX_V = 5000;

int cost[MAX_V][MAX_V];　//距離表
int d[MAX_V];
bool used[MAX_N];
int V;

//not heap
void dijkstra(int s){
	fill(d,d+V,INF);
	fill(used,used+V,false);
	d[s] = 0;

	while(1){
		int v = -1;
		//まだ使われていない頂点のうち、距離が最小のものを探す
		REP(u,V){
			if(!used[u] && (v == -1 || d[u] < d[v])) v = u;
		}
		if (v == -1) break;
		used[v] = true;

		//最小の点を結ぶ
		REP(u,V){
			d[u] = min(d[u],d[v] + cost[v][u])
		}

	}

}

//heap on

struct edge {int to,cost;};
typedef pair<int,int> P;
void dijkstra(int s){
	priority_queue<P,vector<P>,greater<P> > que;
	fill(d,d+V,INF);
	d[s] = 0;
	que.push(P(0,s));

	while(!que.empty()){
		P p = que.top(); que.pop();
		int v = p.second;
		if(d[v] < p.first) continue;

		REP(i,G[v].size()){
			edge e = G[v][i];
			if(d[e.to] >  d[v] + e.cost){
				d[e.to] = d[v] + e.cost;
				que.push(P (d[e.to],e.to))
			}
		}
	}
}
