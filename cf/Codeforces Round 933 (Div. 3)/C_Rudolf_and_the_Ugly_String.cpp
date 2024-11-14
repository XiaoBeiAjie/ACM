#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    int n; cin >> n;
    string s; cin >> s;
    s = " " + s;
    int cnt = 0;
    for (int i = 1; i <= n - 2; i ++ ) 
        if (s[i] == 'm' && s[i + 1] == 'a' && s[i + 2] == 'p') cnt ++, i += 2;
        else if (s[i] == 'p' && s[i + 1] == 'i' && s[i + 2] == 'e') cnt ++, i += 2;
    cout << cnt << "\n";
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T; cin >> T;
    while (T -- ) solve();
    return 0;
}