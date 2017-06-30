#define REP(i,n) for (int i=0;i<(n);i++)
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX_N = 5000;
const long long MIN = - (2 << 60);
long long d[MAX_N][MAX_N]; //距離表
int n,m;

void init(){
	REP(i,n){
		REP(j,n){
			if (i == j)	d[i][j] = 0;
			else d[i][j] = MIN;
		}
	}
}

void warshall_floyd(){
	REP(k,n){
		REP(i,n){
			REP(j,n){
				d[i][j] = max(d[i][j],d[i][k]+d[k][j]);
			}
		}
	}
}

int main(){
	cin >> n >> m;
	init();
	REP(i,m){
		int a,b,c;
		cin >> a >> b >> c;
		a--;b--;
		d[a][b]=c;
	}

	warshall_floyd();
	
	if(d[0][0] > 0) cout << "inf" << endl;
	else cout << d[0][n-1] << endl;
}