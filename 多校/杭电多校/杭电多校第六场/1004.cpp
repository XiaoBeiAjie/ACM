#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
typedef long long ll;

void solve() {
    int n, m;
    cin >> n >> m;
    map<int, int> mp;
    vector<ll> b(n + 1), e(n + 1), s(m + 1), t(m + 1);
    for (int i = 1; i <= n; i ++ ) {
        cin >> b[i] >> e[i];
        mp[b[i] << 1 | 1] ++, mp[e[i] << 1 | 1] --;
    }
    for (int i = 1; i <= m; i ++ ) {
        cin >> s[i] >> t[i];
        mp[s[i] << 1 | 1] ++, mp[t[i] << 1 | 1] --;
    }
    int tmp = 0;
    for (auto [x, y] : mp) {
        tmp += y;
        if (tmp >= 2) {
            cout << "No\n";
            return ;
        }
    }
    ll i = 1, j = 1, res = 1e15, st = t[1];
    while (i <= n && j <= m) {
        while (j <= m && s[j] <= res) {
            res = t[j] + 2 * (t[j] - s[j]);
            j ++;
        }
        while (i <= n && e[i] <= res && b[i] >= st) i ++;
        if (i > n) {
            cout << "Yes\n";
            return ;
        }
        if (j > m) {
            break;
        }
        res = t[j] + 2 * (t[j] - s[j]);
        st = t[j];
        j ++;
        if (b[i] < st) {
            cout << "No\n";
            return ;
        }
        
    }
    if (i <= n) {
        cout << "No\n";
        return ;
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