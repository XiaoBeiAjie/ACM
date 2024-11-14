#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
typedef long long LL;

int n, l, r;

void solve() {
    cin >> n >> l >> r;
    vector<int> f(n + 1), w(n + 1), pos(n + 1), dp(n + 1);
    for (int i = 1; i <= n; i ++ ) 
        cin >> w[i], w[i] += w[i - 1];
    for (int i = n, j = n - 1; i; i -- ) {
        while (j >= 0 && w[i] - w[j] < l) j --;
        if (w[i] - w[j] > r) pos[i] = -1;
        else pos[i] = j;
    }
    for (int i = 1; i <= n; i ++ ) {
        if (pos[i] != -1) f[i] = max(f[pos[i]] + 1, dp[pos[i]] + 1);
        dp[i] = max(f[i], dp[i - 1]);
    }
        
    cout << dp[n] << endl;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T; cin >> T;
    while (T -- ) solve();
    system("pause");
    return 0;
}