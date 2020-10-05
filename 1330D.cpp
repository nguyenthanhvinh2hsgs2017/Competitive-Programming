#include<bits/stdc++.h>
using namespace std;
 
#define FOR(a, b, c) for(int a = b; a <= c; ++a)
#define FORW(a, b, c) for(int a = b; a >= c; --a)
#define fi first
#define se second
#define pb push_back
#define int long long
 
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
 
const int N = 2e5 + 10;
const int oo = 1e18;
 
int maxn, n, m, cnt = 0;
int f[100], dp[100][2];
string s;
//int find(int u) { return (pr[u] == u) ? u : (pr[u] = find(pr[u])); }
 
signed main()  {
//    freopen("test.inp", "r", stdin);
//    freopen("test.out", "w", stdout);
    ios_base::sync_with_stdio(false); cout.tie(0);
    int t; cin >> t;
    while(t -- )    {
        cin >> maxn >> m;
 
        cnt = 0; s = "";
        memset(f, 0, sizeof f);
        memset(dp, 0, sizeof dp);
 
        int tmp = maxn;
        while(tmp > 0) {
            s += char(tmp % 2 + '0');
            cnt ++, tmp /= 2;
        }
        FOR(i, 1, cnt - 1) f[i] = (1 << (i - 1)) % m;
        f[cnt] = 1;
        FOR(i, 1, cnt - 1) {
            if(s[i - 1] == '0') continue;
            f[cnt] += f[i] % m;
            f[cnt] %= m;
        }
        //cout << s << '\n';
        //FOR(i, 1, cnt) cout << f[i] << '\n';
        dp[0][0] = 1;
        FOR(i, 1, cnt) {
            dp[i][1] = f[i];
            dp[i][1] = ( dp[i][1] + dp[i - 1][1] + dp[i - 1][1] * f[i]) % m;
        }
        cout << dp[cnt][1] % m << '\n';
    }
}
