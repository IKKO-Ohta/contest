#include <iostream>
using namespace std;

const long MAX = 200000;
#define SENTINEL 2000000000;


int L[MAX/2 +2],R[MAX/2 +2];

long long merge (int A[],int n,int left,int mid, int right){
    int i,j,k;
    long long cnt = 0;
    int n1 = mid -left;
    int n2 = right - mid;
    for (int i = 0; i < n1 ; ++i) L[i] = A[left + i];
    for (int i = 0; i < n2 ; ++i)  R[i] = A[mid + i];
    L[n1] = R[n2] = SENTINEL;
    i = j = 0;
    for (int k = left; k < right ; ++k) {

        if(L[i] <= R[j]){
            A[k] = L[i];
            i++;
        }else{
            A[k] = R[j];
            j++;
            cnt += n1 - i;
        }
    }
    return cnt;
}

long long mergesort(int A[],int n, int left,int right){
    int mid;
    long long v1,v2,v3;
    if(left + 1 < right){
        mid = (left + right)/2;
        v1 = mergesort(A,n,left,mid);
        v2 = mergesort(A,n,mid,right);
        v3 = merge(A,n,left,mid,right);
        return v1 + v2 + v3;
    } else return 0;
};

int main (){
    int A[MAX],n,i;

    cin >> n;
    for ( i = 0; i < n ; ++i) {
        cin >> A[i];
    }

    long long ans = mergesort(A,n,0,n);
    cout << ans << endl;

    return 0;
}