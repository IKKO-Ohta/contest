//
// Created by 司田行史 on 2016/03/21.
//

#include <iostream>
using namespace std;
const int MAX = 500000;
const int SENTINEL = 2000000000;
int A[MAX/2 + 2],B[MAX/2 + 2];
int cnt;

void merge(int P[],int alpha,int gamma,int beta){
    int n1 = gamma - alpha;
    int n2 = beta - gamma;
    for (int i = 0; i < n1 ; ++i)A[i] = P[alpha + i];
    for (int i = 0; i < n2 ; ++i)B[i] = P[gamma + i];
    A[n1] = SENTINEL;
    B[n2] = SENTINEL;
    int i=0; int j=0;
    for (int k = alpha; k < beta ; ++k) {
        cnt ++;
        if(A[i] <= B[j]){
            P[k] = A[i];
            i++;
        }else{
            P[k] = B[j];
            j++;
        }
    }
}

void mergesort(int P[],int alpha,int beta){
    if(alpha + 1 < beta){
        int gamma = (alpha + beta)/2;
        mergesort(P,alpha,gamma);
        mergesort(P,gamma,beta);
        merge(P,alpha,gamma,beta);
    }
}

int main (){
    int P[MAX] ,n,i;
    cnt = 0;
    cin >> n;

    for (int i = 0; i < n; ++i)cin >> P[i];

    mergesort(P,0,n);

    for (int i = 0; i < n ; ++i) {
        if (i) cout << " ";
        cout << P[i];
    }
    cout << endl;
    cout << cnt << endl;
    return 0;
}