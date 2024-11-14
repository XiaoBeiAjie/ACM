#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    int n; cin >> n;
    vector<int> sg(n + 1);
    for (int i = 1; i <= n; i ++ ) 
        cin >> sg[i], sg[i] ^= sg[i - 1];
    cout << (sg[n] ? "Yes\n" : "No\n");
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T; cin >> T;
    while (T -- ) solve();
    return 0;
}