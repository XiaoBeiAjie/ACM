#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve() {
    int n; cin >> n;
    vector<array<int, 2>> w(n + 1);
    for (int i = 1; i <= n; i ++ ) 
        cin >> w[i][0] >> w[i][1];
    vector<int> b(n + 1);
    iota(b.begin(), b.end(), 0);
    sort(b.begin() + 1, b.end(), [&] (int &i, int &j) {
        return w[i][0] + w[i][1] < w[j][0] + w[j][1];
    });
    i64 sum = 0, ans = LLONG_MIN;
    for (int i = 1; i <= n; i ++ ) {
        ans = max(ans, sum - w[b[i]][1]);
        sum += w[b[i]][0];
    }
    cout << ans << "\n";
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T = 1;
    while (T -- ) solve();
    return 0;
}