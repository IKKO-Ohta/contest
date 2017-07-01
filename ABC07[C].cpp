#define REP(i,n) for (int i=0;i<(n);i++)
#include <iostream>
#include <queue>
#include <utility>
using namespace std;
const int MAX = 100;
const int INF = 10000;

int N,M;
int sx,sy;
int gx,gy;
char field[MAX][MAX+1];
int d[MAX][MAX+1];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

typedef pair<int,int> P; 

int bfs(){

    REP(i,N){
        REP(j,M){
            d[i][j] = INF;
        }
    }

    queue <P> que;
    que.push(P(sx,sy));
    d[sx][sy] = 0;

    while(que.size()){
        P p = que.front(); que.pop();

        if (p.first == gx && p.second == gy) break;

        // 周辺4マスを調べる
        for(int r = 0; r < 4; r++) {
            int nx = p.first + dx[r], ny = p.second + dy[r];
            if (0 <= nx && nx < N && 0 <= ny && ny < M && field[nx][ny] != '#' &&d[nx][ny] == INF){
                d[nx][ny] = d[p.first][p.second] + 1;
                que.push(P(nx,ny));
            }
        }
    }
    return d[gx][gy];
}



void solve(){
    int ans = bfs();
    cout << ans << endl;
}


int main(){
    cin >> N >> M;
    cin >> sx  >> sy;
    cin >> gx  >> gy;
    sx --; sy --; gx --; gy --;
    REP(i,N){
        REP(j,M){
            cin >> field[i][j];
            }
        }
    solve();
}
