#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;
const int N = 200010;
typedef long long LL;

int T;
int n, m;
int a[N], b[N], d[N];

void solve() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i ++ ) scanf("%d", &a[i]);
    map<int, int> ha, hh;
    for (int i = 1; i <= n; i ++ ) {
        scanf("%d", &b[i]);
        if (b[i] != a[i]) ha[b[i]] ++;
        else hh[b[i]] ++;
    }
    scanf("%d", &m);
    for (int j = 1; j <= m; j ++ ) scanf("%d", &d[j]);
    bool f = 1;
    if (ha.count(d[m])) ha[d[m]] --;
    else if (hh.count(d[m])) ;
    else f = 0;
    if (!f) return puts("NO"), void();
    for (int i = m - 1; i; i -- ) 
        if (ha.count(d[i]) && ha[d[i]] > 0) ha[d[i]] --;
    for (auto [x, y] : ha) 
        if (y > 0) {
            f = 0;
            break;
        }
    puts(f ? "YES" : "NO");
}
 
int main(void) {
    scanf("%d", &T);
    while (T -- ) solve();
    system("pause");
    return 0;
}