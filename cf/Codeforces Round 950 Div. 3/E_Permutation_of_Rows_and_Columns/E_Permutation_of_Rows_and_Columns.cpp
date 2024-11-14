#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;
const int N = 100010;
typedef long long LL;

int T;
int n, m;

void solve() {
    scanf("%d%d", &n, &m);
    vector<vector<int>> a(n + 1, vector<int>(m + 1));
    unordered_map<int, pair<int, int>> mp;
    for (int i = 1; i <= n; i ++ ) 
        for (int j = 1; j <= m; j ++ ) 
            scanf("%d", &a[i][j]);
    int x;
    for (int i = 1; i <= n; i ++ ) 
        for (int j = 1; j <= m; j ++ ) 
            scanf("%d", &x), mp[x] = {i, j};
    vector<int> b(m + 1);
    int idx = mp[a[1][1]].x;
    b[1] = mp[a[1][1]].y;
    for (int j = 2; j <= m; j ++ ) 
        if (mp[a[1][j]].x != idx) return puts("No"), void();
        else b[j] = mp[a[1][j]].y;
    for (int i = 2; i <= n; i ++ ) {
        idx = mp[a[i][1]].x;
        for (int j = 1; j <= m; j ++ ) 
        if (mp[a[i][j]].x != idx || mp[a[i][j]].y != b[j]) return puts("No"), void();
    }
     puts("Yes");   
}

int main(void) {
    scanf("%d", &T);
    while (T -- ) solve();
    system("pause");
    return 0;
}