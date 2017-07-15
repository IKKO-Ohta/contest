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
int B[2][3];
int C[3][2];
VVI f;


//main
//------------------------------------------

int evaluate(VVI f){
    int accum = 0;
    REP(i,2)
        REP(j,3)
            if(f[i][j] == f[i+1][j]) accum += B[i][j];
    REP(i,3)
        REP(j,2)
            if(f[i][j] == f[i][j+1]) accum += C[i][j];
    return accum;
}

int dfs(int t){
    int ret;
    // 停止条件
    if(t == 9){
        //REP(i,3) REP(j,3) if (f[i][j] == 0) f[i][j] = 1;
        int ans = evaluate(f);
        //cout << ans << endl;
        return ans;
    }

    if (t % 2 == 1){
        ret = INF;
        REP(i,3) REP(j,3) if (f[i][j] == 0){
            f[i][j] = 1; //石を置く
            //cout << f << endl;
            ret = min(ret,dfs(t+1));
            //cout << ret << endl;
            f[i][j] = 0;
        }
    }
    
    if (t % 2 == 0){
        ret = 0;
        REP(i,3) REP(j,3) if (f[i][j] == 0){
            f[i][j] = -1;
            //cout << f << endl;
            ret = max(ret,dfs(t+1));
            //cout << ret << endl;
            f[i][j] = 0;
        }
    }
    return ret;
}


signed main(){
    int sum = 0;
    REP(i,2)
        REP(j,3){
            cin >> B[i][j];
            sum += B[i][j];}
    REP(i,3)
        REP(j,2){
            cin >> C[i][j];
            sum += C[i][j];}
        
    VI a = {0,0,0}; f.pb(a);
    VI b = {0,0,0}; f.pb(b);
    VI c = {0,0,0}; f.pb(c);
    int ans = dfs(0);
    cout << ans << endl;
    cout << sum - ans << endl;
}