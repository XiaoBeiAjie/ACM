#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
typedef long long ll;

void solve() {
    int n; cin >> n;
    vector<int> v(n + 1), w(n + 1);
    for (int i = 1; i <= n; i ++ ) 
        cin >> v[i] >> w[i];
    unordered_map<int, int> f;
    f[0] = 0;
    for (int i = 1; i <= n; i ++ ) {
        unordered_map<int, int> g;
        for (auto [x, y] : f)
            g[x + v[i]] = y + w[i];
        for (auto [x, y] : g)
            if (f.find(x) != f.end()) 
                f[x] = max(y, f[x]);
            else 
                f[x] = y; 
    }
    int ans = 0;
    for (auto [x, y] : f) 
        if (x < 0 || y < 0) continue;
        else ans = max(ans, x + y);
    cout << ans << "\n";
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T = 1;
    while (T -- ) solve();
    system("pause");
    return 0;
}