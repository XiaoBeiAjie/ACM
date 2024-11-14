#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve() {
    i64 n, k; cin >> n >> k;
    i64 sum = (k + k + n - 1) * n >> 1;
    int l = 1, r = n;
    function<bool(int)> check = [&] (int mid) {
        i64 res = (k + k + mid - 1) * mid / 2;
        return res <= sum / 2;
    };
    while (l < r) {
        int mid = l + r + 1 >> 1;
        if (check(mid)) l = mid;
        else r = mid - 1;
    }
    cout << min(sum - (k + k + l - 1) * l, (k + k + l) * (l + 1) - sum) << "\n";
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T -- ) solve();
    return 0;
}