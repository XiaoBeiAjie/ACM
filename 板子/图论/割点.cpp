#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
typedef long long ll;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> e(n + 1);
    for (int i = 1; i <= m; i ++ ) {
        int u, v;
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    int dfn = 0, cnt = 0;
    vector<int> num(n + 1), low(n + 1), iscut(n + 1);
    function<void(int, int)> dfs = [&](int u, int fa) {
        num[u] = low[u] = ++ dfn;
        int son = 0;
        for (auto v : e[u]) {
            if (!num[v]) {
                son ++;
                dfs(v, u);
                low[u] = min(low[u], low[v]);
                if (low[v] >= num[u] && u != fa) // 割点是 low[v] >= num[u], 割边 low[v] > num[u] 
                    cnt += !iscut[u], iscut[u] = true;
            }
            else if (num[v] < num[u] && v != fa)
                low[u] = min(low[u], num[v]); // 用 num[v] 去更新， 否则会出现走了重复的路
        }
        if (u == fa && son >= 2) 
            cnt += !iscut[u], iscut[u] = true;
    };
    for (int i = 1; i <= n; i ++ )
        if (!num[i]) 
            dfs(i, i);
    cout << cnt << "\n";
    for (int i = 1; i <= n; i ++ ) 
        if (iscut[i])
            cout << i << " ";
    cout << "\n";
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T = 1;
    while (T -- ) solve();
    system("pause");
    return 0;
}