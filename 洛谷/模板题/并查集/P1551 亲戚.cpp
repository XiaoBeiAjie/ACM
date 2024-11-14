#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
typedef long long ll;

void solve() {
    int n, m, q;
    cin >> n >> m >> q;
    vector<int> p(n + 1);
    for (int i = 1; i <= n; i ++ ) 
        p[i] = i;
    function<int(int)> find = [&] (int x) {
        return x == p[x] ? x : p[x] = find(p[x]);
    };
    for (int i = 1; i <= m; i ++ ) {
        int u, v;
        cin >> u >> v;
        u = find(u), v = find(v);
        if (u == v) continue;
        p[u] = v;
    }
    while (q -- ) {
        int u, v;
        cin >> u >> v;
        u = find(u), v = find(v);
        cout << (u == v ? "Yes\n" : "No\n");
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