#define REP(i,n) for (int i=0;i<(n);i++)
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;


vector<int> G[MAX_V];


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
}
