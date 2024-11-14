#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve() {
    int n = 3;
    vector<int> w(n + 1);
    for (int i = 1; i <= n; i ++ ) 
        cin >> w[i];
    int m; cin >> m;
    vector<int> a(m + 1);
    for (int i = 1; i <= m; i ++ ) 
        cin >> a[i];
    vector<int> sg(101);
    for (int i = 1; i <= 100; i ++ ) {
        vector<int> cnt(101);
        for (int j = 1; j <= m; j ++ ) 
            if (i < a[j]) continue;
            else cnt[sg[i - a[j]]] ++;
        int t = 0;
        while (t <= 100 && cnt[t]) t ++;
        sg[i] = t;
    }
    if (sg[w[1]] ^ sg[w[2]] ^ sg[w[3]]) cout << "Peter\n";
    else cout << "Vasya\n";
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T = 1;
    while (T -- ) solve();
    return 0;
}