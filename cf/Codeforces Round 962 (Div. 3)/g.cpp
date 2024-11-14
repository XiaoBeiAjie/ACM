#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
typedef long long ll;


mt19937_64 rng {chrono::steady_clock::now().time_since_epoch().count()};

void solve() {
    int n, m;
    cin >> n >> m;
    vector<ll> f(n + 1);
    for (int i = 1; i <= m; i ++ ) {
        int a, b;
        cin >> a >> b;
        ll t = rng();
        f[a] ^= t;
        f[b] ^= t;
    }
    for (int i = 2; i <= n; i ++ )
        f[i] ^= f[i - 1];
    map<ll, int> cnt;
    int ans = 0;
    for (int i = 1; i <= n; i ++ ) 
        ans = max(ans, ++ cnt[f[i]]);
    cout << n - ans << "\n";
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T; cin >> T;
    while (T -- ) solve();
    system("pause");
    return 0;
}