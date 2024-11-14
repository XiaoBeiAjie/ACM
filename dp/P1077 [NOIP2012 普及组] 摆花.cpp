#include <bits/stdc++.h>
using namespace std;
const int N = 100010, mod = 1e6 + 7;
typedef long long ll;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> w(n + 1);
    for (int i = 1; i <= n; i ++ ) 
        cin >> w[i];
    vector<int> f(m + 1);
    f[0] = 1;
    for (int i = 1; i <= n; i ++ ) {
        vector<int> g(m + 1);
        for (int j = 0; j <= w[i]; j ++ ) 
            for (int k = j; k <= m; k ++ ) 
                g[k] = (g[k] + f[k - j]) % mod;
        f = g;       
    }   
    cout << f[m] % mod << "\n";            
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T = 1;
    while (T -- ) solve();
    system("pause");
    return 0;
}