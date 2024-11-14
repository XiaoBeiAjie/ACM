#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
typedef long long LL;

vector<vector<int>> g(N);
vector<int> d(N);
vector<int> vis(N);

void solve() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i ++ ) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
        d[u] ++, d[v] ++;
    }
    queue<int> q;
    for (int i = 1; i <= n; i ++ ) 
        if (d[i] == 1) vis[i] = 1, q.push(i);
    while (q.size()) {
        auto u = q.front();
        q.pop();
        for (auto v : g[u]) {
            if (vis[v]) continue;
            d[v] --;
            if (d[v] == 1) vis[v] = 1, q.push(v);
        }    
    }
    for (int i = 1; i <= n; i ++ ) 
        if (!vis[i]) 
            cout << i << " ";
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T = 1;
    while (T -- ) solve();
    system("pause");
    return 0;
}