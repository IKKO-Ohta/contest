#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 
 
int main(){
    int n,q;
    int S[10000],T[500];
    cin >> n;
    for (int i = 0; i < n ; ++i) {
        cin >> S[i];
    }
    cin >> q;
    for (int i = 0; i < q ; ++i) {
        cin >> T[i];
    }
 
    int count = 0;
    for (int i = 0; i < q ; ++i) {
        for (int j = 0; j < n ; j++) {
            if(T[i] == S[j]) {
                count++;
                break;
            }
        }
    }
    cout << count << endl;
    return 0;
}