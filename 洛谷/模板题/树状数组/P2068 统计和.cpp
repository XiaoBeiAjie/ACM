#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
typedef long long ll;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<ll> tr(n + 1);
    function<int(int)> lowbit = [&] (int x) {
        return x & -x;
    };
    function<void(int, int)> update = [&] (int x, int c) {
        for (int i = x; i <= n; i += lowbit(i))
            tr[i] += c;
    };
    function<ll(int)> query = [&] (int x) {
        ll res = 0;
        for (int i = x; i; i -= lowbit(i)) 
            res += tr[i];
        return res;
    };
    while (m -- ) {
        char op; cin >> op;
        if (op == 'x') {
            int x, c;
            cin >> x >> c;
            update(x, c);
        }
        else {
            int l, r;
            cin >> l >> r;
            cout << query(r) - query(l - 1) << "\n";
        }
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T = 1;
    while (T -- ) solve();
    system("pause");
    return 0;
}