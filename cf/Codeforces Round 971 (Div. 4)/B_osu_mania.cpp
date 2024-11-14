#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve() {
    int n; cin >> n;
    vector<int> ans(n + 1);
    for (int i = 1; i <= n; i ++ ) {
        string s; cin >> s;
        for (int j = 0; j < 4; j ++ ) 
            if (s[j] == '#') 
                ans[i] = j + 1;
    }
    for (int i = n; i; i -- ) 
        cout << ans[i] << " \n"[i == 1];
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T -- ) solve();
    return 0;
}