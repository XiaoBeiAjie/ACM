#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    int n; cin >> n;
    vector<ll> w(n + 1);
    for (int i = 1; i <= n; i ++ ) 
        cin >> w[i], w[i] += w[i - 1];
    string s; cin >> s;
    s = " " + s;
    int l = 1, r = n;
    ll sum = 0;
    while (l < r) {
        while (l < r && s[l] == 'R') l ++;
        while (l < r && s[r] == 'L') r --; 
        if (s[l] == 'L' && s[r] == 'R') 
            sum += w[r] - w[l - 1], l ++, r --;
    }
    cout << sum << "\n";
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T; cin >> T;
    while (T -- ) solve();
    return 0;
}