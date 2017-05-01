//C++11 を使用
//重要構文 for (auto itr = v.begin(); itr != v.end() ; itr++)
//autoは型推測。特にイテレータを取得するときに便利。C++11以降で使える

#include <iostream>
#include <list>
#include <algorithm>
using namespace std;

int main(){
    int q,x;
    string command;

    list<int> v;
    cin >> q;
    for (int i = 0; i < q; ++i) {
        cin >> command;
        if(command == "insert"){
            cin >> x;
            v.push_front(x);
        }else if(command == "deleteFirst"){
            v.pop_front();
        }else if(command == "deleteLast"){
            v.pop_back();
        }else if(command == "delete"){
            cin >> x;
            for (auto itr = v.begin(); itr != v.end() ; itr++) { //イテレータで指定
                if(*itr == x){        //イテレータの中身
                    v.erase(itr);
                    break;
                }
            }
        }
    }
    int i = 0;
    for(auto itr = v.begin(); itr != v.end(); ++itr) { //もう一度
        if ( i ++) cout << " "; // i !=0 and then i++
        cout << *itr;
    }
    cout << endl;
    return 0;
}