#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve() {
    int n, q; cin >> n >> q;
    int idx = 0;
    constexpr int len = 1000000;
    vector tr(len + 1, vector<int>(26));
    vector cnt(len + 1, vector<int>(26));
    vector d(26, vector<i64>(26));
    i64 res = 0;
    function<void(string&, int)> insert = [&] (string& s, int n) {
        int p = 0;
        s = " " + s;
        for (int i = 1; i <= n; i ++ ) {
            int t = s[i] - 'a';
            if (!tr[p][t]) tr[p][t] = ++ idx;
            for (int j = 0; j < 26; j ++ ) {
                if (j == t) continue;
                else if (tr[p][j]) d[t][j] += cnt[p][j];
            }
            cnt[p][t] ++;
            p = tr[p][t]; 
        }
        for (int j = 0; j < 26; j ++ ) 
            if (cnt[p][j]) 
                res += cnt[p][j];
    };
    for (int i = 1; i <= n; i ++ ) {
        string s; cin >> s;
        insert(s, s.size());
    }
    while (q -- ) {
        string s; cin >> s;
        s = " " + s;
        vector<int> mp(26);
        for (int i = 1; i <= 26; i ++ ) 
            mp[s[i] - 'a'] = i;
        i64 ans = 0;
        for (int i = 0; i < 26; i ++ ) 
            for (int j = 0; j < 26; j ++ ) 
                if (mp[i] < mp[j]) 
                    ans += d[i][j];
        cout << ans + res << "\n";
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T = 1;
    while (T -- ) solve();
    return 0;
}