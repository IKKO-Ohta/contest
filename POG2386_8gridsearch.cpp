// POG 2386

'''
TITLE : ８grid dfs

ポイント：８方向グリッドサーチ+DFS
ちゃんと８方向グリッドサーチが実装できますか？　そこでDFS（再帰）できますか？
'''
#define REP(i,n) for (int i=0;i<(n);i++)　//信じられないような変数誤りがC++では起こるので注意！！　foreachは存在しない！！

#include <iostream>
using namespace std;
const int MAX = 100;

'''
舞台設定は全てグローバル変数に置くのが大事
静的配列確保のため、const int MAXを先んじて確保しておく
'''
int N,M;
int count = 0;
char field[MAX][MAX+1];


void dfs (int x,int y){
	field[x][y] = '.';
	'''
	場所遷移の関数は座標をargにしていく。これをグリッドサーチ関数と呼ぶ。
	８方向ループや４方向ループは頻出。方針は移動距離dx,dyをループすること
	安全策で代入は分割して書くこと。
	a < x < b はC++では書けないので注意.枠内に入っているか、周りに水があるかをチェック
	'''
	for (int dx = -1; dx <= 1; dx++){
		for (int dy = -1 ; dy <= 1 ; dy++){ 
			int nx = x + dx, ny = y + dy ; 
			if (0 <= nx && nx < N && 0 <= ny && ny < M && field[nx][ny] == 'W') dfs(nx,ny);
		}
	}
	return ;
}


void solve(){
	REP(i,N){
		REP(j,M){
			if (field[i][j] == 'W') {
				dfs(i,j); count ++;
			}
		}
	}
	cout << count << endl;
}

int main(){
	cin >> n >> m;
	REP(i,N){
		REP(j,M){
			cin >> field[i][j];
			}
		}
	solve();
}

'''
TIPS:
四方向グリッドサーチは次のようなイディオム：

int dx[4] = {1, 0, -1, 0};　//配列をまとめて代入する{}用法
int dy[4] = {0, 1, 0, -1};
int dfs(int x, int y) {
    // (x, y) に対する処理をここに書く

    // 周辺4マスを調べる
    for(int r = 0; r < 4; r++) {
        int nx = x + dx[r];
        int ny = y + dy[r];
        dfs(nx, ny);
    }
}
'''