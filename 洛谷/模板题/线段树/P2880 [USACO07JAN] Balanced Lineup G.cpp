#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
typedef long long ll;

struct SegTree {
    int l, r;
    int val;
};


void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> w(n + 1);
    for (int i = 1; i <= n; i ++ ) 
        cin >> w[i];
    vector<SegTree> tr1(n << 2), tr2(n << 2);
    constexpr int inf = 0x3f3f3f3f;
    function<void(int)> pushup = [&] (int root) {
        tr1[root].val = max(tr1[root << 1].val, tr1[root << 1 | 1].val);
        tr2[root].val = min(tr2[root << 1].val, tr2[root << 1 | 1].val);
    };
    function<void(int, int, int)> build = [&] (int root, int l, int r) {
        tr1[root].l = l, tr1[root].r = r;
        tr2[root].l = l, tr2[root].r = r;
        if (l == r) {
            tr1[root].val = w[l];
            tr2[root].val = w[l];
            return ;
        }
        int mid = l + r >> 1;
        build(root << 1, l, mid), build(root << 1 | 1, mid + 1, r);
        pushup(root);
    };
    function<int(int, int, int)> query1 = [&] (int root, int l, int r) {
        if (l <= tr1[root].l && tr1[root].r <= r) {
            return tr1[root].val;
        }
        int res = 0;
        if (tr1[root << 1].r >= l) res = max(res, query1(root << 1, l, r));
        if (tr1[root << 1 | 1].l <= r) res = max(res, query1(root << 1 | 1, l, r));
        return res;
    };
    function<int(int, int, int)> query2 = [&] (int root, int l, int r) {
        if (l <= tr2[root].l && tr2[root].r <= r) {
            return tr2[root].val;
        }
        int res = inf;
        if (tr2[root << 1].r >= l) res = min(res, query2(root << 1, l, r));
        if (tr2[root << 1 | 1].l <= r) res = min(res, query2(root << 1 | 1, l, r));
        return res;
    };
    build(1, 1, n);
    while (m -- ) {
        int l, r;
        cin >> l >> r;
        cout << query1(1, l, r) - query2(1, l, r) << "\n";
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