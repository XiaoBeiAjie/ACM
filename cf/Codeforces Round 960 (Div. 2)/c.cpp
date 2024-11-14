#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
typedef long long ll;

void solve() {
    int n; cin >> n;
    ll sum = 0;
    vector<ll> a(n + 1), s(n + 1);
    vector<int> cnt(n + 1);
    int maxx = 0;
    for (int i = 1; i <= n; i ++ ) {
        cin >> a[i];
        s[i] = s[i - 1] + a[i];
        cnt[a[i]] ++;
        if (cnt[a[i]] > 1 && a[i] > maxx) 
            maxx = a[i];
        a[i] = maxx;
    }
    sum += s[n];
    for (int i = 0; i <= n; i ++ ) cnt[i] = 0;
    maxx = 0;
    for (int i = 1; i <= n; i ++ ) {
        s[i] = s[i - 1] + a[i];
        cnt[a[i]] ++;
        if (cnt[a[i]] > 1 && a[i] > maxx) 
            maxx = a[i];
        a[i] = maxx;
    }
    sum += s[n];
    for (int i = 1; i <= n; i ++ ) 
        sum += a[i] * (1ll * n - i + 1);
    cout << sum << endl;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T; cin >> T;
    while (T -- ) solve();
    system("pause");
    return 0;
}