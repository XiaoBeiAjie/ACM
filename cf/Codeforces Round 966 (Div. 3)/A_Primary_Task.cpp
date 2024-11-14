#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    string s; cin >> s;
    if (s.size() > 2 && s[0] == '1' && s[1] == '0' && s[2] != '0') {
        if (s.size() == 3 && s[2] == '1') cout << "No\n";
        else cout << "Yes\n";
    }
    else cout << "No\n";
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T; cin >> T;
    while (T -- ) solve();
    return 0;
}