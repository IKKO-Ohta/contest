#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

int cnt;
int n;
int l;
int A[1000000];
vector<int> G;

void insertionSort(int A[],int n, int g){
    for (int i = g; i < n ; ++i) {
        int v = A[i];
        int j = i-g;
        while (j >= 0 && A[j] > v ){
            A[j+g] = A[j];
            j = j-g;
            cnt ++;
        }
        A[j+g] = v;
    }
}

void shellSort(int A[],int n){
    for (int h = 1 ; ; ){
    if(h > n)break;
    G.push_back(h);
        h = 3 * h + 1;
    }
    for (int i = G.size() -1 ; i >= 0 ; i--) {
        insertionSort(A, n, G[i]);
    }
}

int main(){
    cin >> n;
	for (long i = 0; i < n; i++) cin >> A[i];
    cnt = 0;

    shellSort(A,n);

    cout << G.size() << endl;
    for (int i = G.size() -1 ; i >= 0 ; i--) {
        cout << G[i];
        if (i) cout << (" ");
    }
    cout << endl;
    cout << cnt << endl;
    for (int i = 0; i < n ; ++i) {
        cout << A[i] << endl;
    }
    return 0;
}