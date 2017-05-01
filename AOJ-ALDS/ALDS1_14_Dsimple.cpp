
//これだと半分しか通らない こわい
#include <bits/stdc++.h>
using namespace std;


int main() {
	ios::sync_with_stdio(false);
	int n;
	string text;
	string pattern;
	cin >> text >> n;

	for (int i = 0; i < n; ++i){
		cin >> pattern;
		string::size_type index = text.find(pattern);
		if (index == std::string::npos) {
			cout << 0 << "\n";
		} else {
			cout << 1 << "\n";
		}
	}
	return 0;
}