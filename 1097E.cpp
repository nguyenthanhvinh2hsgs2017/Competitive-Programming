#include<bits/stdc++.h>
using namespace std;
 
#define fi first
#define se second
#define FOR(a, b, c) for(int a = b; a <= c; ++a)
#define pb push_back
 
const int N = 1e5 + 10;
const int oo = 1e9;
typedef pair<int, int> ii;
int n, cnt, maxn;
bool visit[N];
vector<int> vi;
vector< int > ans[N];
int f[N];
 
vector<int> LIS(vector<int> tmp)    {
    vector<ii> res;
    FOR(i, 0, tmp.size()) f[i] = -1;
    for(int i = 0; i < tmp.size(); ++i) {
        int pos = upper_bound(res.begin(), res.end(), ii(tmp[i], 0)) - res.begin();
        if(pos == res.size()) {
            if(res.size()) f[i] = res.back().se;
            res.pb(ii(tmp[i], i));
        } else {
            if(pos > 0) f[i] = res[pos - 1].se;
            res[pos] = ii(tmp[i], i);
        }
    }
    int lst = res.back().se;
    vector<int> ret;
    while(lst >= 0) {
        ret.pb(tmp[lst]); lst = f[lst];
    }
    reverse(ret.begin(), ret.end());
    return ret;
}
void solve()    {
    int k = 0; while(k * (k + 1) / 2 <= n) k ++;
    vector<int> cur = LIS(vi);
    if(cur.size() >= k) {
        for(int v: cur) visit[v] = true;
        vector<int> tmp; for(int v: vi) if(!visit[v]) tmp.pb(v);
        cnt ++;
        for(int v: cur) ans[cnt].pb(v);
        vi = tmp; tmp.clear();
        n = vi.size();
    } else {
        vector<int> lis;
        vector< vector<int> > trace;
        trace.resize((int)vi.size() + 1);
        for(int v: vi)  {
            int pos = upper_bound(lis.begin(), lis.end(), v) - lis.begin();
            if(pos == lis.size())  {
                lis.pb(v); trace[lis.size() - 1].pb(v);
            } else {
                trace[pos].pb(v);
                lis[pos] = v;
            }
        }
        for(int i = 0; i < lis.size(); ++i) ans[++cnt] = trace[i];
        n = 0;
    }
}
signed main()
{
    //freopen("test.inp", "r", stdin);
    int t; scanf("%d", &t);
    while(t --) {
        scanf("%d", &n); maxn = n;
        FOR(i, 0, n) ans[i].clear();
        cnt = 0; vi.clear(); memset(visit, false, sizeof visit);
 
        FOR(i, 1, n) {
            int a; scanf("%d", &a);
            vi.pb(a);
        }
        while(n > 0)    solve();
        printf("%d\n", cnt);
        FOR(i, 1, cnt)  {
            printf("%d ", ans[i].size());
            for(int v: ans[i]) printf("%d ", v);
            printf("\n");
        }
    }
}
