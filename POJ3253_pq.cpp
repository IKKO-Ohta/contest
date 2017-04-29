#define REP(i,n) for (int i=0;i<(n);i++)

#include <iostream>
#include <vector>
#include <queue>

using namespace std;
const int MAX_N = 20000;
int N,min1,min2;
int L[MAX_N];
priority_queue<int, vector<int>, greater<int> > pq;

void solve(){
	long long ans = 0;
	while(!pq.empty()){
		min1 = pq.pop();
		min2 = pq.pop();
		cost = cost + min1 + min2;
	}
	cout << ans << endl;
}

int main(){
	cin >> N;
	REP(i,N){
		cin >> L[i];
		pq.push_back(L[i])
	}
	solve();
}