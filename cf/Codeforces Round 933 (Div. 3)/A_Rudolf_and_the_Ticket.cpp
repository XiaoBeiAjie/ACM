#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(n + 1), b(m + 1);
    for (int i = 1; i <= n; i ++ ) 
        cin >> a[i];
    for (int j = 1; j <= m; j ++ ) 
        cin >> b[j];
    int cnt = 0;
    for (int i = 1; i <= n; i ++ ) 
        for (int j = 1; j <= m; j ++ ) 
            if (a[i] + b[j] <= k) cnt ++;
    cout << cnt << "\n";
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T; cin >> T;
    while (T -- ) solve();
    return 0;
}