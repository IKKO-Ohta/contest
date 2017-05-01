#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#define REP(i,n) for(int i=0;i<n;i++)
using namespace std;

int n, k;
string s;
vector<int> order;
vector<int> tmp;
vector<int> sa;

bool compare_sa(const int &i, const int &j)
{
    if(order[i] != order[j]) return order[i] < order[j];
    else
    {
        int ri = i + k <= n ? order[i+k] : -1;
        int rj = j + k <= n ? order[j+k] : -1;
        return ri < rj;
    }
}

void construct_sa()
{
    for(int i = 0; i <= n; i++)
    {
        sa[i] = i;
        order[i] = i < n ? s[i] : -1;
    }
    for(k = 1; k <= n; k*=2)
    {
        sort(sa.begin(),sa.end(),compare_sa);
        tmp[sa[0]] = 0;
        for(int i = 1; i <= n; i++)
            tmp[sa[i]] = tmp[sa[i-1]] + (compare_sa(sa[i-1],sa[i])?1:0);
        for(int i = 0; i <= n; i++)
            order[i] = tmp[i];
    }
}

void init()
{
    n = s.size();
    order.resize(n+1);
    tmp.resize(n+1);
    sa.resize(n+1);
    construct_sa();
}

bool contain(string t)
{
    int l=0, r=n;
    while(r-l>1)
    {
        int m = (l+r)/2;
        if(s.compare(sa[m],t.size(),t)<0) l = m;
        else r = m;
    }
    return s.compare(sa[r],t.size(),t) == 0;
}

int main()
{
    cin >> s;
    string t;
    int q; cin >> q;
    init();
    construct_sa();
    REP(i,q)
    {
        cin >> t;
        cout << contain(t) << endl;
    }
    return 0;
}