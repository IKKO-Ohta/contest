
#include <iostream>
#include <cmath>
#include <string>
#include <map>
#include <queue>

using namespace std;
const int N = 4;
const int N2 = 16;

static const int dx[4] = {-1,0,1,0};
static const int dy[4] = {0,-1,0,1};
static const char dir[4] ={'u','l','d','r'};
int MDT[N2][N2];

struct Puzzle{
    int f[N2];
    int space;
    int MD;
    int cost;

    bool operator < (const Puzzle &p) const{
        for (int i = 0; i < N2 ; ++i) {
            if (f [i] == p.f[i])continue;
            return f[i] < p.f[i];
        }
        return false;
    }
};

struct State{
    Puzzle puzzle;
    int estimated;
    bool operator < ( const State &s ) const {
        return estimated > s.estimated;
    }
};

int getALLMD(Puzzle pz){
    int sum = 0;
    for (int i = 0; i < N2 ; ++i) {
        if(pz.f[i] == N2) continue;
        sum += MDT[i][pz.f[i] -1];
    }
    return sum;
}

int astar(Puzzle s){
    priority_queue<State> PQ;
    s.MD = getALLMD(s);
    s.cost;
    map<Puzzle,bool> V;
    Puzzle u,v;
    State initial;
    initial.puzzle = s;
    initial.estimated = getALLMD(s);
    PQ.push(initial);

    while(! PQ.empty()){
        State st = PQ.top();PQ.pop();
        u = st.puzzle;

        if(u.MD == 0) return u.cost;
        V[u] = true;

        int sx = u.space / N;
        int sy = u.space % N;

        for (int r = 0; r < 4 ; ++r) {
            int tx = sx + dx[r];
            int ty = sy + dy[r];
            if( tx < 0 or ty < 0 or tx >= N or ty >= N ) continue;
            v = u;
            v.MD -= MDT[tx * N +ty ][v.f[tx *N + ty] -1 ];
            v.MD += MDT[sx * N +sy ][v.f[tx *N + ty] -1 ];


            swap(v.f[sx*N + sy],v.f[tx * N + ty]);
            v.space = tx * N +ty;
            if (!V[v]){
                v.cost ++ ;
                State news;
                news.puzzle = v;
                news.estimated = v.cost + v.MD;
                PQ.push(news);
            }
        }
    }
    return -1;
}

int main(){
    for (int i = 0; i < N2 ; ++i) {
        for (int j = 0; j <N2 ; ++j) {
            MDT[i][j] = abs(i/ N - j / N ) + abs(i % N - j % N);
        }
    }

    Puzzle in;
    for (int i = 0; i < N2 ; ++i) {
        cin >> in.f[i];
        if (in.f[i] == 0){
            in.f[i] = N2;
            in.space = i;
        }
    }
    cout << astar( in ) << endl;
    return 0 ;
}