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
 
const int N = 2e5 + 100;
const int maxN = 1e16;
const int oo = 1e18;
const int mod  = 1e9 + 7;
 
int n, x; 
int a[N], b[N];
 
signed main()  {
//    freopen("test.inp", "r", stdin);
//    freopen("spm.out", "w", stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    FOR(i, 1, n) cin >> a[i];
    sort(a + 1, a + n + 1);
 
    int res = n / 2;
    if(n % 2 == 0) res -= 1;
    cout << res << '\n';
    FOR(i, 1, n) {
        if(i % 2) cout << a[n - ((i + 1) / 2) + 1] << ' ';
        else cout << a[i / 2] << ' ';
    }
}
