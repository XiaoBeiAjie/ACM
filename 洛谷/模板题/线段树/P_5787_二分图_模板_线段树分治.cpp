#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct SegTree {
    int l, r;
    vector<int> val;
};

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> p(n << 1 | 1);
    for (int i = 1; i <= n << 1; i ++ )
        p[i] = i;
    function<int(int)> find = [&] (int x) {
        return p[x] == x ? x : find(p[x]);
    };
    vector e(m + 1, array<int, 2>());
    vector<SegTree> tr(k << 2);
    function<void(int, int, int)> build = [&] (int root, int l, int r) {
        tr[root].l = l, tr[root].r = r;
        if (l == r) return ;
        int mid = l + r >> 1;
        build(root << 1, l, mid); build(root << 1 | 1, mid + 1, r);
    };
    function<void(int, int, int, int)> update = [&] (int root, int l, int r, int c) {
        if (r < l) return ;
        if (l <= tr[root].l && tr[root].r <= r) 
            return tr[root].val.push_back(c);
        int mid = l + r >> 1;
        if (tr[root << 1].r >= l) update(root << 1, l, r, c);
        if (tr[root << 1 | 1].l <= r) update(root << 1 | 1, l, r, c);
    };
    build(1, 1, k);
    for (int i = 1; i <= m; i ++ ) {
        int l, r;
        cin >> e[i][0] >> e[i][1] >> l >> r;
        update(1, l + 1, r, i);
    }
    vector<int> h(n << 1 | 1, 1);
    vector<array<int, 3>> stk;
    function<void(int, int)> merge = [&] (int u, int v) {
        int fu = find(u), fv = find(v);
        if (h[fu] > h[fv]) swap(fu, fv);
        stk.push_back({fu, fv, h[fu] == h[fv]});
        p[fu] = fv;
        if (h[fu] == h[fv]) h[fv] ++;
    };
    function<void(int, int, int)> query = [&] (int root, int l, int r) {
        int cnt = stk.size();
        bool f = true;
        for (auto t : tr[root].val) {
            auto u = e[t][0], v = e[t][1];
            int fu = find(u), fv = find(v);
            if (fu == fv) {
                for (int i = l; i <= r; i ++ ) 
                    cout << "No\n";
                f = false;
                break;
            }
            merge(u, v + n); merge(v, u + n);
        }
        if (f) {
            if (l == r) cout << "Yes\n";
            else {
                int mid = l + r >> 1;
                query(root << 1, l, mid); query(root << 1 | 1, mid + 1, r);
            }
        } 
        while (stk.size() > cnt) {
            auto [u, v, f] = stk.back();
            stk.pop_back();
            h[v] -= f; p[u] = u;
        }
    };
    query(1, 1, k);
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T = 1;
    while (T -- ) solve();
    return 0;
}