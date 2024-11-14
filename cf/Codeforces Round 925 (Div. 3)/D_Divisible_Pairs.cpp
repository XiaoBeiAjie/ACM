#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
typedef long long ll;

void solve() {
    ll n, x, y; cin >> n >> x >> y;
    vector<int> w(n + 1);
    for (int i = 1; i <= n; i ++ ) 
        cin >> w[i];
    map<pair<int, int>, ll> mp;
    ll ans = 0;
    for (int i = 1; i <= n; i ++ ) {
        int a = w[i] % x, b = w[i] % y;
        if (mp.find({(x - a) % x, b}) != mp.end())
            ans += mp[{(x - a) % x, b}];
        mp[{a, b}] ++;
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