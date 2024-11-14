#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
typedef long long LL;

void solve() {
    LL n, k;
    cin >> n >> k;
    vector<int> w(n + 1);
    for (int i = 1; i <= n; i ++ ) 
        cin >> w[i];
    LL ans = 1;
    for (int i = 1; i <= n; i ++ ) 
        if (ans >= w[i] + (i - 1) * (k - 1))
            ans += k;
        else if (ans >= w[i]) 
            ans += (ans - w[i]) / (i - 1) + 1;
        else break;
    cout << ans << endl; 
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T; cin >> T;
    while (T -- ) solve();
    system("pause");
    return 0;
}