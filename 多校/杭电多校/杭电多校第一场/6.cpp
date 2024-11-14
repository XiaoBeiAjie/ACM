#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
typedef long long LL;

LL qmi(LL a, LL b) {
    LL res = 1;
    while (b) {
        if (b & 1) res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}

void solve() {
    int n; cin >> n;
    vector<int> v(n + 1);
    for (int i = 1; i <= n; i ++ ) 
        cin >> v[i];
    vector<int> f(n + 1), g(n + 1);
    vector<vector<int>> mp(n + 1);
    for (int i = 1; i <= n; i ++ ) {
        f[i] = 2 * f[i - 1] + 1;
        if (!mp[v[i]].empty()) 
            f[i] -= f[*mp[v[i]].rbegin() - 1] + 1;   
        g[i] = f[i - 1] + 1;
        for (auto j : mp[v[i]])
               g[i] -= g[j];
        mp[v[i]].push_back(i);
    }
    vector<int> cnt(n + 1);
    for (int i = n; i; i -- ) {
        for (auto j : mp[v[i]])
            cnt[j] ++;
        mp[v[i]].pop_back();
    }
    LL ans = 0;
    for (int i = 1; i <= n; i ++ ) 
        cout << f[i] << " ";
    cout << endl;
    for (int i = 1; i <= n; i ++ ) 
        cout << g[i] << " ";
    cout << endl;
    for (int i = 1; i <= n; i ++ ) 
        cout << cnt[i] << " ";
    cout << endl;
    for (int i = 1; i <= n; i ++ ) 
        ans = ans + qmi(cnt[i], 3) * g[i];
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