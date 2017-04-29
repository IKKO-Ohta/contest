#define REP(i,n) for (int i=0;i<(n);i++)

#include <iostream>
using namespace std;
const int MAX_N = 1000;
int X[MAX_N];
int N,R,ans;

void solve(){
	int i = 0, int ans = 0;
	while(i < N){
		'''
		対照なコードはそれぞれ半径の行きと帰りに相当している。
		'''
		int S = X[i++]; //Sはカバーされていない最初の点
		while(i < N && X[i]  <= S + R) i ++; //Sからできるだけ遠くにいった点まで進む

		int p = X[i -1]; //新しく印をつける点の位置
		while(i < N && X[i] <= S + R) i ++; //Pから距離Rを超える点まで進む
		ans ++;
	}
	cout << ans << endl;
}

int main(){
	cin >> N >> R;
	REP(i,N) cin >> X[i];
	solve();
}