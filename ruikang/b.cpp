#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
typedef long long LL;

void solve() {
    int n, m;
    cin >> n >> m;
    map<string, string> mp;
    for (int i = 1; i <= n; i ++ ) {
        string s;
        string c;
        cin >> s >> c;
        mp[s] = c;
    }
    while (m -- ) {
        string s;
        cin >> s;
        if (mp.find(s) != mp.end()) {
            cout << mp[s] << endl;
            continue;
        }
        int cnt = 0;
        string ans;
        for (auto [s1, c1] : mp) {
            for (auto [s2, c2] : mp) {
                string res = s1 + s2;
                //cerr << res << endl;
                if (res == s) {
                    ans = c1 + c2;
                    cnt ++;
                }
                if (cnt > 1) break;
            }
            if (cnt > 1) break;
        }  
        if (cnt == 1) cout << ans << endl;
        else cout << "D" << endl;
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T = 1;
    while (T -- ) solve();
    system("pause");
    return 0;
}