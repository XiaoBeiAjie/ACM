#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    string a, b;
    cin >> a >> b;
    int n = a.size() - 1;
    for (int i = 0; i < n; i ++ ) 
        if (a[i] == '0' && a[i + 1] == '1' && b[i] == '0' && b[i + 1] == '1') 
            return cout << "Yes\n", void();
    cout << "No\n";
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T; cin >> T;
    while (T -- ) solve();
    return 0;
}