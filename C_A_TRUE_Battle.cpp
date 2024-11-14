#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve() {
    int n; cin >> n;
    string s; cin >> s;
    s = " " + s;
    if (s[1] == '1' || s[n] == '1') return cout << "YES\n", void();
    for (int i = 1; i < n; i ++ ) 
        if (s[i] == '1' && s[i + 1] == '1') return cout << "YES\n", void();
    return cout << "NO\n", void();
}

int main (void) {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T -- ) solve();
    return 0;
}