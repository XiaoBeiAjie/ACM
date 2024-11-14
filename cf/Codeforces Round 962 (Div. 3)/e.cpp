#include <bits/stdc++.h>
using namespace std;
const int N = 100010, mod = 1e9+7;
typedef long long ll;

void solve() {
    string s;
    cin >> s;
    int n = s.size();
    s = " " + s;
    ll ans = 0, cur = 0;
    map<int, ll> mp;
    mp[0] = 1;
    for (int i = 1; i <= n; i ++ ) {
        cur += (s[i] == '1') ? 1 : -1;
        if (mp.find(cur) != mp.end()) ans = (ans + mp[cur] * (n - i + 1) % mod) % mod;
        mp[cur] += i + 1;
    }
    cout << ans << "\n";
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T; cin >> T;
    while (T -- ) solve();
    system("pause");
    return 0;
}