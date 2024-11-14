#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve() {
    string s; cin >> s;
    int c1 = 0, c2 = 0;
    for (int i = 0; i < 5; i ++ ) 
        if (s[i] == 'T') c1 ++;
        else if (s[i] == 'D') c2 ++;
    if (c1 >= 3) cout << "T1\n";
    else cout << "DRX\n";
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T = 1;
    while (T -- ) solve();
    return 0;
}