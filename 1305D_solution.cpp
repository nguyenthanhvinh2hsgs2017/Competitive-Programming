#include<bits/stdc++.h>
using namespace std;
 
#define FOR(a, b, c) for(int a = b; a <= c; ++a)
#define FORW(a, b, c) for(int a = b; a >= c; --a)
#define pb push_back
#define fi first
#define se second
#define SZ(a) ((int)a.size())
#define int long long
 
const int oo = 1e9;
const int N = 2e5 + 100;
const int mod = 1e9 + 7;
 
typedef pair<int, int> ii;
 
int n;
int deg[N];
bool visit[N];
vector<int> vi[N];
 
int query(int u, int v) {
	cout << "? " << u << ' ' << v << '\n'; cout.flush();
	int res; cin >> res;
	return res;
}
void ok(int x) { cout << "! " << x; exit(0); }
signed main(){
	// freopen("test - Copy.inp", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	cin >> n;
	FOR(i, 1, n - 1) {
		int u, v; cin >> u >> v;
		vi[u].pb(v); vi[v].pb(u);
	}
	FOR(i, 1, n) deg[i] = SZ(vi[i]);
 
	int cnt = 0;
	while(cnt < n - 1) {
		int u = -1, v = -1;
		FOR(i, 1, n) if(!visit[i] && deg[i] == 1) {
			if(u == -1) u = i;
			else if(v == -1) v = i;
		}
		visit[u] = visit[v] = 1;
		for(auto v1: vi[u]) if(!visit[v1]) deg[v1] -= 1;
		for(auto v1: vi[v]) if(!visit[v1]) deg[v1] -= 1;
		cnt += 2;
 
		int LCA = query(u, v);
		if(LCA == u || LCA == v) ok(LCA);
	}
	FOR(i, 1, n) if(!visit[i]) ok(i);
}
/*
7
1 2
1 3
1 4
1 5
1 6
1 7
*/
