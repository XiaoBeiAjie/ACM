#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;
const int N = 200010, M = 666, mod = 998244353;
typedef long long LL;

int n, k;
vector<int> e[N];
vector<LL> f[N], g;
unordered_map<int, LL> F[N], G;  

void init() {
    for (int i = 1; i <= n; i ++ ) e[i].clear();
    F[1].clear();
}

int dfs1(int u, int fa) {
    int size_t = 1;
    f[u][1] = 1;
    for (auto v : e[u]) {
        if (v == fa) continue;
        int siz = dfs1(v, u);
        for (int j = 0; j <= k + 1; j ++ ) g[j] = 0;
        for (int j = 0; j <= min(siz, k); j ++ ) 
            for (int i = min(k + 1 - j, size_t); i; i -- ) 
                g[i + j] = (1LL * g[i + j] + 1LL * f[u][i] * f[v][j] % mod) % mod;   
        size_t += siz;
        for (int i = 0; i <= k + 1; i ++ ) f[u][i] = g[i];
    }
    f[u][0] = (f[u][k] + f[u][k + 1]) % mod;
    return size_t;
}

void dfs2(int u, int fa) {
    F[u][1] = 1;
    for (auto v : e[u]) {
        if (v == fa) continue;
        dfs2(v, u);
        G.clear();
        for (auto j : F[v]) 
            for (auto i : F[u])
                if (i.x + j.x > k + 1) continue;
                else G[i.x + j.x] = (1LL * G[i.x + j.x] + 1LL * i.y * j.y % mod) % mod;
        F[u].clear();
        for (auto t : G)
            F[u][t.x] = t.y;
    }
    F[u][0] = (F[u][k] + F[u][k + 1]) % mod;
    if (F[u][0] == 0) F[u].erase(0);
    if (F[u][k] == 0) F[u].erase(k);
    if (F[u][k + 1] == 0) F[u].erase(k + 1); 
    for (auto v : e[u]) 
        if (v != fa) F[v].clear();
}

void solve() {
    cin >> n >> k;
    init();
    for (int i = 1; i < n; i ++ ) {
        int a, b;
        cin >> a >> b;
        e[a].push_back(b);
        e[b].push_back(a);
    }
    dfs2(1, 0);
    cout << (F[1][0] % mod + mod) % mod << endl;    
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T;cin >> T;
    while (T -- ) solve();
    system("pause");
    return 0;
}