#define REP(i,n) for (int i=0;i<(n);i++)
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX_N = 100;
const int MAX_M = 5000;

int N,M;
int Tree[MAX_M];
int U[MAX_M],V[MAX_N];
int par[MAX_N];
int myrank[MAX_N];

void init(int n){
	REP(i,n){
		par[i] = i;
		myrank[i] = 0;
	}
}

int find(int x){
	if(par[x] == x){
		return x;
	}else{
		return par[x] = find(par[x]);
	}
}

void unite(int x,int y){
	x = find(x);
	y = find(y);
	if(x == y) return;

	if(myrank[x] < myrank[y]){
		par[x] = y;
	}else{
		par[y] = x;
		if(myrank[x] == myrank[y]){
			myrank[x]++;
		}
	}
}

bool same(int x,int y){
	return find(x) == find(y);
}


int main(){
	// input : example<1>
	cin >> N >> M;
	int u,v;
	init(N);
	REP(i,M){
		cin >> u >> v;
		u--; v--;
		if (find(u) == find(v)) Tree[find(u)] = -1;
        unite(u,v);
	}
	//tree => [0,0,0,0,-1,0,0,0] 
	REP(i,N){
		if (Tree[find(i)] >= 0) Tree[find(i)]++;
	}
	//tree => [4,0,0,0,-1,0,0,0] 
	int ans = 0;
	REP(i,N){
	    if (Tree[i] > 0) ans ++;
	}
	cout << ans << endl;
}