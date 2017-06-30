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
struct edge {int from,to,cost;};

edge es[MAX_E];
int d[MAX_V];
int V,E;

void init(){
	REP(i,V) d[i] = INF;
}

void shortest_path(int s){
	d[s] = 0;
	while(1){
		bool update = false;
		REP(i,E){
			edge e = es[i];
			if(d[e.from] != INF && d[e.to] > d[e.from] + e.cost){
				 d[e.to] = d.[e.from] + e.cost;
				 update = true;
			}
		}
	if (!update) break;
	}
}

bool find_negative_loop(){
	REP(i,V){
		REP(j,E){
			edge e = es[j];
			if(d[e.to] > d[e.from] + e.cost){
				d[e.to] = d[e.from] + e.cost;
				if( i == V - 1 ) return true;
			}
		}
	}
	return false;
}