#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    int n, m; cin >> n >> m;
    vector g(n, vector<int> (m));
    for (int i = 0; i < n; i ++ ) 
        for (int j = 0; j < m; j ++ ) 
            cin >> g[i][j];
    constexpr int inf = 0x3f3f3f3f;
    vector dist(n, vector<int> (m, inf));
    constexpr int dx[] = {2, 1}, dy[] = {0, 1};
    int ans = inf;
    function<void()> bfs = [&] () {
        queue<pair<int, int>> q;
        q.push({0, 0});
        dist[0][0] = 0;
        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            if (y == m - 1) {
                int t = (n - 1 + dist[x][y]) % n;
                ans = min(ans, dist[x][y] + min(abs(t - x), n - abs(t - x)));
                continue;
            }
            for (int i = 0; i < 2; i ++ ) {
                int nx = (x + dx[i]) % n, ny = y + dy[i];
                if (g[nx][ny] == 1 || (i == 0 && g[(x + 1) % n][ny] == 1)) continue;
                if (dist[nx][ny] > dist[x][y] + 1) 
                    q.push({nx, ny}), dist[nx][ny] = dist[x][y] + 1;
            }
        }
    };
    bfs();
    if (ans == inf) ans = -1;
    cout << ans << "\n";
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T; cin >> T;
    while (T -- ) solve();
    return 0;
}