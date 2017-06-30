#define REP(i,n) for (int i=0;i<(n);i++)
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;
const int MAX_N = 10000;
const int MAX_L = 10000000;
int N,L,P;
int A[MAX_N+1],B[MAX_N+1]; //Aが距離、Bが保有できる量
priority_queue<int> pq;

void solve(){
	int l = 0, i = 0, cnt = 0;
	while(1){		
		l++; P--; 
		if(l == L){
			cout << cnt << endl;
			break;
		}

		if(l == A[i]){
			pq.push(B[i])
			i ++;
		}

		if(P == 0){
			if(!pq.empty()){
			 P += pq.top(); pq.pop();
			 cnt ++;
			}else{
				cout << '-1' << endl;
				return;
			}
		}
	}

}

int main(){
	cin >> N;
	REP(i,N){
	    int a;
		cin >> A[i] >> B[i];
	}
	cin >> L >> P;
	solve();
}
