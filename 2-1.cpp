#define REP(i,n) for (int i=0;i<(n);i++)

#include <stack>
#include <queue>
#include <cstdio>

// recursive
int fact(int n){
	if (n == 0) return 1;
	return n * fact(n-1);
}

//stack
int main(){
	stack<int> s;
	s.push(1);
	s.push(2);
	cout << s.top() << endl;
	s.pop();
	cout << s.top() << endl;
	s.pop();

}

//que
int main(){
	queue<int> q;
	q.push(1);
	q.push(2);
	q.pop();
	q.pop();
}

//DFS
// => recursiveとほぼおなじ意味合いで使う

//部分和問題
//再帰で解く！
//本質：足すか足さないかの2^n通り.だからこれは木構造を形成し、その場合分けは"足すか””足さないか”のどちらかになる。

int a[MAX_N];
int n,k;

bool dfs(int n,int sum){
	if (i == n) return sum == k;
	if (dfs(i + 1,sum)) return true; // 足し込まないとき
	if (dfs(i + 1,sum += a[i])) return true; //足し込むとき
	return false;

}