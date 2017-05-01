//処理部の後半の仕組みがよくわからなかった。検討課題にしたい

#include <iostream>
#include <stack>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main(){

    //計算部
    stack<int> S1;
    stack< pair <int,int> > S2; //各々の水たまりと、その面積
    char ch;
    int sum = 0;

    for (int i = 0; cin >> ch  ; ++i) {   // "\/"の組ひとつ、もしくは_でインクリメントひとつ
        if( ch == '\\')S1.push(i);        //バックスラッシュは二個重ねて表記

        else if (ch == '/' and S1.size() >0){  // 深さ”\”を登り”/”が越えないなら

            int j = S1.top(); //積んだ面積スタックの先頭
            S1.pop();
            sum += i-j; //合計の面積に足し込む
            int a = i-j; //その水たまりの面積
            while(S2.size() > 0 and S2.top().first > j){ //ここから？
                a += S2.top().second;
                S2.pop();
            }
            S2.push(make_pair(j,a));
        }
    }

    //出力部
    vector<int> ans;
    int t =0;
    while(S2.size()>0){
        ans.push_back(S2.top().second);
        S2.pop();
    } //vectorにそれぞれの面積を移し替える
    reverse(ans.begin(),ans.end());//順序入れ替え
    cout << sum << endl; //面積を出力
    cout << ans.size(); // 水たまりの数kを出力
    for (int i = 0; i < ans.size() ; ++i) {
        cout << " ";
        t += ans[i];
        cout << ans[i];
    }
    cout << endl;

    return 0;
}