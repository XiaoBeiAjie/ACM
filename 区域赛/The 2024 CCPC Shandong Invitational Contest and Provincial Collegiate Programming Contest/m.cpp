#include <bits/stdc++.h>
#define x first
#define y second
using i64 = long long;
const int N = 1010;
typedef long long LL;

struct Point {
    i64 x;
    i64 y;
    Point(i64 x = 0, i64 y = 0) : x(x), y(y) {}
};

bool operator==(const Point &a, const Point &b) {
    return a.x == b.x && a.y == b.y;
}

Point operator+(const Point &a, const Point &b) {
    return Point(a.x + b.x, a.y + b.y);
}

Point operator-(const Point &a, const Point &b) {
    return Point(a.x - b.x, a.y - b.y);
}

i64 dot(const Point &a, const Point &b) {
    return a.x * b.x + a.y * b.y;
}

i64 cross(const Point &a, const Point &b) {
    return a.x * b.y - a.y * b.x;
}

int T, n;
int w[N];
LL f[N][N];

void solve() {
    scanf("%d", &n);
    for (int i = 1; i <= 2 * n; i ++ ) 
        for (int j = 1; j <= 2 * n; j ++ ) 
            f[i][j] = -4e18 + 500;
    for (int i = 1; i <= 2 * n; i ++ ) 
        f[i][i] = 0;
    std::map<int, std::vector<int>> ha;
    for (int i = 1; i <= n; i ++ ) {
        scanf("%d", &w[i]);
        w[i + n] = w[i];
        ha[w[i]].push_back(i);
        ha[w[i]].push_back(i + n);
    }
    std::map<std::pair<int, int>, int> lb, rb;
    for (auto &[x, y] : ha) 
        sort(y.begin(), y.end());  
    for (int i = 1; i <= 2 * n; i ++ ) 
        for (int j = 1; j <= n; j ++ ) { 
            std::vector<int>::iterator it = upper_bound(ha[w[j]].begin(), ha[w[j]].end(), i);
            if (it != ha[w[j]].end()) lb[{i, w[j]}] = *it;
            it = lower_bound(ha[w[j]].begin(), ha[w[j]].end(), i);
            if (it -- != ha[w[j]].begin()) rb[{i, w[j]}] = *it;
        } 
    std::vector<Point> v(2 * n + 10);
    for (int i = 1; i <= n; i ++ ) {
        int x, y;
        scanf("%d%d", &x, &y);
        v[i] = v[i + n] = {x, y};
    }
    LL ans = 0;
    for (int len = 2; len <= n; len ++ ) {
        for (int l = 1; l + len - 1 <= 2 * n; l ++ ) {
            int r = l + len - 1;
            if (w[l] != w[r]) continue;
            f[l][r] = std::max(0LL, f[l][r]);
            for (int ll = l + 1; ll < r; ll ++ ) {
                int rr = rb[{r, w[ll]}];
                f[l][r] = std::max(f[l][r], f[ll][rr] + abs(cross(v[l] - v[ll], v[rr] - v[ll])) + abs(cross(v[l] - v[rr], v[r] - v[rr]))); 
            }
            for (int rr = r - 1; rr > l; rr -- ) {
                int ll = lb[{l, w[rr]}];
                f[l][r] = std::max(f[l][r], f[ll][rr] + abs(cross(v[l] - v[ll], v[rr] - v[ll])) + abs(cross(v[l] - v[rr], v[r] - v[rr])));
            }
            ans = std::max(ans, f[l][r]);
        }
    }
    printf("%lld\n", ans);
}

int main(void) {
    scanf("%d", &T);
    while (T -- ) solve();
    system("pause");
    return 0;
}