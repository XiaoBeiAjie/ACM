#include <bits/stdc++.h>
using i64 = long long;

void solve() {
    int n, m; std::cin >> n >> m;
    std::vector g(n + 1, std::vector<int> (m + 1));
    for (int i = 1; i <= n; i ++ ) 
        for (int j = 1; j <= m; j ++ ) 
            std::cin >> g[i][j];
    constexpr int dx[] = {0, 0, 1}, dy[] = {1, -1, 0};
    std::function<bool(int)> check = [&] (int mid) {
        std::queue<std::array<int, 2>> q;
        q.push({1, 1});
        std::vector st(n + 1, std::vector<bool>(m + 1, false));
        st[1][1] = true;
        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            for (int i = 0; i < 3; i ++ ) {
                int nx = x + dx[i], ny = y + dy[i];
                if (nx < 1 || nx > n || ny < 1 || ny > m || g[nx][ny] > mid) continue;
                if (st[nx][ny]) continue;
                st[nx][ny] = true;
                q.push({nx, ny});
            }
        }
        //return (bool)st[n][m];
        return st[n][m];
    };
    int l = 0, r = 1000000000;
    while (l < r) {
        int mid = l + r >> 1;
        if (check(mid)) r = mid;
        else l = mid + 1;
    }
    std::cout << l << "\n";
}

signed main(void) {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);
    int T = 1;
    while (T -- ) solve();
    return 0;
}