#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve() {
    int n, k; cin >> n >> k;
    string s; cin >> s;
    if (n < 7) return cout << "0\n", void();
    int ans = 0;
    for (int i = 0; i <= min(k, 7); i ++ ) {
        int cnt = 0;
        for (int j = 0; j < n - 6; j ++ ) {
            if (s[(i + j) % n] != 'n') continue;
            if (s[(i + j) % n] == 'n' && s[(i + 1 + j) % n] == 'a' && s[(i + j + 2) % n] == 'n'
             && s[(i + j + 3) % n] == 'j' && s[(i + j + 4) % n] == 'i' && s[(i + j + 5) % n] == 'n'
             && s[(i + j + 6) % n] == 'g' ) cnt ++;
        }
        ans = max(cnt, ans);
    }
    cout << ans << "\n";
}

int main (void) {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T = 1; cin >> T;
    while (T -- ) solve();
    return 0;
}