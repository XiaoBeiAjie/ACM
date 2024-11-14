#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
typedef long long ll;

void solve() {
    int n; cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i ++ ) 
        cin >> a[i];
    vector<int> pre(n + 1), suf(n + 2);
    for (int i = 1; i <= n; i ++ ) 
        pre[i] = a[i] + n - i;
    for (int i = n; i; i -- ) 
        suf[i] = a[i] + i - 1;
    for (int i = 2; i <= n; i ++ ) 
        pre[i] = max(pre[i], pre[i - 1]);
    for (int i = n - 1; i; i --)
        suf[i] = max(suf[i], suf[i + 1]);
    int ans = 0x3f3f3f3f3f;
    for (int i = 1; i <= n; i ++ ) 
        ans = min(ans, max({a[i], pre[i - 1], suf[i + 1]}));
    cout << ans << "\n";
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T = 1;
    while (T -- ) solve();
    system("pause");
    return 0;
}