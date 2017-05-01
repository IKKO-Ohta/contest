//
// Created by 司田行史 on 2016/06/26.
//

#include <bits/stdc++.h>
using namespace std;

string pattern,text;

int main() {
    cin >> pattern >> text;
    int N = pattern.len();
    int next[N];

    //maketable
    for (int j = 0; j < pattern.len(); ++j) {
        if (j < 1)
            next[j] = 1;
        else {
            for (int k = 1; k < j; ++k) {
                for (int m = k; m < j && pattern[m] == pattern[m - k]; ++m) {
                    if (m == j) break;
                }
                next[j] = k;
            }
        }
    }

int string_matching (string text,string pattern,int next[]){
    int i, j = 0;
    for (int i = 0; text[i]; ++i) {
        if (text[i] == pattern[j]) {
            j++;
            if (pattern[j] == NULL) return i - j + 1; //みつかった
        } else {
            if (j < next[j]) {
                j = 0;
            } else {
                i = i + next[j];
                j = j - next[j];
            }
        }
    }
    return -1;
}


    return 0;
}