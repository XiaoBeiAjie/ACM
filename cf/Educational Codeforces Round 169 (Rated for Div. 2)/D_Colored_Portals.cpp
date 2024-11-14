#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// BG、BR、BY、GR、GY 或 RY
void solve() {
    int n, q;
    cin >> n >> q;
    vector<set<int>> st(6);
    map<string, int> mp;
    vector<string> s(n + 1);
    mp["BG"] = 0, mp["BR"] = 1, mp["BY"] = 2, mp["GR"] = 3, mp["GY"] = 4, mp["RY"] = 5;
    mp["GB"] = 0, mp["RB"] = 1, mp["YB"] = 2, mp["RG"] = 3, mp["YG"] = 4, mp["YR"] = 5;
    for (int i = 1; i <= n; i ++ ) {
        cin >> s[i];
        st[mp[s[i]]].insert(i);
    }
    while (q -- ) {
        int x, y; cin >> x >> y;
        auto s1 = s[x], s2 = s[y];
        if (s1[0] == s2[0] || s1[0] == s2[1] || s1[1] == s2[0] || s1[1] == s2[1]) {
            cout << abs(y - x) << "\n";
            continue;
        }
        int ans = 0x3f3f3f3f;
        for (int i = 0; i <= 1; i ++ ) 
            for (int j = 0; j <= 1; j ++ ) {
                string t = "";
                t += s1[i]; t += s2[j];
                int idx = mp[t];
                auto it = st[idx].lower_bound(x);
                if (it != st[idx].end()) ans = min(ans, abs(x - *it) + abs(y - *it));
                if (it != st[idx].begin()) {
                    it = prev(it);
                    ans = min(ans, abs(x - *it) + abs(y - *it));
                }
                it = st[idx].lower_bound(y);
                if (it != st[idx].end()) ans = min(ans, abs(x - *it) + abs(y - *it));
                if (it != st[idx].begin()) {
                    it = prev(it);
                    ans = min(ans, abs(x - *it) + abs(y - *it));
                }
            }
        cout << (ans == 0x3f3f3f3f ? -1 : ans) << "\n";
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T; cin >> T;
    while (T -- ) solve();
    return 0;
}