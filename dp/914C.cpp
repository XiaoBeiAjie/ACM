#include <bits/stdc++.h>
using namespace std;
const int N = 1010, mod = 1000000007;
typedef long long LL;

string n;
int k;
int f[N];
int C[N][N];
LL ans;

void solve() {
    cin >> n >> k;
    if (k == 0) cout << "1" << endl, void(); 
    int res = 0;
    for (int i = 0; i < n.size(); i ++ ) {
        if (n[i] == '0') continue;
        for (int j = max(res, 1); j < 1000; j ++ ) 
            if (f[j] == k - 1) {
                ans = (ans + C[n.size() - 1 - i][j - res]) % mod;
              
            }
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    f[1] = 0;
    for (int i = 2; i <= 1000; i ++ ) 
        f[i] = f[__builtin_popcount(i)] + 1;
    for (int i = 0; i <= 1000; i ++ ) C[i][0] = 1;
    for (int i = 1; i <= 1000; i ++ ) 
        for (int j = 0; j <= 1000; j ++ ) 
            C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % mod;
    int T = 1;
    while (T -- ) solve();
    system("pause");
    return 0;
}