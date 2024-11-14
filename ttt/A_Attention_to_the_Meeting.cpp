#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve() {
    int n, k; cin >> n >> k;
    cout << (k - n + 1) / n << "\n";
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T = 1;
    while (T -- ) solve();
    return 0;
}