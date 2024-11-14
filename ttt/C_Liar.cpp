#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve() {
    int n, s; cin >> n >> s;
    vector<int> w(n + 1);
    i64 sum = 0;
    for (int i = 1; i <= n; i ++ ) 
        cin >> w[i], sum += w[i];
    if (sum == s) return cout << n << "\n", void();
    else cout << n - 1 << "\n", void();
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T = 1;
    while (T -- ) solve();
    return 0;
}