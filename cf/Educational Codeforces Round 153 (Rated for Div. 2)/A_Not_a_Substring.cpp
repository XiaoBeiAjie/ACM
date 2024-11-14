#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    string s; cin >> s;
    if (s.size() == 2 && s[0] == '(' && s[1] == ')') return cout << "No\n", void();
    bool f1 = false, f2 = false;
    for (int i = 0; i < s.size() - 1; i ++ ) {
        if (s[i] == s[i + 1]) f1 = true;
        if (s[i] != s[i + 1]) f2 = true;
    }
    int n = s.size();
    cout << "Yes\n";
    if (f1) {
        for (int i = 1; i <= n; i ++ ) 
            cout << "()";
        cout << "\n";
        return ;
    }
    if (f2) {
        for (int i = 1; i <= n; i ++ ) 
            cout << "(";
        for (int i = 1; i <= n; i ++ ) 
            cout << ")";
        cout << "\n";
        return ;
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T; cin >> T;
    while (T -- ) solve();
    return 0;
}