#include <bits/stdc++.h>
using namespace std;
const int N = 40010, INF = 0x3f3f3f3f;
typedef long long LL;

int n;
int w[N];
int f[N], l[N];
LL pre[N], suf[N];
LL g[N];
map<int, vector<int>> e;

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i ++ ) 
        cin >> w[i], w[i] -= i;
    for (int i = 1; i <= n; i ++ ) f[i] = INF;
    int len = 1;
    f[1] = w[1], l[1] = 1;
    for (int i = 2; i <= n; i ++ ) {
        if (f[len] <= w[i]) 
            f[++ len] = w[i], l[i] = len;
        else {
            int pos = upper_bound(f + 1, f + 1 + len, w[i]) - f;
            f[pos] = w[i], l[i] = pos;
        }
    }
    e[0].push_back(0);
    w[0] = -INF, w[n + 1] = INF, l[n + 1] = len + 1;
    for (int i = 1; i <= n + 1; i ++ ) {
        g[i] = INF;
        for (auto j : e[l[i] - 1]) {
            if (w[j] > w[i]) continue;
            for (int k = j; k <= i; k ++ ) pre[k] = abs(w[k] - w[j]), suf[k] = abs(w[k] - w[i]);
            for (int k = j + 1; k <= i; k ++ ) pre[k] += pre[k - 1], suf[k] += suf[k - 1];
            for (int k = j; k <= i; k ++ ) 
                g[i] = min(g[i], g[j] + pre[k] - pre[j] + suf[i] - suf[k]);
        }
        e[l[i]].push_back(i);
    }
    cout << n - len << endl << g[n + 1] << endl;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T = 1;
    while (T -- ) solve();
    system("pause");
    return 0;
}