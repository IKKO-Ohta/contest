#define REP(i,n) for (int i=0;i<(n);i++)
#include <iostream>
#include <algorithm>
using namespace std;
const int MAX_N = 25;
typedef pair<int,int> P;

int n;
int v,l;
P p[MAX_N];

void solve(){
	int accum = 0;
	sort(p,p+n);
	REP(i,n){
		accum += p[i].second;
		if (accum <= p[i].first){
			continue;
		}else{
			cout << "No" << endl;
			return;
		}
	}
	cout << "Yes" << endl;
	return;
}

int main(){
	while(1){
	    cin >> n;
	    if (n == 0) break;
		REP(i,n){
			cin >> v >> l;
			p[i] = P(l,v);
		}
		solve();
	}
}