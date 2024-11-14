#include <bits/stdc++.h>
using namespace std;
const int N = 100010, mod = 1000000007;
typedef long long ll;

void solve() {
    constexpr int primes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};
    int n; cin >> n;
    vector<int> w(n + 1);
    map<int, vector<pair<int, int>>> mp;
    for (int i = 1; i <= n; i ++ ) {
        cin >> w[i];
        int mask = 0, val = 1;
        for (int j = 0; j < 11; j ++ ) {
            while (!(w[i] % primes[j])) {
                w[i] /= primes[j];
                if (mask & (1 << j)) val = 1ll * val * primes[j] % mod;
                mask ^= (1 << j);
            }
        }
        mp[w[i]].push_back({mask, val});
    }
    vector<int> f(1 << 12);
    f[0] = 1;
    for (auto [p, y] : mp) {
        for (auto [mask, val] : y) {
            vector<int> g = f;
            if (p != 1) 
                mask |= (1 << 11);
            for (int s = 0; s < (1 << 12); s ++ ) {
                int ns = s ^ mask;
                int res = 1ll * f[s] * val % mod;
                int both = s & mask;
                for (int i = 0; i < 11; i ++ ) 
                    if (both & (1 << i)) 
                        res = 1ll * res * primes[i] % mod;
                if (both & (1 << 11)) 
                    res = 1ll * res * p % mod; 
                g[ns] = (g[ns] + res) % mod;   
            }
            f = move(g);
        }
        for (int i = (1 << 11); i < (1 << 12); i ++ )
            f[i] = 0;
    }
    cout << f[0] - 1 << endl;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T = 1;
    while (T -- ) solve();
    system("pause");
    return 0;
}