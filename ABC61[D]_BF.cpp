#define REP(i,n) for (int i=0;i<(n);i++)
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;

const long long INF = -1000000000000;
const long long MAX_N = 10001;
const long long MAX_M = 10000000;
struct edge {long long from,to,cost;};

long long d[MAX_N];
edge es[MAX_M];
int n,m;

void init(){
	REP(i,n) d[i] = INF;
}

bool find_negative_loop(){
	d[0] = 0;
	REP(i,n){
		REP(j,m){ 
			edge e = es[j];
			if(d[e.from] != INF && d[e.to] < d[e.from] + e.cost){ //更新の部分
				d[e.to] = d[e.from] + e.cost;
				if( i == n - 1 ) return true;
			}
		}
	}
	return false;
}

int main(){
	cin >> n >> m;
	init();
	REP(i,m){
		long long a,b,c;
		cin >> a >> b >> c; a--; b--;
		edge e;
		e.from = a; e.to = b; e.cost = c;
		es[i] = e;
	}
	bool ans = find_negative_loop();
	if (!ans) cout << d[n-1] << endl;
	else cout << "inf" << endl;
}

