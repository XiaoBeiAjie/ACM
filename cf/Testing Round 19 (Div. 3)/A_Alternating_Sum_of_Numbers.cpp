#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve() {
    int n; cin >> n;
    vector<int> w(n + 1);
    i64 sum = 0;
    for (int i = 1; i <= n; i ++ ) {
        cin >> w[i];
        if (i & 1) sum += w[i];
        else sum -= w[i];
    }
    cout << sum << "\n";
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T -- ) solve();
    return 0;
}