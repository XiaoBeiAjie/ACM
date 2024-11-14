#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    int n; cin >> n;
    vector<array<int, 2>> w(n + 1);
    for (int i = 1; i <= n; i ++ ) 
        cin >> w[i][0] >> w[i][1];
    int ans = w[1][0];
    for (int i = 2; i <= n; i ++ ) 
        if (w[i][0] >= ans && w[i][1] >= w[1][1]) ans = -1;
    cout << ans << "\n";
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T; cin >> T;
    while (T -- ) solve();
    return 0;
}