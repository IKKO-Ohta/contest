#define REP(i,n) for (int i=0;i<(n);i++)
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX_V = 5000;


//辺に属性がある場合
struct edge {int to,cost;}
vector<edge> G[MAX_V];
//頂点iの色は（１or-１）
int color[MAX_V];

bool dfs(int v,int c){
	color[v] = c;
	REP(i,G[v].size()){
		//隣接している頂点が同じ色ならfalse
		if (color[G[v][i]] == c) return false;
		// 隣接している頂点がまだ塗られていないなら-cで塗る
		if (color[G[v][i]] == 0 && !dfs(G[v][i],-c)) return false;
	}
}

void solve(){
	REP(i,V){
		if(color[i] == 0){
			//まだi地点が塗られていないなら1を塗る
			if(!dfs(i,1)){
				cout << 'No' << endl;
				return;
			}
		}
	}
	cout << "Yes" << endl;
}


int main(){
	int V,E;
	cin >> V >> E;
	REP(i,E){
		//sからtへの辺を張る
		int s,t;
		cin >> s >> t;
		G[s].push_back(t);
		//無向グラフの場合は逆方向にも張る
		G[t].push_back(s);
	}
	solve();
}
