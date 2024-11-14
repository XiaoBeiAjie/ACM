#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    int x1, y1, x2, y2, x3, y3;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    int ans = 0;
    if (x2 > x1 && x3 > x1) ans += min(x2, x3) - x1;
    else if (x2 < x1 && x3 < x1) ans += x1 - max(x2, x3);
    if (y2 > y1 && y3 > y1) ans += min(y2, y3) - y1;
    else if (y2 < y1 && y3 < y1) ans += y1 - max(y2, y3);
    cout << ans + 1 << "\n";
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T; cin >> T;
    while (T -- ) solve();
    return 0;
}