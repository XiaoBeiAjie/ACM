#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

struct SegTree {
    int l, r, siz;
    array<i64, 4> sum;
};

void solve() {
    int n, m; cin >> n >> m;
    vector<int> a(n + 1), b(n + 1);
    i64 sum_b = 0;
    constexpr int base = 100000;
    vector<SegTree> tr(base << 3);
    function<void(int)> pushup = [&] (int root) {
        tr[root].siz = tr[root << 1].siz + tr[root << 1 | 1].siz;
        for (int i = 0; i < 4; i ++ ) 
            tr[root].sum[i] = tr[root << 1].sum[i];
        for (int i = 0; i < 4; i ++ ) 
            tr[root].sum[(tr[root << 1].siz + i) % 4] += tr[root << 1 | 1].sum[i];
    };
    function<void(int, int, int)> build = [&] (int root, int l, int r) {
        tr[root].l = l, tr[root].r = r, tr[root].siz = 0;
        for (int i = 0; i < 4; i ++ ) 
            tr[root].sum[i] = 0;
        if (l == r) return ;
        int mid = l + r >> 1;
        build(root << 1, l, mid); build(root << 1 | 1, mid + 1, r);
        pushup(root);
    };
    function<void(int, int, int)> update = [&] (int root, int pos, int c) {
        if (tr[root].l == pos && tr[root].r == pos) {
            if (c == 1) 
                tr[root].sum[tr[root].siz % 4] += pos;
            else 
                tr[root].sum[(tr[root].siz - 1) % 4] -= pos;
            tr[root].siz += c;
            return ;
        }
        if (tr[root << 1].r >= pos) update(root << 1, pos, c);
        if (tr[root << 1 | 1].l <= pos) update(root << 1 | 1, pos, c);
        pushup(root);
    };
    function<i64(int)> query = [&] (int root) {
        i64 res = tr[root << 1].sum[0] + tr[root << 1].sum[3];
        int cnt = tr[root << 1].siz;
        if (cnt & 1) return res + tr[root << 1 | 1].sum[1] + tr[root << 1 | 1].sum[3];
        return res + tr[root << 1 | 1].sum[0] + tr[root << 1 | 1].sum[2];
    };
    build(1, -base, base);
    for (int i = 1; i <= n; i ++ ) {
        cin >> a[i] >> b[i];
        update(1, a[i] - b[i], 1);
        sum_b += b[i];
    }
    cout << sum_b + query(1) << "\n";
    while (m -- ) {
        int x, a_, b_; cin >> x >> a_ >> b_;
        update(1, a[x] - b[x], -1);
        sum_b -= b[x];
        update(1, a_ - b_, 1);
        a[x] = a_, b[x] = b_;
        sum_b += b[x];
        cout << sum_b + query(1) << "\n";
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T = 1;
    while (T -- ) solve();
    return 0;
}