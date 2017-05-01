#include <iostream>

using namespace std;

     //出力手続き
void out (int a[],int n){
    for (int i = 0; i < n-1 ; ++i) {
        cout << a[i] << " ";
    }
        cout << a[n-1] << endl;
}

int main() {
    int a[100];
    int n;

    //入力部
    cin >> n;
    for (int i = 0; i < n ; ++i) {
        cin >> a[i];
    }
    //初期条件の出力
    out (a,n);

    //挿入ソート
    for (int i = 1; i < n ; ++i) {
        int j = i-1;
        int v = a[i];

        while( j >= 0 and a[j]>v) {
            a[j + 1] = a[j];
            --j;
        }
        a[j + 1] = v;
        out (a,n);
        }
    return 0;
}
