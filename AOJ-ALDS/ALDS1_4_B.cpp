#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n,q,a;
    vector<int> S;
    vector<int> T;
    cin >> n;
    for (int i = 0; i < n ; ++i) {
        cin >> a;
        S.push_back(a);
    }
    cin >> q;
    for (int i = 0; i < q ; ++i) {
        cin >> a;
        T.push_back(a);
    }

    int count = 0;
    for (int i = 0; i < q ; ++i) {
        if(binary_search(S.begin(),S.end(),T[i])){
         count ++;
        }
    }
    cout << count << endl;
    return 0;
}