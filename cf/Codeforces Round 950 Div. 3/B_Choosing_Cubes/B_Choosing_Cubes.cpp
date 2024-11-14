#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;
const int N = 100010;
typedef long long LL;

int T;
int n, f, k;
int w[N];

void solve() {
    scanf("%d%d%d", &n, &f, &k);
    for (int i = 1; i <= n; i ++ ) scanf("%d", &w[i]);
    int tt = w[f];
    sort(w + 1, w + 1 + n, greater<int>());
    bool f = 0;
    for (int i = 1; i <= k; i ++ ) 
        if (w[i] == tt) f = 1;
    if (!f) puts("NO");
    else if (k != n && w[k + 1] == tt) puts("MAYBE");
    else puts("YES");
}

int main(void) {
    scanf("%d", &T);
    while (T -- ) solve();
    system("pause");
    return 0;
}