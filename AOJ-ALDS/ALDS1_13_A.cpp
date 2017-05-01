//
// Created by 司田行史 on 2016/06/09.
//

#include <iostream>
#include <cassert>
using namespace std;

const int N = 8;
const int FREE  = -1;
const int NOT_FREE = 1;

int row[N],col[N],DIAGONAL_L[2*N-1],DIAGONAL_R[2*N-1];
bool BOARD[N][N]= {false};

void printBoard(){
    for (int i = 0; i < N ; ++i) {
        for (int j = 0; j < N ; ++j) {
            if(BOARD[i][j])
                if(row[i] != j) return;
        }
    }

    for (int i = 0; i < N ; ++i) {
        for (int j = 0; j < N ; ++j) {
            cout << (row[i] == j ? 'Q' : '.');
        }
        cout << endl;
    }
}

void solve(int i){
    if(i == N){
        printBoard();
        return ;
    }

    for (int j = 0; j < N ; ++j) {
        if(col[j] == NOT_FREE or
           DIAGONAL_L[i+j] == NOT_FREE or
           DIAGONAL_R[i-j+N-1] == NOT_FREE)
            continue;

        row[i] = j;
        col[j] = DIAGONAL_L[i+j] = DIAGONAL_R[i-j+N-1] = NOT_FREE;

        solve(i+1);

        row[i] = col[j] = DIAGONAL_L[i+j] = DIAGONAL_R[i-j+N-1] = FREE;
    }
}

int main(){
    for (int i = 0; i < N ; ++i) {
        col[i] = row[i] = FREE;
        DIAGONAL_L[i] = DIAGONAL_R[i] = FREE;
        DIAGONAL_L[2*i] = DIAGONAL_R[2*i] =FREE;
    }

    int k; cin >> k;
    while(k --){
        int r,c; cin >> r >> c;
        BOARD[r][c] = true;
    }

    solve(0);
}