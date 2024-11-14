#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve() {
    int n; cin >> n;
    vector g(n + 1, vector<int> (n + 1));
    for (int i = 1; i <= n; i ++ ) 
        for (int j = 1; j <= n; j ++ ) 
            cin >> g[i][j];
    if (g[1][2] > g[1][1] && g[2][1] > g[1][1]) return cout << 0 << "\n", void();
    if (g[1][2] < g[1][1] && g[2][1] > g[1][1]) return cout << 1 << "\n", void();
    if (g[1][2] < g[1][1] && g[2][1] < g[1][1]) return cout << 2 << "\n", void();
    if (g[1][2] > g[1][1] && g[2][1] < g[1][1]) return cout << 3 << "\n", void();
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T = 1;
    while (T -- ) solve();
    return 0;
}