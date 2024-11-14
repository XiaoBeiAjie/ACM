#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve() {
    int n, m; cin >> n >> m;
    vector<string> s(n + 1);
    for (int i = 1; i <= n; i ++ ) 
        cin >> s[i], s[i] = " " + s[i];
    constexpr int dx[] = {0, 1, -1, 0}, dy[] = {1, 0, 0, -1};
    function<int(int, int, int, int)> ha = [&] (int i, int j, int i_, int j_) {
        return i * (m + 1) * (n + 1) * (m + 1) + j * (n + 1) * (m + 1) + i_ * (m + 1) + j_;
    };
    function<array<int, 4>(int)> rha = [&] (int msk) {
        int i, j, i_, j_;
        i = msk / ((m + 1) * (n + 1) * (m + 1));
        msk %= (m + 1) * (n + 1) * (m + 1);
        j = msk / ((n + 1) * (m + 1));
        msk %= (n + 1) * (m + 1);
        i_ = msk / (m + 1);
        j_ = msk % (m + 1);
        return (array<int, 4>) {i, j, i_, j_};
    };
    vector<int> vis((n + 1) * (m + 1) * (n + 1) * (m + 1) + 1), st((n + 1) * (m + 1) * (n + 1) * (m + 1) + 1);
    function<void(int)> bfs = [&] (int be) {
        queue<int> q;
        q.push(be); 
        while (!q.empty()) {
            auto [x, y, x_, y_] = rha(q.front()); q.pop();
            for (int i = 0; i < 4; i ++ ) {
                int nx = x + dx[i], ny = y + dy[i];
                int nx_ = x_ + dx[i], ny_ = y_ + dy[i];
                if (nx < 1 || nx > n || ny < 1 || ny > m || s[nx][ny] == 'O') continue;
                if (nx_ < 1 || nx_ > n || ny_ < 1 || ny_ > m || s[nx_][ny_] == 'O') {
                    st[be] = 1;
                    continue;
                }
                int msk = ha(nx, ny, nx_, ny_);
                if (vis[msk]) continue;
                q.push(msk);
            }
        }
    };
    int ans = 0;
    function<int(int, int)> check = [&] (int i, int j) {
        for (int i_ = 1; i_ <= n; i_ ++ ) 
            for (int j_ = 1; j_ <= m; j_ ++ ) {
                if (i_ == i && j_ == j) continue;
                if (s[i_][j_] == 'O') continue;
                int msk = ha(i, j, i_, j_);
                if (!vis[msk]) bfs(msk);
                if (!st[vis[msk]]) return 0;
            }
        return 1;
    };
    for (int i = 1; i <= n; i ++ ) 
        for (int j = 1; j <= m; j ++ ) {
            if (s[i][j] == 'O') continue;
            ans += check(i, j);
        }
    cout << ans << "\n";
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T -- ) solve();
    return 0;
}