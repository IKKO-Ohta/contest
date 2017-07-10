#define REP(i,n) for (long long i=0;i<(n);i++)
#include <iostream>
#include <queue>
#include <utility>
using namespace std;
const long long MAX = 100;
const long long INF = 10000000000000;

long long N,M,T,X;
long long sx,sy;
long long gx,gy;
char field[MAX][MAX+1];
long long d[MAX][MAX+1];

long long dx[4] = {1, 0, -1, 0};
long long dy[4] = {0, 1, 0, -1};

typedef pair<long long,long long> P; 

long long bfs(){

    REP(i,N){
        REP(j,M){
            d[i][j] = INF;
        }
    }

    queue <P> que;
    que.push(P(sy,sx));
    d[sy][sx] = 0;

    while(que.size()){
        P p = que.front(); que.pop();

        if (p.first == gy && p.second == gx){
            break;
        }

        // 周辺4マスを調べる
        for(long long r = 0; r < 4; r++) {
            long long ny = p.first + dy[r], nx = p.second + dx[r];
            if (0 <= nx && nx < N && 0 <= ny && ny < M && d[ny][nx] == INF){
                if (field[nx][ny] != '#'){
                    //cout << "get" << endl;
                    d[nx][ny] = d[p.first][p.second] + 1;
                    que.push(P(nx,ny));
                }else if(field[nx][ny] == '#'){
                    //cout << "get?" << endl;
                    d[nx][ny] = d[p.first][p.second] + X;
                    que.push(P(nx,ny));
                }
            }
        }
    }
    return d[gx][gy];
}


void solve(){
    long long low = 1;
    long long high = T;
    long long mid;
    while(high - low != 1){
        mid = (low + high)/2;
        X = mid;
        //cout << X << endl;
        if(bfs() <= T){
            low = mid;
        }else{
            high = mid;
        }
    }
    cout << low << endl;
}

int main(){
    cin >> N >> M >> T;
    REP(i,N){
        REP(j,M){
            cin >> field[i][j];
            if(field[i][j] == 'S'){
                sy = i; sx = j;
            }else if(field[i][j] == 'G'){
                gy = i; gx = j;
            }
        }
    }
    solve();
}

