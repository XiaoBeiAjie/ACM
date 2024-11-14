#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    int n; cin >> n;
    ll suma = 0, sumb = 0;
    vector<ll> a(n + 1), b(n + 1);
    for (int i = 1; i <= n; i ++ ) 
        cin >> a[i], suma += a[i];
    for (int i = 1; i <= n; i ++ ) 
        cin >> b[i], sumb += b[i];
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    cout << min(suma + n * b[1], sumb + n * a[1]) << "\n";
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T; cin >> T;
    while (T -- ) solve();
    return 0;
}