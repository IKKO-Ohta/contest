#define REP(i,n) for (int i=0;i<(n);i++)

#include <iostream>
using namespace std;
const int MAX_N = 20000;
int N;
int L[MAX_N];

void solve(){
	long long ans = 0;
	while(N>1){
		'''
		最小,次に最小の組を探し当てる
		'''
		int mii1 = 0, mii2= 1;
		if (L[mii1] > L[mii2]) swap(mii1,mii2);
		REP(i+2,N){
			if (L[i] < L[mii1]){
				mii2 = mii1;
				mii1 = i;
			}
			else if(L[i] < L[mii2]){
				mii2 = i;
			}
		}
	int t = L[mii1] + L[mii2];
	ans += t;

	if(mii1 == N -1) swap(mii1,mii2);
	L[mii1] = t;
	L[mii2] = L[N-1];
	N --;
	}
	cout << ans << endl;
}

int main(){
	cin >> N;
	REP(i,N) cin >> L[i];
	solve();
}