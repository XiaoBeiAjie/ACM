#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;
const int N = 110;
typedef long long LL;

int T;
int n, m, p, q;
int f[N][N][2];
int ans;

void bfs() {
    queue<array<int, 3>> que;
    que.push({n, m, 0});
    while (!que.empty()) {
        auto u = que.front();
        if (u[1] == m && u[2] == 1) return ans = f[u[0]][m][1], void();
        que.pop();
        for (int i = 0; i <= u[0]; i ++ ) 
            for (int j = 0; j <= u[1]; j ++ ) 
                if (i + j <= p && ((u[0] - i <= u[1] - j + q) || !(u[1] - j))) 
                    if (f[n - u[0] + i][m - u[1] + j][u[2] ^ 1] > f[u[0]][u[1]][u[2]] + 1) {
                        f[n - u[0] + i][m - u[1] + j][u[2] ^ 1] = f[u[0]][u[1]][u[2]] + 1;
                        que.push({n - u[0] + i, m - u[1] + j, u[2] ^ 1}); 
                    }
    }
    ans = -1;
}

void solve() {
    cin >> m >> n >> p >> q;
    for (int i = 0; i <= n; i ++ ) 
        for (int j = 0; j <= m; j ++ ) 
            f[i][j][0] = f[i][j][1] = 0x3f3f3f3f;
    f[n][m][0] = 0;
    bfs();
    std::cout << ans << std::endl;
}

int main(void) {
    T = 1;
    while (T -- ) solve();
    system("pause");
    return 0;
}