#include <iostream>
using namespace std;
int main() {
    long n;
    long a[10000];
    int ans = 0;
    cin >> n;
    for (int i = 0; i < n ; ++i) {
        cin >> a[i];
        int check = 0;
        for (int j = 1; j * j <= a[i] ; ++j) {
            if( a[i] % j == 0) check++;
        }
        if(check == 1) ans++;
    }
    cout << ans << endl;
    return 0;
}