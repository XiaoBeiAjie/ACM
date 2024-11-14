#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve() {
    string s; cin >> s;
    int n = s.size();
    s = " " + s;
    //if (s[1] != s[n]) return cout << "No\n", void();
    vector<int> ne(n + 1);
    for (int i = 2, j = 0; i <= n; i ++ ) {
        while (j && s[i] != s[j + 1]) j = ne[j];
        if (s[i] == s[j + 1]) j ++;
        ne[i] = j;
    }
    if (ne[n] * 2 <= n) return cout << "No\n", void();
    else 
        cout << "Yes\n" << s.substr(1, ne[n]) << "\n";
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T = 1;
    while (T -- ) solve();
    return 0;
}