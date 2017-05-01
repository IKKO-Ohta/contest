//
// Created by 司田行史 on 2016/06/21.
//

#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
using namespace std;

int main(){
    string t,p; cin >> t >> p;
    int nt = t.size();
    int np = p.size();
    if(nt < np) return 0;
    for (int i = 0; i < nt-np +1 ; ++i) {
        if(t[i]== p[0]){
            if(t.substr(i,np) == p) printf("%d\n",i);
        }
    }
    return 0;
}