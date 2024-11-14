#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

struct SegTree {
    int l, r;
    i64 cnt, sum;
};

void solve() {
    int n, k, m;
    cin >> n >> k >> m;
    vector w(n + 2, vector<array<int, 2>>());
    int len = 0;
    for (int i = 1; i <= m; i ++ ) {
        int l, r, c, p;
        cin >> l >> r >> c >> p;
        w[l].push_back({c, p});
        w[r + 1].push_back({-c, p});
        len = max(len, p);
    }
    vector<SegTree> tr(len << 2);
    function<void(int)> pushup = [&] (int root) {
        tr[root].sum = tr[root << 1].sum + tr[root << 1 | 1].sum;
        tr[root].cnt = tr[root << 1].cnt + tr[root << 1 | 1].cnt;
    };
    function<void(int, int, int)> build = [&] (int root, int l, int r) {
        tr[root].l = l, tr[root].r = r;
        if (l == r) {
            tr[root].sum = 0, tr[root].cnt = 0;
            return ;
        }
        int mid = l + r >> 1;
        build(root << 1, l, mid); build (root << 1 | 1, mid + 1, r);
        pushup(root);
    };
    function<void(int, int, int)> update = [&] (int root, int p, int c) {
        if (p < tr[root].l || p > tr[root].r) return ;
        if (tr[root].l == p && tr[root].r == p) {
            tr[root].cnt += c;
            tr[root].sum += 1ll * c * p;
            return ;
        }
        if (tr[root << 1].r >= p) update(root << 1, p, c);
        if (tr[root << 1 | 1].l <= p) update(root << 1 | 1, p, c);
        pushup(root);
    };
    function<i64(int, int, int)> query_c = [&] (int root, int l, int r) {
        if (l > tr[root].r || r < tr[root].l) return 0ll;
        if (tr[root].l >= l && tr[root].r <= r) 
            return tr[root].cnt;
        i64 res = 0;
        if (tr[root << 1].r >= l) res += query_c(root << 1, l, r);
        if (tr[root << 1 | 1].l <= r) res += query_c(root << 1 | 1, l, r);
        return res;
    };
    function<i64(int, int, int)> query_s = [&] (int root, int l, int r) {
        if (l > tr[root].r || r < tr[root].l) return 0ll;
        if (tr[root].l >= l && tr[root].r <= r) 
            return tr[root].sum;
        i64 res = 0;
        if (tr[root << 1].r >= l) res += query_s(root << 1, l, r);
        if (tr[root << 1 | 1].l <= r) res += query_s(root << 1 | 1, l, r);
        return res;
    };
    function<i64()> check = [&] () {
        if (tr[1].cnt <= k) return tr[1].sum;
        int l = 1, r = len;
        while (l < r) {
            int mid = l + r >> 1;
            if (query_c(1, 1, mid) >= k) r = mid;
            else l = mid + 1;      
        }
        return query_s(1, 1, l - 1) + l * (k - query_c(1, 1, l - 1));
    };
    i64 ans = 0;
    build(1, 1, len);
    for (int i = 1; i <= n; i ++ ) {
        for (auto [c, p] : w[i]) 
            update(1, p, c);
        ans += check();
    }
    cout << ans << "\n";
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T = 1;
    while (T -- ) solve();
    return 0;
}