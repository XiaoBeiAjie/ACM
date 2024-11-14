#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

struct SegTree {
    int l, r;
    i64 val, maxx;
};

void solve() {
    int n, m; cin >> n >> m;
    vector<int> w(n + 1);
    int maxx = 0;
    for (int i = 1; i <= n; i ++ ) 
        cin >> w[i], maxx = max(maxx, w[i]);
    vector<int> primes;
    vector<int> d(maxx + 1), num(maxx + 1);
    vector<bool> st(maxx + 1);
    d[1] = 1;
    for (int i = 2; i <= maxx; i ++ ) {
        if (!st[i]) {
            primes.push_back(i);
            num[i] = 1, d[i] = 2;
        }
        for (int j = 0; primes[j] <= maxx / i; j ++ ) {
            st[i * primes[j]] = true;
            if (i % primes[j] == 0) {
                num[i * primes[j]] = num[i] + 1;
                d[i * primes[j]] = d[i] / num[i * primes[j]] * (num[i * primes[j]] + 1);
                break;
            }
            num[i * primes[j]] = 1;
            d[i * primes[j]] = d[i] * 2;
        }
    }
    vector<SegTree> tr(n << 2);
    function<void(int)> pushup = [&] (int root) {
        tr[root].val = tr[root << 1].val + tr[root << 1 | 1].val;
        tr[root].maxx = max(tr[root << 1].maxx, tr[root << 1 | 1].maxx);
    };
    function<void(int, int, int)> build = [&] (int root, int l, int r) {
        tr[root].l = l, tr[root].r = r;
        if (l == r) {
            tr[root].val = w[l];
            tr[root].maxx = w[l];
            return ;
        }
        int mid = l + r >> 1;
        build(root << 1, l, mid); build(root << 1 | 1, mid + 1, r);
        pushup(root);
    };
    function<void(int, int, int)> update = [&] (int root, int l, int r) {
        if (tr[root].maxx <= 2) return ;
        if (tr[root].r < l || r < tr[root].l) return ;
        if (l <= tr[root].l && tr[root].r <= r && tr[root].l == tr[root].r) {
            tr[root].val = d[tr[root].val];
            tr[root].maxx = tr[root].val;
            return ;    
        }
        if (tr[root << 1].r >= l) update(root << 1, l, r);
        if (tr[root << 1 | 1].l <= r) update(root << 1 | 1, l, r);
        pushup(root);  
    };
    function<i64(int, int, int)> query = [&] (int root, int l, int r) {
        if (tr[root].r < l || r < tr[root].l) return 0ll;
        if (l <= tr[root].l && tr[root].r <= r) return tr[root].val;
        i64 res = 0;
        if (tr[root << 1].r >= l) res += query(root << 1, l, r);
        if (tr[root << 1 | 1].l <= r) res += query(root << 1 | 1, l, r);
        return res;
    };
    build(1, 1, n);
    while (m -- ) {
        int op, l, r;
        cin >> op >> l >> r;
        if (op == 1) 
            update(1, l, r);
        else 
            cout << query(1, l, r) << "\n";
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T = 1;
    while (T -- ) solve();
    return 0;
}