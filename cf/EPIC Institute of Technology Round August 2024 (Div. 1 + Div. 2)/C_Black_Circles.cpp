#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
typedef long long ll;

void solve() {
    int n; cin >> n;
    vector<array<long double, 2>> w(n + 1);
    for (int i = 1; i <= n; i ++ ) 
        cin >> w[i][0] >> w[i][1];
    long double sx, sy, ex, ey;
    cin >> sx >> sy >> ex >> ey;
    long double t = sqrtl((sx - ex) * (sx - ex) + (sy - ey) * (sy - ey));
    for (int i = 1; i <= n; i ++ ) {
        long double tt = sqrtl((w[i][0] - ex) * (w[i][0] - ex) + (w[i][1] - ey) * (w[i][1] - ey));
        if (tt <= t) return cout << "No\n", void();
    }
    cout << "Yes\n";
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T; cin >> T;
    while (T -- ) solve();
    system("pause");
    return 0;
}