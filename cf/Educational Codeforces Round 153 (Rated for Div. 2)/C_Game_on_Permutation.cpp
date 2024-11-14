#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    int n; cin >> n;
    vector<int> w(n + 1);
    for (int i = 1; i <= n; i ++ ) 
        cin >> w[i];
    stack<int> stk;
    int cnt = 0;
    int minn = 0x3f3f3f3f, t = 0x3f3f3f3f;
    for (int i = 1; i <= n; i ++ ) {
        if (w[i] < minn) minn = w[i];
        else if (w[i] < t) cnt ++, t = w[i];
    }
    cout << cnt << "\n";
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T; cin >> T;
    while (T -- ) solve();
    return 0;
}