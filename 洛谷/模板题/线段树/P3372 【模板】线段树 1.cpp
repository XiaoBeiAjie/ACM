#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
typedef long long ll;

struct Tree {
    int l, r;
    ll sum, tag;
};

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> w(n + 1);
    for (int i = 1; i <= n; i ++ ) 
        cin >> w[i];
    vector<Tree> tr(n << 2);
    function<void(int)> pushup = [&] (int root) {
        tr[root].sum = tr[root << 1].sum + tr[root << 1 | 1].sum;
    };
    function<void(int, int, int)> build = [&] (int root, int l, int r) {
        tr[root].l = l, tr[root].r = r;
        tr[root].sum = 0, tr[root].tag = 0;
        if (l == r) {
            tr[root].sum = w[l];
            return ;
        }
        int mid = l + r >> 1;
        build(root << 1, l, mid), build(root << 1 | 1, mid + 1, r);
        pushup(root);
    };
    function<void(int)> pushdown = [&] (int root) {
        if (!tr[root].tag) return ;
        tr[root << 1].sum += tr[root].tag * (tr[root << 1].r - tr[root << 1].l + 1);
        tr[root << 1 | 1].sum += tr[root].tag * (tr[root << 1 | 1].r - tr[root << 1 | 1].l + 1);
        tr[root << 1].tag += tr[root].tag; tr[root << 1 | 1].tag += tr[root].tag;
        tr[root].tag = 0;
    };
    function<void(int, int, int, int)> update = [&] (int root, int l, int r, ll c) {
        if (l <= tr[root].l && tr[root].r <= r) {
            tr[root].sum += c * (tr[root].r - tr[root].l + 1);
            tr[root].tag += c;
            return ;
        }
        pushdown(root);
        if (tr[root << 1].r >= l) update(root << 1, l, r, c);
        if (tr[root << 1 | 1].l <= r) update(root << 1 | 1, l, r, c);
        pushup(root);
    };
    function<ll(int, int, int)> query = [&] (int root, int l, int r) {
        if (l <= tr[root].l && tr[root].r <= r) 
            return tr[root].sum;
        pushdown(root);
        ll res = 0;
        if (tr[root << 1].r >= l) res += query(root << 1, l, r);
        if (tr[root << 1 | 1].l <= r) res += query(root << 1 | 1, l, r);
        return res;
    };
    build(1, 1, n);
    while (m -- ) {
        int op; cin >> op;
        if (op == 1) {
            int l, r; ll c;
            cin >> l >> r >> c;
            update(1, l, r, c);
        }
        else {
            int l, r;
            cin >> l >> r;
            cout << query(1, l, r) << "\n";
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