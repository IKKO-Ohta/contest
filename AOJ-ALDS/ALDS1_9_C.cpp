//
// Created by 司田行史 on 2016/04/15.
//

#include <iostream>
#include <string>
#include <queue>
using namespace std;

int main(){
    string com;
    priority_queue<int> PQ;

    while(1){
        cin >> com;
        if(com == "insert"){
            int key; cin >> key;
            PQ.push(key);
        }else if (com == "extract"){
            cout << " " << PQ.top();
            PQ.pop();
        }else if (com == "end"){
            break;
        }
    }

    return 0;
}