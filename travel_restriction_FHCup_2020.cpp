#include<bits/stdc++.h>

using namespace std;

#define fi first 
#define se second
#define FOR(a, b, c) for (int a = b; a <= c; ++a)
#define FORW(a, b, c) for(int a = b; a >= c; --a)
#define pb push_back
#define SZ(a) ((int)a.size())
#define int long long

const int N = 2e2;
const int oo = 1e9;
const int mod = 1e9 + 7;

typedef pair<int, int> ii;

int n;
vector<int> vi[N];
bool in[N], out[N], f[N][N], visit[N];

signed main(){  
	freopen("travel_restrictions_input.txt", "r", stdin);
	freopen("travel_restrictions.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0); 
    cout.tie(0);
	
	int t; cin >> t;
	FOR(cases, 1, t)	{
		cin >> n;
		FOR(i, 1, n) FOR(j, 1, n) f[i][j] = false;
		FOR(i, 1, n) {
			char c; cin >> c;
			in[i] = (c == 'Y');
			f[i][i] = 1;
			vi[i].clear();
		}       
		FOR(i, 1, n) {
			char c; cin >> c;
			out[i] = (c == 'Y');
		}

		FOR(i, 1, n) {
			if(i > 1 && out[i] && in[i - 1]) vi[i].pb(i - 1);
			if(i < n && out[i] && in[i + 1]) vi[i].pb(i + 1);
		}
		FOR(i, 1, n) {
			FOR(j, 1, n) visit[j] = false;
			queue<int> pq; pq.push(i); visit[i] = 1;
			while(!pq.empty()) {
				int u = pq.front(); pq.pop();
				for(int v: vi[u]) if(!visit[v]) {
					visit[v] = 1;
					pq.push(v);
				}
			}
			FOR(j, 1, n) f[i][j] = visit[j];
		}
		cout << "Case #" << cases << ":\n";
		FOR(i, 1, n) {
			FOR(j, 1, n) {
				if(f[i][j]) cout << "Y";
				else cout << "N";
			}
			cout << '\n';
		} 
	}

}	
