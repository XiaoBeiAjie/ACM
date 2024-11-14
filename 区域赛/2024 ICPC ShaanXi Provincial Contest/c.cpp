#include <bits/stdc++.h>
using namespace std;
const int N = 200010;
typedef long long LL;

int n, ans, l;
vector<vector<int>> g(N);
vector<int> p(N), siz(N, 1), d(N), f(N);
unordered_map<int, vector<int>> mp;

int find(int x) {
    if (p[x] != x) p[x] = find(p[x]);
    return p[x];
}

void dfs(int u, int fa) {
    for (auto v : g[u]) {
        if (v == fa) continue;
        dfs(v, u);
        l = max(l, f[u] + f[v] + 1);
        f[u] = max(f[u], f[v] + 1);
    }
}

void torport
(int x) {
    queue<int> q;
    int res = 0, cnt = 0;
    for (auto u : mp[x]) 
        q.push(u), cnt ++;
    while (!q.empty()) {
        auto u = q.front();
        q.pop();
        for (auto v : g[u]) {
            d[v] --;
            if (d[v] == 1) q.push(v), cnt ++;
        }
    }
    cerr << cnt << " " << siz[x] << " " << x << endl;
    if (cnt == siz[x]) {
        l = 0;
        dfs(x, 0);
        ans += l;
    }
    else 
        ans += siz[x] - cnt;
    
}

void solve() {
    cin >> n;
    for (int i = 1; i <= 2 * n; i ++ ) 
        p[i] = i;
    for (int i = 1; i <= n; i ++ ) {
        int x, y = i; cin >> x;
        g[x].push_back(y);
        g[y].push_back(x);
        d[y] ++, d[x] ++;
        x = find(x), y = find(y);
        if (x == y) continue;
        if (siz[x] < siz[y]) swap(y, x);
        p[y] = x;
        siz[x] += siz[y];
    }
    for (int i = 1; i <= 2 * n; i ++ ) 
        if (d[i] == 1) mp[p[i]].push_back(i);
    for (int i = 1; i <= 2 * n; i ++ ) {
        if (p[i] == i && d[i]) 
            torport(i); 
    }
    cout << ans << endl;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T = 1;
    while (T -- ) solve();
    system("pause");
    return 0;
}