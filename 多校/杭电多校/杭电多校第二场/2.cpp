#include <bits/stdc++.h>
using namespace std;
const int N = 35;
typedef long long ll;

struct Monster {
    int x, y, val, att, len;
};

int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    int d; cin >> d;
    vector<Monster> mo(k);
    map<pair<int, int>, int> mp;
    for (int i = 0; i < k; i ++ ) {
        cin >> mo[i].x >> mo[i].y >> mo[i].val >> mo[i].att >> mo[i].len;
        mp[{mo[i].x, mo[i].y}] = i;
    }   
    vector cost(n + 1, vector (m + 1, vector<int> (1 << k)));
    for (int z = 0; z < (1 << k); z ++ ) 
        for (int i = 1; i <= n; i ++ ) 
            for (int j = 1; j <= m; j ++ ) 
                for (int t = 0; t < k; t ++ ) {
                    if (z & (1 << t)) continue;
                    int dis = abs(i - mo[t].x) + abs(j - mo[t].y);
                    if (dis <= mo[t].len) cost[i][j][z] += mo[t].att;
                }
    int sx, sy;
    cin >> sx >> sy;
    vector f(n + 1, vector (m + 1, vector<int> (1 << k, 0x3f3f3f3f)));
    f[sx][sy][0] = 0;
    function<void()> dijkstra = [&] () {
        priority_queue<array<int, 4>> q;
        vector vis(n + 1, vector (m + 1, vector<bool> (1 << k)));
        f[sx][sy][0] = 0;
        q.push({- f[sx][sy][0], sx, sy, 0});
        while (!q.empty()) {
            auto [g, x, y, z] = q.top();
            q.pop();
            if (vis[x][y][z]) continue;
            vis[x][y][z] = true;
            for (int i = 0; i < 4; i ++ ) {
                int nz = z;
                for (int t = 1; t <= d; t ++ ) {
                    int nx = x + t * dx[i], ny = y + t * dy[i];
                    if (nx < 1 || nx > n || ny < 1 || ny > m) continue;
                    if ((mp.find({nx, ny}) != mp.end() && (z >> mp[{nx, ny}]) ^ 1)) {
                        nz |= (1 << mp[{nx, ny}]);
                        continue;
                    } 
                    if (f[nx][ny][nz] > cost[nx][ny][nz] - g) {
                        f[nx][ny][nz] = cost[nx][ny][nz] - g;
                        q.push({- f[nx][ny][nz], nx, ny, nz});
                    }
                }
            }
                
        }
    };
    dijkstra();
    vector<int> g(1 << k);
    for (int z = 0; z < (1 << k); z ++ ) {
        int res = 0;
        for (int t = 0; t < k; t ++ ) 
            if (z & (1 << t)) res += mo[t].val;
        g[z] = res;
    }
    int ans = 0;  
    for (int i = 1; i <= n; i ++ ) 
        for (int j = 1; j <= m; j ++ ) 
            for (int z = 0; z < (1 << k); z ++ ) 
                ans = max(ans, g[z] - f[i][j][z]);  
    cout << ans << endl;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T; cin >> T;
    while (T -- ) solve();
    system("pause");
    return 0;
}