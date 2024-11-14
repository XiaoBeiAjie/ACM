#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve() {
    int m; cin >> m;
    constexpr int mod = 998244353;
    function<i64(i64, i64)> qmi = [&] (i64 a, i64 b) {
        i64 res = 1;
        while (b) {
            if (b & 1) res = res * a % mod;
            a = a * a % mod;
            b >>= 1;
        }
        return res;
    };
    cout << qmi(2, m - 1) << "\n";
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T = 1;
    while (T -- ) solve();
    return 0;
}