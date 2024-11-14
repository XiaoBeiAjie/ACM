#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
typedef long long ll;

void solve() {
    ll n, x;
    cin >> n >> x;
    ll cnt = 0, res = 0, idx = 0;
    for (ll a = 1; 3 * a * a <= n; a ++ )  {
        for (ll b = a; 2 * a * b + b * b <= n; b ++ ) {
            if (a + 2 * b > x) break;
            ll c = min(x - a - b, (n - a * b) / (a + b)); 
            //cout << a << " " << b << " " << c << "\n";
            cnt += c - b + 1;
            if (a == b) res ++, idx += c - b;
            else idx ++;
        }   
    }
          
    cout << 6 * cnt - 3 * idx - 5 * res << "\n";
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T; cin >> T;
    while (T -- ) solve();
    system("pause");
    return 0;
}