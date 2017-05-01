#include <iostream>
#include <queue>
#include <climits>
#include <vector>
using namespace std;
typedef pair<pair<int,int>,int> NODE;
#define cost first.first
#define ticket first.second
#define pos second
#define ppp(a,b,c) make_pair(make_pair(a,b),c)
#define rep(i,n) for(int i=0;i<n;i++)
#define INF (1<<21)

int info[100][100];
int n;

int dijkstra(int a,int b,int c){
    priority_queue <NODE,vector<NODE>,greater<NODE>> Q;
    int memo [100][11] ;
    for (int i = 0; i < 100 ; ++i) {
        for (int j = 0; j < 11 ; ++j) { //
            MEMO[i][j] = INF;
        }
    }


    for (int j = 0; j < 11 ; ++j) { //スタート地点はコスト０
        MEMO[a][j] =0;
    }
    Q.push(ppp(0,c,a));
    while(! Q.empty()){
        NODE q = Q.top(); Q.pop();
        for (int i = 0; i < n ; ++i) {
            if (info.[q.pos][i] + q.so)
        }
    }
}

int main (){
    int c,m,s,d,a,b,f;
    while(cin >> c >> n >> m >> s >> d,c){ //コンマ演算子：c == 0なら終了
        s--; d--;
        for (int i = 0; i < 100; ++i) {
            for (int j = 0; j < 100; ++j) {
                info[i][j] = INFTY;
            }
        }
        for (int i = 0; i < m ; ++i) {
                cin >> a >> b >> f;
                a-- ; b-- ; //１originだから
                info[a][b] = info[b][a] = f;
        }
        cout << dijk(s,d,c) << endl;
    }
    return 0;
}
