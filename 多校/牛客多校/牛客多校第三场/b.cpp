#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
typedef long long ll;

void solve() {
    ll n, d;
    cin >> n >> d;
    vector<ll> v(n + 1); 
    for (int i = 1; i <= n; i ++ ) 
        cin >> v[i];
    ll g = v[1];
    for (int i = 2; i <= n; i ++ ) 
        g = __gcd(v[i], g);
    d %= g;
    cout << min(g - d, d);

}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T = 1;
    while (T -- ) solve();
    system("pause");
    return 0;
}