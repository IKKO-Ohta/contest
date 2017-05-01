#include <iostream>
#include <algorithm>
using namespace std;
const int MAX = 100000;
int A[MAX],n;

int partition(int p,int r){
    int x = A[r];
    int i = p-1;
    for (int j = p; j <= r-1 ; j++) {
        if(A[j] <= x){
            i ++;
            swap(A[i],A[j]);
        }
    }
    swap(A[i+1],A[r]);
    return i + 1;
}

int main (){
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> A[i];

    int x = partition(0,n-1);
    for(int i=0; i<n; i++){
        if(i==x){
            cout << '[' << A[i] << ']';
        }
        else{
            cout << A[i];
        }
        if(i<n-1){
            cout << ' ';
        }
        else{
            cout << endl;
        }
    }
    return 0;
}