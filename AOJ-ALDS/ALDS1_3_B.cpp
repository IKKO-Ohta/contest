# include <iostream>
# include <string>
# include <queue>
using namespace std;

int main(){
    // 構文：queue<型>名前, pairとmake_pairを使って名前と仕事量を管理
    queue< pair<string,int> > process;
    int n,t,q;
    string s;
    int time=0; //累計時間
    cin >> n >> q;
    for (int i = 0; i < n ; ++i) {
        cin >> s >> t;
        // make_pair オシャレ
        process.push(make_pair(s,t));
    }
    while(!process.empty()) {
        //処理中pair pを置く
        pair<string,int> p = process.front();
        process.pop();
        if (p.second > q){
            time += q;
            p.second -= q;
            process.push(p);
        }else{
            time += p.second;
            //処理終了したqueueの名前と累計時間を表示
            cout << p.first << " " << time << endl;
        }
    }
    return 0;
}