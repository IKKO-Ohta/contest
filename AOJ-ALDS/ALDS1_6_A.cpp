//
// Created by 司田行史 on 2016/03/21.
//

#include <iostream>
using namespace std;

int main(){
    int n,x;
    int A[10001] ={0};
    cin >> n;

    for (int i = 0; i < n ; ++i) {
        cin >> x;
        A[x]++;
    }
    bool s = false;
    for (int i = 0; i <= 10000 ; ++i) { //あるiについて
        for (int j = 0; j < A[i] ; ++j) { //カウントしたぶんだけ
            if(s) cout << " ";
            s ++;
            cout << i;                  //その数を吐く
        }
    }
    cout << endl;
    return 0;
}
