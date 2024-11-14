#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
typedef long long ll;

void solve() {
    int n; cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i ++ ) 
        cin >> a[i];
    for (int i = 0; i < n; i ++ ) 
        cin >> b[i];
    bool f = false;
    if (a == b) f = true;
    reverse(b.begin(), b.end());
    if (a == b) f = true;
    cout << (f ? "Bob\n" : "Alice\n");
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T; cin >> T;
    while (T -- ) solve();
    return 0;
}