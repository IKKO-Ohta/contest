#define REP(i,n) for (int i=0;i<(n);i++)　//信じられないような変数誤りがC++では起こるので注意！！　foreachは存在しない！！

#include <iostream>
'''
GRIDサーチ＋BFS
BFSは最短経路を調べるときに使う。そのときの距離や状態の保存の仕方は大丈夫？
グリッドサーチや、座標をしめすtypedefなどの手筋に着目する。

・グリッドサーチ時のフィールド要件の確認は大丈夫？
・未踏チェックは？/移動可能チェックは？ （移動判定はつまり６つ確認しなければならないのを自覚せよ）

・pair型のfirstやsecondは（）をつけないのは知っている？
'''


#include <queue>
#include <utility>
using namespace std;
const int MAX = 100;
const int INF = 10000;

int N,M;
int sx,sy;
int gx,gy;
char field[MAX][MAX+1]; //field
int d[MAX][MAX+1] //distance 最短経路の問題だから２つ配列は用意する

int dx[4] = {1, 0, -1, 0};　//グリッドサーチの味付け
int dy[4] = {0, 1, 0, -1};

typedef pair<int,int> P; //マクロを貼っておく

int bfs(){

	REP(i,N){
		REP(j,M){
			d[i][j] = INF
		}
	}

	queue <P> que;
	que.push(P(sx,sy));
	d[sx][sy] = 0;

	while(que.size()){
		d[x][y] = dis;
		P p = que.front(); que.pop(); //マクロ

		if (p.first == gx && p.second == gy) break;

		// 周辺4マスを調べる
		for(int r = 0; r < 4; r++) {
	    	int nx = p.first + dx[r], ny = p.second + dy[r]; //同時代入のときは型宣言をつけない
	    	if (0 <= nx && nx < N && 0 <= ny && ny < M && field[nx][ny] != '#' &&d[nx][ny] == INF){
	    		d[nx][ny] = d[p.first][p.second] + 1;
	    		que.push(P(nx,ny))
	    	}
		}
	}
	return d[gx][gy];
}



void solve(){
	int ans = bfs()
	cout << ans << endl;
}


int main(){
	cin >> N >> M;
	REP(i,N){
		REP(j,M){
			cin >> field[i][j];
			if (field[i][j] == 'S') sx = i, sy = j;
			if (field[i][j] == 'G') gx = i, gy = j;
			}
		}
	solve();
}