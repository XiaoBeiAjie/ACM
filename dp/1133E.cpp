#include <bits/stdc++.h>
using namespace std;
const int N = 5010;
typedef long long LL;

int f[N][N][2];

void solve() {
    int n, m; cin >> n >> m;
    vector<int> w(n + 1);
    for (int i = 1; i <= n; i ++ ) 
        cin >> w[i];
    sort(w.begin() + 1, w.end());
    vector<int> cnt(n + 1);
    map<int, int> mp;
    int idx = 0, last = 0;
    for (int i = 1; i <= n; i ++ ) 
        if (w[i] == last) cnt[idx] ++;
        else cnt[++ idx] ++, mp[idx] = w[i], last = w[i];
    mp[0] = 0;
    int ans = 0;
    for (int i = 1; i <= n; i ++ ) 
        cnt[i] += cnt[i - 1];
    for (int i = 1; i <= idx; i ++ ) 
        for (int j = 1; j <= m; j ++ ) {
            f[i][j][0] = max(f[i - 1][j][1] , f[i - 1][j][0]);
            f[i][j][1] = max(f[i - 1][j - 1][1] , f[i - 1][j - 1][0]) + cnt[i] - cnt[i - 1];
            for (int k = 1; k <= 5 && i - k > 0; k ++ ) 
                if (mp[i - k] + 5 >= mp[i]) f[i][j][0] = max(f[i - k][j][1] + cnt[i] - cnt[i - k], f[i][j][0]);
                else break;
        }  
    for (int j = 1; j <= m; j ++ ) 
        ans = max({ans, f[idx][j][0], f[idx][j][1]});
    cout << ans << endl;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T = 1;
    while (T -- ) solve();
    system("pause");
    return 0;
}