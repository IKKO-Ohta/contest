#include <bits/stdc++.h>
using namespace std;
#define int long long
#define REP(i,n) for(int i = 0; i < (int)(n); ++i)
#define DEBUG(x) cerr << #x << " = " << x << endl

struct suffix_array {
    int n;
    vector<int> x;
    suffix_array(const char *s) : n(strlen(s)), x(n) {
        vector<int> r(n), t(n);
        for (int i = 0; i < n; ++i) r[x[i] = i] = s[i];
        for (int h = 1; t[n-1] != n-1; h *= 2) {
            auto cmp = [&](int i, int j) {
                if (r[i] != r[j]) return r[i] < r[j];
                return i+h < n && j+h < n ? r[i+h] < r[j+h] : i > j;
            };
            sort(x.begin(), x.end(), cmp);
            for (int i = 0; i+1 < n; ++i) t[i+1] = t[i] + cmp(x[i], x[i+1]);
            for (int i = 0; i < n; ++i)   r[x[i]] = t[i];
        }
    }
    int operator[](int i) const { return x[i]; }
};

bool contain(const string &S, int *sa, const string &T) {
    int lb = -1, ub = S.size() - 1;
    while(ub - lb > 1) {
        int mid = (lb + ub) / 2;
        if(S.compare(sa[mid], T.size(), T) >= 0) ub = mid;
        else lb = mid;
    }
    return S.compare(sa[ub], T.size(), T) == 0;
}

signed main() {
    ios::sync_with_stdio(false);
    string T; cin >> T;
    int Q; cin >> Q;
    suffix_array sary(T.c_str());
    while(Q--) {
        string P; cin >> P;
        cout << (contain(T, sary.x.data(), P) ? 1 : 0) << endl;
    }
}
