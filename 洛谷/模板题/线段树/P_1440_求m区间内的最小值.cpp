#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
typedef long long ll;

struct SegTree {
    int l, r, val;
};

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> w(n + 1);
    for (int i = 1; i <= n; i ++ ) 
        cin >> w[i];
    vector<SegTree> tr(n << 2);
    function<void(int)> pushup = [&] (int root) {
        tr[root].val = min(tr[root << 1].val, tr[root << 1 | 1].val);
    };
    function<void(int, int, int)> build = [&] (int root, int l, int r) {
        tr[root].l = l, tr[root].r = r;
        if (l == r) {
            tr[root].val = w[l];
            return ;
        }
        int mid = l + r >> 1;
        build(root << 1, l, mid), build(root << 1 | 1, mid + 1, r);
        pushup(root);
    };
    function<int(int, int, int)> query = [&] (int root, int l, int r) {
        if (l <= tr[root].l && tr[root].r <= r) 
            return tr[root].val;
        int res = 0x3f3f3f3f;
        if (tr[root << 1].r >= l) res = min(res, query(root << 1, l, r));
        if (tr[root << 1 | 1].l <= r) res = min(res, query(root << 1 | 1, l, r));
        return res;
    };
    build(1, 1, n);
    for (int i = 1; i <= n; i ++ ) {
        int r = i - 1, l = max(1, i - m);
        if (r < l) cout << "0\n";
        else cout << query(1, l, r) << "\n";
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