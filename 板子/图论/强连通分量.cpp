#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
typedef long long ll;

void solve() {
    int n, m;
    cin >> n >> m;
    vector e(n + 1, vector<int> ());
    for (int i = 1; i <= m; i ++ ) {
        int u, v;
        cin >> u >> v;
        e[u].push_back(v);
    }
    vector<int> dfn(n + 1), low(n + 1), scc(n + 1), sz(n + 1);
    stack<int> stk;
    vector<bool> in_stack(n + 1);
    int tot = 0, sc = 0;
    function<void(int)> tarjan = [&] (int u) {
        dfn[u] = low[u] = ++ tot;
        stk.push(u); in_stack[u] = true;
        for (auto v : e[u]) {
            if (!dfn[v]) {
                tarjan(v);
                low[u] = min(low[u], low[v]);
            }
            else if (in_stack[v])
                low[u] = min(low[u], dfn[v]);
        }
        if (dfn[u] == low[u]) {
            ++ sc;
            while (stk.top() != u) {
                int v = stk.top();
                scc[v] = sc;
                sz[sc] ++;
                in_stack[v] = false;
                stk.pop();
            }
            scc[u] = sc;
            sz[sc] ++;
            in_stack[u] = false;
            stk.pop();
        } 
    };
    for (int i = 1; i <= n; i ++ ) 
        if (!dfn[i]) 
            tarjan(i);
    cout << sc << "\n";
    vector<bool> vis(n + 1);
    for (int i = 1; i <= n; i ++ ) {
        if (vis[i]) continue;
        cout << i << " "; vis[i] = true;
        for (int j = i + 1; j <= n; j ++ ) 
            if (scc[i] == scc[j]) 
                cout << j << " ", vis[j] = true;
        cout << "\n";
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T = 1;
    while (T -- ) solve();
    system("pause");
    return 0;
}