#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
typedef long long ll;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> tr(n + 1);
    function<int(int)> lowbit = [&] (int x) {
        return x & -x;
    };
    function<void(int, int)> update = [&] (int x, int c) {
        for (int i = x; i <= n; i += lowbit(i))
            tr[i] += c;
    };
    function<int(int)> query = [&] (int x) {
        int res = 0;
        for (int i = x; i; i -= lowbit(i))
            res += tr[i];
        return res;
    };
    while (m -- ) {
        int op; cin >> op;
        if (!op) {
            int l, r;
            cin >> l >> r;
            update(l, 1), update(r + 1, -1);
        }
        else {
            int x; cin >> x;
            cout << query(x) << "\n";
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