#include <bits/stdc++.h>
using namespace std;
const int N = 5010;
typedef long long ll;

int X[N << 1];

struct ScanLine {
    int l, r, h;
    int mark;
    bool operator < (const ScanLine &rhs) const {
        if (h == rhs.h) 
            return mark > rhs.mark;
        return h < rhs.h;
    }
} line[N << 1];

struct SegTree {
    int l, r, sum, len, cnt; // cnt 区间条数
    bool lc, rc;
} tree[N << 2];

void build_tree(int rt, int l, int r) {
    tree[rt].l = l, tree[rt].r = r;
    tree[rt].lc = tree[rt].rc = false;
    tree[rt].sum = tree[rt].len = 0;
    tree[rt].cnt = 0;
    if (r == l) return ;
    int mid = l + r >> 1;
    build_tree(rt << 1, l, mid);
    build_tree(rt << 1 | 1, mid + 1, r);
}

void pushup(int rt) {
    int l = tree[rt].l, r = tree[rt].r;
    if (tree[rt].sum) {
        tree[rt].len = X[r + 1] - X[l];
        tree[rt].lc = tree[rt].rc = true;
        tree[rt].cnt = 1;
    }
    else {
        tree[rt].len = tree[rt << 1].len + tree[rt << 1 | 1].len;
        tree[rt].lc = tree[rt << 1].lc, tree[rt].rc = tree[rt << 1 | 1].rc;
        tree[rt].cnt = tree[rt << 1].cnt + tree[rt << 1 | 1].cnt;
        if (tree[rt << 1].rc && tree[rt << 1 | 1].lc)
            tree[rt].cnt --;
    }
}

void update(int rt, int L, int R, int c) {
    int l = tree[rt].l, r = tree[rt].r;
    if (X[l] >= R || X[r + 1] <= L) return ;
    if (L <= X[l] && X[r + 1] <= R) {
        tree[rt].sum += c;
        pushup(rt);
        return;
    }
    update(rt << 1, L, R, c);
    update(rt << 1 | 1, L, R, c);
    pushup(rt);
}

void solve() {
    int n; cin >> n;
    for (int i = 1; i <= n; i ++ ) {
        int x_1, x_2, y_1, y_2;
        cin >> x_1 >> y_1 >> x_2 >> y_2;
        line[2 * i - 1] = (ScanLine) {x_1, x_2, y_1, 1};
        line[2 * i] = (ScanLine) {x_1, x_2, y_2, -1};
        X[2 * i - 1] = x_1, X[2 * i] = x_2;
    }
    n <<= 1;
    sort(line + 1, line + n + 1);
    sort(X + 1, X + n + 1);
    int tot = unique(X + 1, X + n + 1) - X - 1;
    build_tree(1, 1, tot - 1);
    int ans = 0, pre = 0;
    for (int i = 1; i < n; i ++ ) {
        update(1, line[i].l, line[i].r, line[i].mark);
        ans += abs(pre - tree[1].len);
        pre = tree[1].len;
        ans += 2 * tree[1].cnt * (line[i + 1].h - line[i].h);
    }
    ans += line[n].r - line[n].l;
    cout << ans << endl;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T = 1;
    while (T -- ) solve();
    system("pause");
    return 0;
}