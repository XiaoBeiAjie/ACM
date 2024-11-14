#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve() {
    int n, k; cin >> n >> k;
    vector e(n + 1, vector<int>());
    vector<int> w(n + 1);
    for (int v = 1; v <= n; v ++ ) {
        int u; cin >> u >> w[v];
        e[u].push_back(v);
    }
    set<int> st1, st2;
    i64 sum = 0, ans = 0;
    function<void(int, int)> dfs = [&] (int u, int fa) {
        if (e[u].empty()) ans = max(ans, sum);
        for (auto v : e[u]) {
            if (v == fa) continue;
            if (st1.empty() || st1.size() < k) st1.insert(w[v]), sum += w[v];
            else if (st1.size() == k && *st1.begin() < w[v]) {
                int t = *st1.begin(); st1.erase(t); 
                st1.insert(w[v]); st2.insert(t);
                sum += w[v] - t;
            }
            else st2.insert(w[v]);
            dfs(v, u);
            if (st2.find(w[v]) != st2.end()) st2.erase(w[v]);
            else {
                st1.erase(w[v]);
                sum -= w[v];
                if (!st2.empty()) {
                    int t = *st2.rbegin();
                    st2.erase(t); st1.insert(t);
                    sum += t;
                }
            }   
        }   
    };
    dfs(0, -1);
    cout << ans << "\n";
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T = 1;
    while (T -- ) solve();
    return 0;
}