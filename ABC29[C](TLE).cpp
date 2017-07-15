//------------------------------------------
// C++ templete 
//------------------------------------------
#include <bits/stdc++.h>
#define int long long
using namespace std;

//typedef
//------------------------------------------
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef vector<PII> VP;

//REPEAT
//------------------------------------------
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)

//container util
//------------------------------------------
#define pb push_back
#define paired make_pair
#define ALL(a) (a).begin(),(a).end()
#define PRINT(V) for (auto v : (V)) cout << v << " "
#define SORT(V) sort((V).begin(),(V).end())
#define RSORT(V) sort((V).rbegin(), (V).rend())

//constant
//------------------------------------------
const int MOD = 1000000007;
const int INF = 1061109567;
const double EPS = 1e-10;
const double PI  = acos(-1.0);
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

//math
//------------------------------------------
int QP(int a,int b){int ans=1;do{if(b&1)ans=1ll*ans*a%MOD;a=1ll*a*a%MOD;}while(b>>=1);return ans;}
int QP(int a,int b,int MOD){int ans=1;do{if(b&1)ans=1ll*ans*a%MOD;a=1ll*a*a%MOD;}while(b>>=1);return ans;}
int GCD(int a,int b){return b?GCD(b,a%b):a;}

//debug
//------------------------------------------
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;
template<typename T> ostream& operator<<(ostream& s, const vector<T>& v) {
    int len = v.size();
    for (int i = 0; i < len; ++i) {
        s << v[i]; if (i < len - 1) s << "\t";
    }
    return s;
}
template<typename T> ostream& operator<<(ostream& s, const vector< vector<T> >& vv) {
    int len = vv.size();
    for (int i = 0; i < len; ++i) {
        s << vv[i] << endl;
    }
    return s;
}

//grobal variable
//------------------------------------------
int N;
map<PPI,int> mp;

//main
//------------------------------------------
int dfs(int t,int x){
    // 停止条件
    int ret;
    if(x * 2 > N and x * 2 + 1> N){
        if(t % 2 == 0){
            return -1; // 後手の勝ち
        }else{
            return 1; //先手の勝ち
        }
    }

    int res0,res1;
    if (t % 2 == 1){ //後手
        REP(i,2)
            if(i == 0 and 2*x + 1 <= N){
                res0 = dfs(t+1,2*x+1);
            }else{
                res1 = dfs(t+1,2*x);
            }
        ret = min(res0,res1);
        //cout << "a" << ret << endl;
    }
    
    if (t % 2 == 0){ //先手 
        REP(i,2)
            if(i == 0 and 2*x + 1 <= N){
                res0 = dfs(t+1,2*x+1);
            }else{
                res1 = dfs(t+1,2*x);
            }
        ret = max(res0,res1);
        //cout << "t" << ret << endl;
    }

    return ret;
}



signed main(){
    cin >> N;
    int ans = dfs(0,1);
    cout << ans << endl;
    if (ans == 1){
        cout << "Takahashi" << endl;
    }else{
        cout << "Aoki" << endl;
    }
}
