#include<bits/stdc++.h>
using namespace std;
 
#define FOR(a, b, c) for(int a = b; a <= c; ++a)
#define FORW(a, b, c) for(int a = b; a >= c; --a)
#define pb push_back
#define fi first
#define se second
#define SZ(a) ((int)a.size())
#define int long long
 
mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());
 
const int oo = 1e9;
const int N = 1e6 + 100;
const int mod = 1e9 + 7;
 
typedef pair<int, int> ii;
 
int n;
int a[N];
bool prime_check[N]; 
vector<int> prime;
 
int Random(int lef, int rig) {
	return (int)(rd() % (rig - lef + 1)) + lef;
}
 
int solve(int val) {
	vector<int> tmp;
	for(auto v: prime) if(val % v == 0) {
		tmp.pb(v);
		while(val % v == 0) val /= v;
	}
	if(val > 1) tmp.pb(val);
 
	int res = oo;
	for(auto v: tmp) {
		int cnt = 0;
		FOR(i, 1, n) {
			if(a[i] <= v) cnt += v - a[i];
			else cnt += min(a[i] % v, v - a[i] % v);
		}
		res = min(res, cnt);
	}
	return res;
}
 
signed main(){
	// freopen("test - Copy.inp", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
 
	// double t = clock();
	// while((clock() - t) / CLOCK_PER_SEC < 2.2) {
	// 	cout << "blu\n";
	// }
 
	cin >> n;
	FOR(i, 1, n) cin >> a[i];
	FOR(i, 2, N - 1) if(!prime_check[i]) {
		prime.pb(i);
		for(int j = i*i; j < N; j += i) prime_check[j] = 1;
	}
	int ans = 0;
	FOR(i, 1, n) ans += (a[i] % 2);
 
	FOR(test, 1, 20) {
		int pos = Random(1, n);
		int val = a[pos];
		if(val > 2) ans = min(ans, solve(val));
		if(val > 3) ans = min(ans, solve(val - 1));
		ans = min(ans, solve(val + 1));
	}
	cout << ans;
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
