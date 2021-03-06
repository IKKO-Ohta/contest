//
// Created by 司田行史 on 2016/04/23.
//

#include <iostream>
#include <algorithm>
using namespace std;

const int N = 100;

int main (){
    int n,p[N+1],m[N+1][N+1];
    cin >> n;
    for (int i = 1; i <= n ; ++i) cin >> p[i-1] >> p[i];
    for (int i = 1; i <= n ; ++i) m[i][i] = 0;
    for (int l = 2; l <= n ; ++l) {
        for (int i = 1; i <= n - l + 1 ; ++i) {
            int j = i + l - 1 ;
            m[i][j] = 200000;
            // m[i][j] = (1 << 21);と同じ
            // 1を21bit左にシフト
            for (int k = i; k <= j -1  ; ++k) {
                m[i][j] = min (m[i][j],m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j]);
            }
        }
    }

    for (int i = 0; i < n ; ++i) {
        for (int j = 0; j < n ; ++j) {
            cout << m[i][j] << " ";
        }
        cout << endl;
    }

    cout << m[1][n] << endl;

    return 0;
}