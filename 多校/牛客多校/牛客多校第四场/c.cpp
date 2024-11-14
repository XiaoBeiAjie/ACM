#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
typedef long long ll;

void solve() {
    int n; cin >> n;
    vector<int> w(n + 1), ne(n + 1);
    for (int i = 1; i <= n ; i++ ) 
        cin >> w[i], ne[i] = w[i];
    vector<bool> vis(n + 1);
    vector<int> mp(5);
    int idx = 0, ans = 0;
    for (int i = 1; i <= n; i ++ ) 
        if (ne[i] != i && !vis[i]) {
            int cnt = 1;
            int st = i, be = i;
            vis[st] = 1;
            while (ne[be] != st) cnt ++, be = ne[be], vis[be] = 1;
            while (cnt > 4) cnt -= 3, ans ++;
            mp[cnt] ++;
        }
    ans += mp[4] + mp[3] + (mp[2] + 1) / 2;
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