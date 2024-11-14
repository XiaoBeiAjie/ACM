#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
typedef long long ll;

void solve() {
    ll n, q; cin >> n >> q;
    vector<ll> p(n + 1);
    for (ll i = 2; i <= n; i ++ ) 
        cin >> p[i];
    vector<ll> pos(n + 1), rk(n + 1);
    set<ll> st;
    for (ll i = 1; i <= n; i ++ ) {
        cin >> rk[i];
        pos[rk[i]] = i;
        if (pos[rk[i] >> 1]) st.insert(rk[i]);
        if (rk[i] == 1) st.insert(rk[i]);
    }
    while (q -- ) {
        ll idx_u, idx_v;
        cin >> idx_u >> idx_v;

        ll u = rk[idx_u], v = rk[idx_v];
        idx_v = pos[u], idx_u = pos[v];
        pos[u] = idx_u, pos[v] = idx_v;
        rk[idx_u] = u, rk[idx_v] = v;

        ll fu = u >> 1ll, fv = v >> 1ll;
        if (pos[fu] > idx_u && st.find(u) != st.end()) st.erase(u);
        if (pos[fv] > idx_v && st.find(v) != st.end()) st.erase(v);
        ll us1 = u << 1ll, us2 = u << 1ll | 1ll, vs1 = v << 1ll, vs2 = v << 1ll | 1ll;
        if (us1 <= n && idx_u > pos[us1] && st.find(us1) != st.end()) st.erase(us1); 
        if (us2 <= n && idx_u > pos[us2] && st.find(us2) != st.end()) st.erase(us2); 
        if (vs1 <= n && idx_v > pos[vs1] && st.find(vs1) != st.end()) st.erase(vs1); 
        if (vs2 <= n && idx_v > pos[vs2] && st.find(vs2) != st.end()) st.erase(vs2); 

        if (pos[fu] < idx_u && st.find(u) == st.end()) st.insert(u);
        if (pos[fv] < idx_v && st.find(v) == st.end()) st.insert(v);
        if (us1 <= n && idx_u < pos[us1] && st.find(us1) == st.end()) st.insert(us1); 
        if (us2 <= n && idx_u < pos[us2] && st.find(us2) == st.end()) st.insert(us2); 
        if (vs1 <= n && idx_v < pos[vs1] && st.find(vs1) == st.end()) st.insert(vs1); 
        if (vs2 <= n && idx_v < pos[vs2] && st.find(vs2) == st.end()) st.insert(vs2); 
        cout << (st.size() == n ? "Yes\n" : "No\n");
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T; cin >> T;
    while (T -- ) solve();
    return 0;
}