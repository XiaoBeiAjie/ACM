#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    string s; cin >> s;
    s = " " + s;
    int idx = 1;
    while (s[idx] != '1') idx ++;
    for (int i = 1; i < idx; i ++ ) 
        if (s[i] == '3') return cout << s[i] << 1 << "\n", void();
    for (int i = idx + 1; i <= 10; i ++ ) 
        if (s[i] == '3') return cout << 1 << s[i] << "\n", void();
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T; cin >> T;
    while (T -- ) solve();
    return 0;
}