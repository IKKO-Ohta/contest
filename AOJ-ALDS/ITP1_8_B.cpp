#include <string>
#include <iostream>

using namespace std;

int main() {
    char str[1001];

    while(1) {
        cin >> str;
        if(str[0] == '0') break;
        int sum = 0;
        for (int i = 0; i < strlen(str); ++i) {
            sum += (str[i]);
        }
        cout << sum << endl;
    }
    return 0;
}
