// stackと queueの基本的なコマンド
// .top() ……先頭
// .pop() ……吐く
// .push(x) ……入れる
// .size() ……サイズを取得
// .empty ……空ならtrue

#include <iostream>
#include <string>
#include <stack>
#include<cstdlib>
using namespace std;

int main (){
    int n,m;
    stack<int> operand;
    string g;

    // 引き算：順序に注意
    while(cin >> g){
        if (g == "+") {
            n = operand.top();
            operand.pop();
            m = operand.top();
            operand.pop();
            operand.push(m + n);
        }
        else if (g == "-") {
            n = operand.top();
            operand.pop();
            m = operand.top();
            operand.pop();
            operand.push(m - n);
        }
        else if (g == "*") {
            n = operand.top();
            operand.pop();
            m = operand.top();
            operand.pop();
            n = m * n;
            operand.push(n);
        }
        else {
            //入力：atoiのオペランドに合わせるために.c_str（キャラ・ストリング）でchar型のポインタを取得
            //atoiはcharのみオペランドに取る
            operand.push(atoi(g.c_str()));
        }
    }
    cout << operand.top() << endl;
    return 0;
}