#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve() {
    string s, t; cin >> s >> t;
    int n = s.size(); s = " " + s;
    int m = t.size(); t = " " + t;
    vector<int> a(n + 1), b(m + 1);
    vector<int> pos1, pos2;
    for (int i = 1; i <= n; i ++ ) 
        if (s[i] == '*') a[i] = -1, pos1.push_back(i);
        else a[i] = s[i] - '0';
    for (int i = 1; i <= m; i ++ ) 
        if (t[i] == '*') b[i] = -1, pos2.push_back(i);
        else b[i] = t[i] - '0';
    int cnt1 = pos1.size(), cnt2 = pos2.size();
    for (int mask1 = 0; mask1 < (1 << cnt1); mask1 ++ ) 
        for (int mask2 = 0; mask2 < (1 << cnt2); mask2 ++ ) {
            for (int i = 0; i < cnt1; i ++ ) 
                if ((mask1 >> i) & 1) a[pos1[i]] = 1;
                else a[pos1[i]] = 0;
            for (int i = 0; i < cnt2; i ++ ) 
                if ((mask2 >> i) & 1) b[pos2[i]] = 1;
                else b[pos2[i]] = 0;
            int res = 0;
            for (int i = 1; i <= m; i ++ ) {
                res *= 2;
                res += b[i];
            }
            //if (res == 0) continue;
            i64 ans = 0;
            for (int i = 1; i <= n; i ++ ) {
                ans *= 2;
                ans += a[i];
                while(ans >= res) ans -= res;
            }
            if (ans == 0) {
                for (int i = 1; i <= n; i ++ ) 
                    cout << a[i];
                cout << "\n";
                return void();
            }
        } 
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T = 1;
    while (T -- ) solve();
    return 0;
}