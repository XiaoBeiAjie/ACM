#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
typedef long long LL;

void solve() {
    int x, y, k;
    cin >> x >> y >> k;
    
    while (k) {
        int res = y - x % y;
        if (k >= res) {
            k -= res;
            x += res;
            while (x % y == 0) x /= y;
        } 
        else {
            x += k;
            k = 0;
        }
        if (x < y) break;
    }
    if (k == 0) return cout << x << endl, void();
    k %= y - 1;
    if (x + k >= y) k -= y - x, x = 1;
    x += k;
    cout << x << endl;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T; cin >> T;
    while (T -- ) solve();
    system("pause");
    return 0;
}