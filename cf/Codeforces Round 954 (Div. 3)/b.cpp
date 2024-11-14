#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;
const int N = 110;
typedef long long LL;

int T;
int n, m;
vector<vector<int>> g(N, vector<int> (N));

int dx[4] = {0, 1, -1, 0}, dy[4] = {1, 0, 0, -1};

bool check(int x, int y) {
    for (int i = 0; i < 4; i ++ ) {
        int nx = x + dx[i], ny = y + dy[i];
        if (nx && nx <= n && ny && ny <= m && g[nx][ny] >= g[x][y]) 
            return false;
    }
    return true;;
}

void trn(int x, int y) {
    int res = 0;
    for (int i = 0; i < 4; i ++ ) {
        int nx = x + dx[i], ny = y + dy[i];
        if (nx && nx <= n && ny && ny <= m) 
            res = max(res, g[nx][ny]);
    }
    g[x][y] = res;
}

void solve() {
    cin >> n >> m;
    for (int i = 1; i <= n; i ++ ) 
        for (int j = 1; j <= m; j ++ ) 
            cin >> g[i][j];
    for (int i = 1; i <= n; i ++ ) 
        for (int j = 1; j <= m; j ++ ) 
            if (check(i, j)) trn(i, j);
    for (int i = 1; i <= n; i ++ ) {
        for (int j = 1; j <= m; j ++ ) 
            cout << g[i][j] << " ";
        cout << endl;
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> T;
    while (T -- ) solve();
    system("pause");
    return 0;
}