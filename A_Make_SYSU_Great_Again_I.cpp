#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve() {
    int n, k; cin >> n >> k;
    set<array<int, 2>> s;
    for (int i = 1; i <= n; i ++ ) {
        cout << i << " " << i << "\n";
        s.insert({i, i});
        int j = i + 1;
        if (i != n) cout << i << " " << i + 1 << "\n", s.insert({i, i + 1});
        else cout << n << " " << 1 << "\n", s.insert({n, 1});
    } 
    int cnt = 2 * n;
    for (int i = 1; i <= n; i ++ ) 
        for (int j = 1; j <= n; j ++ ) {
            if (s.find({i, j}) == s.end()) 
                cout << i << " " << j << "\n", s.insert({i, j}), cnt ++;
            if (cnt == k) return ;
        }
}

int main (void) {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T = 1;
    while (T -- ) solve();
    return 0;
}