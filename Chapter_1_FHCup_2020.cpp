#include<bits/stdc++.h>

using namespace std;

#define fi first 
#define se second
#define FOR(a, b, c) for (int a = b; a <= c; ++a)
#define FORW(a, b, c) for(int a = b; a >= c; --a)
#define pb push_back
#define SZ(a) ((int)a.size())
#define int long long

const int N = 2e6 + 100;
const int oo = 1e9;
const int mod = 1e9 + 7;

typedef pair<int, int> ii;

int n, cap_max;
multiset<int> st;
int cost[N], f[N];

signed main(){  
	freopen("running_on_fumes_chapter_1_input.txt", "r", stdin);
	freopen("chapter_1.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0); 
    cout.tie(0);
    int t; cin >> t;
    FOR(cases, 1, t) {
        cin >> n >> cap_max;
        st.clear();
        FOR(i, 1, n) cin >> cost[i], f[i] = -1;
        f[1] = 0; cost[1] = 0;
        int pointer = 1;
        st.insert(0);

        FOR(i, 2, n) {
            while(i - pointer > cap_max && SZ(st) > 0) {
                if(pointer == 1) st.erase(st.find(0));
                else if(cost[pointer] > 0) {
                    st.erase(st.find(f[pointer] + cost[pointer]));
                }
                pointer += 1;
            }
            if(SZ(st) == 0) break;
            if(cost[i] > 0) {
                auto it = st.begin(); 
                f[i] = (*it);
                st.insert(f[i] + cost[i]);
            }
        }
        int ans = -1;
        if(cap_max >= n - 1) ans = 0;
        FOR(i, 1, n) if(n - i <= cap_max && f[i] != -1){
            // cout << i << ' ' << f[i] << '\n';
            if(ans == -1 || ans > f[i] + cost[i])
                ans = f[i] + cost[i]; 
        }
        cout << "Case #" << cases << ": " << ans << '\n';
    }
}	
