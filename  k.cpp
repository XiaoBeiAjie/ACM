#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

bool mem1;

void solve() {
    int n; cin >> n;
    vector<int> ans(n + 1);
    constexpr int base = 5e5;
    vector<bitset<base + 1>> bs(30);
    vector tag(base + 1, vector<int> ()); 
    struct SegTree {
        int l, r;
        vector<int> val;
    };
    vector<SegTree> tr(n << 2);
    function<void(int, int, int, int)> update = [&] (int root, int l, int r, int v) {
        if (l <= tr[root].l && tr[root].r <= r) 
            return tr[root].val.push_back(v);
        if (tr[root << 1].r >= l) update(root << 1, l, r, v);
        if (tr[root << 1 | 1].l <= r) update(root << 1 | 1, l, r, v);
    };
    function<void(int, int, int)> build = [&] (int root, int l, int r) {
        tr[root].l = l, tr[root].r = r;
        if (l == r) return ;
        int mid = l + r >> 1;
        build(root << 1, l, mid); build(root << 1 | 1, mid + 1, r);
    };
    build(1, 1, n);
    for (int i = 1; i <= n; i ++ ) {
        int op, x; cin >> op >> x;
        if (op == 1) 
            tag[x].push_back(i);
        else {
            int l = tag[x].back(), r = i - 1;
            update(1, l, r, x);
            tag[x].pop_back();
        }
    }
    for (int i = 1; i <= base; i ++ ) 
        for (auto l : tag[i]) 
            update(1, l, n, i);
    function<void(int, int)> dfs = [&] (int root, int d) {
        for (auto v : tr[root].val) 
            bs[d] = (bs[d] << v) | bs[d];
        if (tr[root].l == tr[root].r) return ans[tr[root].l] = bs[d].count() - 1, void();
        bs[d + 1] = bs[d];
        dfs(root << 1, d + 1);
        bs[d + 1] = bs[d];
        dfs(root << 1 | 1, d + 1);
    };
    bs[0][0] = 1;
    dfs(1, 0);
    for (int i = 1; i <= n; i ++ ) 
        cout << ans[i] << "\n";
}

bool mem2;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #ifdef LOCAL
    cerr << fixed << setprecision(2) << "Memory : " << abs(&mem1 - &mem2) / 1024. / 1024. << "MB\n";
    #endif
    int T = 1;
    while (T -- ) solve();
    #ifdef LOCAL
    cerr << "Time : " << clock() * 1000 / CLOCKS_PER_SEC << "MS\n";
    #endif
    return 0;
}