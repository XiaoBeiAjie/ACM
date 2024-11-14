#include <bits/stdc++.h>
using namespace std;
const int N = 1000010;
typedef long long ll;

ll X[N << 1];

struct ScanLine{
    ll l, r, h;
    int mark; // 标记权值 1/-1
    bool operator < (const ScanLine &rhs) const {
        return h < rhs.h;
    }
} line[N << 1];

struct SegTree {
    int l, r, sum ; // sum 被完全覆盖次数
    ll len; // len 区间内被截长度
} tree[N << 2];

void build_tree(int rt, int l, int r) {
    tree[rt].l = l, tree[rt].r = r;
    tree[rt].len = 0, tree[rt].sum = 0;
    if (l == r) return ;
    int mid = l + r >> 1;
    build_tree(rt << 1, l, mid);
    build_tree(rt << 1 | 1, mid + 1, r);
}

void pushup(int rt) {
    int l = tree[rt].l, r = tree[rt].r;
    if (tree[rt].sum) // 未被覆盖过 更新长度
        tree[rt].len = X[r + 1] - X[l];
    else // 合并儿子信息
        tree[rt].len = tree[rt << 1].len + tree[rt << 1 | 1].len;
}

void update(int rt, int L, int R, int c) {
    int l = tree[rt].l, r = tree[rt].r;
    if (X[r + 1] <= L || R <= X[l]) return ;
    if (L <= X[l] && X[r + 1] <= R) {
        tree[rt].sum += c;
        pushup(rt);
        return ;
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
        X[2 * i - 1] = x_1, X[2 * i] = x_2;
        line[2 * i - 1] = (ScanLine) {x_1, x_2, y_1, 1};
        line[2 * i] = (ScanLine) {x_1, x_2, y_2, -1};
    }
    n <<= 1;
    sort(line + 1, line + n + 1);
    sort(X + 1, X + n + 1);
    int tot = unique(X + 1, X + n + 1) - X - 1;
    build_tree(1, 1, tot - 1);
    ll ans = 0;
    for (int i = 1; i < n; i ++ ) {
        update(1, line[i].l, line[i].r, line[i].mark);
        ans += tree[1].len * (line[i + 1].h - line[i].h);
    }
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