#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    int n; cin >> n;
    vector<int> w(n + 1);
    for (int i = 1; i <= n; i ++ ) 
        cin >> w[i];
    vector<bool> vis(n + 1);
    vis[w[1]] = true;
    bool f = false;
    for (int i = 2; i <= n; i ++ ) {
        bool f = false;
        if (w[i] != 1 && vis[w[i] - 1]) f = true;
        if (w[i] != n && vis[w[i] + 1]) f = true;
        if (!f) return cout << "No\n", void();
        vis[w[i]] = true;
    }
    cout << "Yes\n";

}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T; cin >> T;
    while (T -- ) solve();
    return 0;
}