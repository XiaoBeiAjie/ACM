#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    int n; cin >> n;
    string s; cin >> s;
    s = " " + s;
    vector cnt(n + 1, vector<int> (2));
    for (int i = 1; i <= n; i ++ ) {
        cnt[i][0] = cnt[i - 1][0] + (s[i] == '0');
        cnt[i][1] = cnt[i - 1][1] + (s[i] == '1');
    }
    int l = n >> 1, r = (n + 1) >> 1;
    while (1) {
        if (cnt[l][0] >= (l + 1) >> 1 && (cnt[n][1] - cnt[l][1]) >= (n - l + 1) >> 1) 
            return cout << l << "\n", void();
        l --;
        if (cnt[r][0] >= (r + 1) >> 1 && (cnt[n][1] - cnt[r][1]) >= (n - r + 1) >> 1) 
            return cout << r << "\n", void();
        r ++;
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T; cin >> T;
    while (T -- ) solve();
    return 0;
}