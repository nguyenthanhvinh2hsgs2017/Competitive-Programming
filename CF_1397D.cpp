#include <bits/stdc++.h>
 
using namespace std;
 
#define FOR(a, b, c) for(int a = b; a <= c; ++a)
#define FORW(a, b, c) for(int a = b; a >= c; --a)
#define pb push_back
#define fi first
#define se second
#define SZ(a) ((int)a.size())
#define int long long
 
typedef pair< int, int > ii;
typedef pair<int, pair<int, int> > iii;
 
const int mod = 1e9 + 7;
const int N = 2e5 + 100;
const int oo = 1e9;
 
int n;
int a[N];
 
signed main(){
	// freopen("test.inp", "r", stdin);
	// freopen("beach_umbrellas_input.txt", "r", stdin);
	// freopen("practice_output.txt", "w", stdout);
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while(t --)	{
		cin >> n;
 
		int maxn = 0, sum = 0;
		FOR(i, 1, n) {
			cin >> a[i];
			maxn = max(maxn, a[i]);
			sum += a[i];
		}
		if(maxn <= (sum / 2)) {
			if(sum % 2 == 0) cout << "HL\n";
			else cout << "T\n";
		} else cout << "T\n";
	}
		
}	
