#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve() {
    int n; cin >> n;
    int base_x = n - 1 >> 1, base_y = n - 1 >> 1;
    cout << n << "################\n";
    function<char(int)> fun = [&] (int pos) {
        int x = pos / n, y = pos % n;
        return (abs(x - base_x) + abs(y - base_y) <= base_y) ? '*' : ' ';
    };
    for (int i = 0; i < n * n; i ++ ) {
        cout << fun(i);
        if (i % n == n - 1) cout << "\n";
        if ((n & 1 ^ 1) && (i == (n * n >> 1) - 1))  base_x ++;
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T -- ) solve();
    return 0;
}