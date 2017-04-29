#define REP(i,n) for (int i=0;i<(n);i++)
#define RREP(i,n) for (int i=(n)-1;i>=0;i--)　//リバースREP

#include <iostream>
using namespace std;
int v[6] = {1,5,10,50,100,500};
int c[6];
int A;


void solve(){
	int ans = 0;
	RREP(i,6){
		int t = min (A / v[i],c[i]);
		A -= t * v[i];
		ans += t; 
	}
	cout << ans;
}

int main(){
	cin >> c[0] >> c[1] >> c[2] >> c[3] >> c[4] >> c[5];
	cin >> A;
	solve();

}

/****/

'''
Greedy + C++のsort(pair)の挙動を知っていますか問題。
sort(pair)はまずpair.firstを比較し、それからpair.secondを評価する。
また、C++のsort構文はやや特殊でsort(A,A+n,[option])と書く。
=>Aの先頭からn番目までソートする。もし配列長がnなら全ソート
'''
#define REP(i,n) for (int i=0;i<(n);i++)
#define RREP(i,n) for (int i=(n)-1;i>=0;i--)　//リバースREP

#include <iostream>
using namespace std;
pair<int,int> job;
const int MAX = 1000000;
int n;
int s[MAX],t[MAX];
pair<int,int> itv[MAX]; //

int main(){
	cin >> n;
	REP(i,n) cin >> s[i];
	REP(i,n) cin >> t[i];
	REP(i,n){
		itv[i].first = t[i]; //終了時刻
		itv[i].second = s[i]; //開始時刻
	}

	sort(itv,itv + n); // C++では、先頭からn番目までのソートをsort(s,s+n,[opt])と書く

	int ans = 0; t = 0;
	REP(i,n){
		if(t < itv[i].second){
			ans ++;
			t = itv[i].first;
		}
	}

	print(ans)
}