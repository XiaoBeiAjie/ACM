#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
typedef long long ll;

struct SegTree {
    int l, r, val;
};

void solve() {
    int m, k;
    cin >> m >> k;
    int n = 100000;
    vector<SegTree> tr(n << 2);
    function<void(int)> pushup = [&] (int root) {
        tr[root].val = tr[root << 1].val + tr[root << 1 | 1].val;
    };
    function<void(int, int, int)> build = [&] (int root, int l, int r) {
        tr[root].l = l, tr[root].r = r;
        if (l == r) {
            tr[root].val = 0;
            return ;
        }
        int mid = l + r >> 1;
        build(root << 1, l, mid), build(root << 1 | 1, mid + 1, r);
        pushup(root);
    };
    function<void(int, int, int, int)> update = [&] (int root, int l, int r, int c) {
        if (l <= tr[root].l && tr[root].r <= r) {
            tr[root].val += c;
            return ;
        }
        if (tr[root << 1].r >= l) update(root << 1, l, r, c);
        if (tr[root << 1 | 1].l <= r) update(root << 1 | 1, l, r, c);
        pushup(root);
    };
    function<int(int, int, int)> query = [&] (int root, int l, int r) {
        if (l <= tr[root].l && tr[root].r <= r) 
            return tr[root].val;
        int res = 0;
        if (tr[root << 1].r >= l) res += query(root << 1, l, r);
        if (tr[root << 1 | 1].l <= r) res += query(root << 1 | 1, l, r);
        return res;
    };
    build(1, 1, n);
    while (m -- ) {
        int x, c;
        cin >> x >> c;
        update(1, x, x, c);
    }
    if (!k) return cout << "0", void();
    int ans = 0;
    for (int l = 1; l + k - 1 <= n; l ++ ) 
        ans = max(ans, query(1, l, l + k - 1));
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