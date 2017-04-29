'''
C++でのstring処理は機能的な融通がきかないため、
添字の働きを活かす原始的なやりかたを用いるしかない。
逆順処理にはb = [配列のサイズ-1]すなわち最後の添字を使って攻める。
'''

#define REP(i,n) for (int i=0;i<(n);i++)

#include <iostream>
using namespace std;
const int MAX_N = 2000;

int N;
char S[MAX_N + 1];

void solve(){
	int a = 0,b = N-1;
	while(a <= b){
		bool left = false;
		REP(i,N){
			if (S[a+i] < S[b - i]){
				left = true;
				break;
			}
			else if(S[a + i] > S[b -i]){
				left = false;
				break;
			}
		}
		if (left) putchar(S[a++]);
		else putchar(S[b--]);
	}
}

int main(){
	cin >> N;
	REP(i,N){
		cin >> S[i];
	}
	solve()
	return 0;
}