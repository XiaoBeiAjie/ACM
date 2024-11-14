#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve() {
    int n; cin >> n;
    vector<int> b(n + 1);
    queue<int> q;
    for (int i = 1; i <= n; i ++ ) {
        int x; cin >> x;
        q.push(x);
    }
    for (int i = 1; i <= n; i ++ ) 
        cin >> b[i];
    for (int i = 1; i < n; i ++ ) {
        while (b[i] != q.front()) {
            cout << "1";
            int x = q.front();
            q.pop(); q.push(x);
        }
         
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T -- ) solve();
    return 0;
}