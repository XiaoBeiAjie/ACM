#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    int n; cin >> n;
    vector<int> a(n + 2);
    for (int i = 1; i <= n; i ++ ) 
        cin >> a[i];
    vector<int> l(n + 2), r(n + 2);
    a[n + 1] = 0x3f3f3f3f;
    for (int i = 1; i <= n; i ++ ) 
        l[i] = l[i - 1] + (a[i - 1] <= a[i]);
    l[n + 1] = l[n];
    for (int i = n; i; i -- ) 
        r[i] = r[i + 1] + (a[i] >= a[i + 1]);
    r[0] = r[1];
    int ans = 0x3f3f3f3f;
    // for (int i = 0; i <= n + 1; i ++ ) 
    //     cerr << l[i] << " \n"[i == n + 1];
    // for (int i = 0; i <= n + 1; i ++ ) 
    //     cerr << r[i] << " \n"[i == n + 1];
    for (int i = 1; i <= n + 1; i ++ ) 
        ans = min(ans, r[i] + l[i - 1]);
    cout << ans << "\n";
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T; cin >> T;
    while (T -- ) solve();
    return 0;
}