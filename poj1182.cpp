#define REP(i,n) for (int i=0;i<(n);i++)
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX_N = 50000;
const int MAX_K = 100000;
int par[MAX_N];
int myrank[MAX_K];
int N,K;
int T[MAX_K],X[MAX_K],Y[MAX_K];

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


void solve(){
	//union-find木を初期化
	//x,x+N,x+2*Nをx-A,x-B,x-Cの要素とする
	init(N*3);

	int ans = 0;
	REP(i,K){
		int t = T[i];
		int x = X[i] -1,y = Y[i] -1; //0, ..., N-1 の範囲にする

		//正しくない番号
		if(x < 0 || N <= x || y < 0 || N <= y){
			ans ++;
			continue;
		}

		if(t == 1){
			// xとyが同じ種類
			if (same(x,y+N) || same(x, y + 2 * N)){
				ans++;
			}else{
				unite(x,y);
				unite(x + N,y + N);
				unite(x + N*2, y + N*2);
			}
		}else{
			// xはyを食べるという情報
			if(same(x,y) || same(x,y+2*N)){
				ans ++;
			}else{
				unite(x,y+N);
				unite(x+N,y+2*N);
				unite(x+ 2*N,y);
			}
		}
	}

	cout << ans << endl;
}

int main(){
	cin >> N >> K;
	REP(i,K){
		cin >> T[i] >> X[i] >> Y[i];
	}
	solve();

}