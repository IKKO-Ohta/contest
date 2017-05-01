#include <bits/stdc++.h>
//方針　フィールドをハッシュ変換　→　照合
//書写したはいいもののまともなプログラムじゃない

using namespace std;

#define MAX 1010
typedef unsigned long long ull;

int N,M,P,Q;
char field[MAX][MAX],pattern[MAX][MAX];
ull hash[MAX][MAX],tmp[MAX][MAX]; /

void compute_hash(char a[MAX][MAX],int n,int m){
    const ull B1 = 63533;
    const ull B2 = 100007;　//100007は素数

    ull t1 = 1;
    for(int j = 0 ; j < Q ; j++) t1 *= B1;　//何でb1のQ乗？

    for (int i = 0; i < n ; ++i) {
        ull e = 0;
        for(int j = 0 ; j < Q ; j++) e = e * B1 + a[i][j];
        for(int j = 0 ; j + Q <= m ; j++){
            tmp[i][j] = e;
            if(j + Q < m) e = e * B1 - t1 * a[i][j] + a[i][j+Q];
        }
    }

    
    ull t2 = 1;
    for (int i = 0; i < P ; ++i)  t2 *= B2;

    for (int j = 0; j + Q <= m  ; ++j) {
        ull e = 0;
        for (int i = 0; i < P ; ++i)e = e * B2 + tmp[i][j];
        for (int i = 0; i + P <= n ; ++i) {
            hash[i][j] = e;
            if(i + P < n) e = e * B2 - t2 * tmp[i][j] + tmp[i + P][j];
        }
    }
}

void solve(){
    compute_hash(pattern,P,Q);
    ull res = hash[0][0];
    compute_hash(field,N,M);
    for (int i = 0; i <= N ; ++i) {
        for (int j = 0; j <= M ; ++j) {
            if(res == hash[i][j]){
                cout << i << " " << j << endl;
            }
        }
    }
}

int main(){
    cin >> N >> M;
    for (int i = 0; i < N ; ++i) {
        for (int j = 0; j < M ; ++j) {
            cin >> field[i][j];
        }
    }
    cin >> P >> Q;
    for (int i = 0; i < P ; i++) {
        for (int j = 0; j < Q; ++j) {
            cin >> pattern[i][j];
        }
    }
        if(N < P && M < Q) return 0;
        solve();
        return 0;
}