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
const int INF = 1e16;
const double EPS = 1e-16;
const double PI  = acos(-1.0);
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

//math
//------------------------------------------
int QP(int a,int b){int ans=1;do{if(b&1)ans=1ll*ans*a%MOD;a=1ll*a*a%MOD;}while(b>>=1);return ans;}
int QP(int a,int b,int MOD){int ans=1;do{if(b&1)ans=1ll*ans*a%MOD;a=1ll*a*a%MOD;}while(b>>=1);return ans;}
int GCD(int a,int b){return b?GCD(b,a%b):a;}

//vector util
//------------------------------------------

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

vector<int> SLICE(const vector<int>& v, int start=0, int end=-1) {
    int oldlen = v.size();
    int newlen;

    if (end == -1 or end >= oldlen){
        newlen = oldlen-start;
    } else {
        newlen = end-start;
    }

    vector<int> nv(newlen);

    for (int i=0; i<newlen; i++) {
        nv[i] = v[start+i];
    }
    return nv;
}

//debug
//------------------------------------------
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;

//grobal variable
//------------------------------------------
int N;
VI Vec;

//main
//------------------------------------------
signed main(){
    cin >> N;

    REP(i,N){
        int t; cin >> t;
        Vec.pb(t);
        accum += t;
    }

}



