#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve() {
    int n; cin >> n;
    i64 sum = 0;
    for (int i = 1; i <= n; i ++ ) {
        i64 x, y; char c;
        cin >> x >> c;
        if (c == 'A') y = 10;
        else y = c - '0';
        x %= 5, y %= 5;
        sum = (sum + x * y % 5) % 5;
    }
    if (sum) cout << "No\n";
    else cout << "Yes\n";
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T -- ) solve();
    return 0;
}