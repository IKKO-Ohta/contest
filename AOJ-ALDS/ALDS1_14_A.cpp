//
// Created by 司田行史 on 2016/06/21.
//

#include <iostream>
#include <string>
using namespace std;

void solve(string T,string P){
    int size = T.size() - P.size() +1;
    for (int i = 0; i < size ; ++i) {
        if(T[i] == P[0])
        {
            bool isSame = true;
            for (int j = 0; j < P.size() ; ++j) {
                if( T[i+j] != P[j]) {
                    isSame = false;
                    break;
                }
            }
            if(isSame){
                cout << i << endl;
            }
        }
    }
}

int main(){
    string T,P;
    cin >> T >> P;
    solve(T,P);
    return 0;
}