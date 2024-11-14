#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define int long long
bool mem1;
#define endl "\n"
const int N = 2e3 + 10;
int dp[N][N];
int que(int x1 , int x2 , int y1 , int y2)
{
    return dp[x2][y2] - dp[x2][y1 - 1] - dp[x1 - 1][y2] + dp[x1 - 1][y1 - 1];
}
void solve() {
    int n , m  , k;
    cin >> n >> m >> k;
    string s;
    cin >> s;
    int len = s.length();
    int maxy = 0 , miny = 0, maxx = 0 , minx = 0;
    int nx = 0, ny = 0 ,dx = 0 , dy = 0;
    for(int i = 0 ; i <= 2 * n + 1  ; i++)
        for(int j = 0 ; j <= 2 * m + 1 ; j ++)
            dp[i][j] = 0;
    dp[n + 1][m + 1] = 1;
    for(int i = 0 ; i < len ; i++)
    {
        if(s[i] == 'L')
            ny-- , dy++;
        else if(s[i] == 'R')
            ny++ , dy--;
        else if(s[i] == 'U')
            nx-- , dx++;
        else
            nx++ , dx--;
        nx = min(nx, n);
        nx = max(nx , -n);
        ny = min(ny , m);
        ny = max(ny , -m);
        dx = min(dx, n);
        dx = max(dx , -n);
        dy = min(dy , m);
        dy = max(dy , -m);
        if(!dp[dx + n + 1][dy + m + 1]) dp[dx + n + 1][dy + m + 1] = 1;
        maxx = max(maxx, nx);
        minx = min(minx , nx);
        maxy = max(maxy , ny);
        miny = min(miny , ny);
    }
    // for(int i = 1 ; i <= 2 * n + 1 ; i++)
    //     for(int j = 1 ; j <= 2 * m + 1 ; j++)
    //         cerr << dp[i][j] << " \n"[j == 2 * m + 1];
    for(int i = 1 ; i <= 2 * n + 1 ; i++)
        for(int j = 1 ; j <= 2 * m + 1 ; j++)
            dp[i][j] = dp[i][j] + dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1];
    // cerr << endl;
    // for(int i = 1 ; i <= 2 * n + 1 ; i++)
    //     for(int j = 1 ; j <= 2 * m + 1 ; j++)
    //         cerr << dp[i][j] << " \n"[j == 2 * m + 1];
    int tx1 , tx2 , ty1 , ty2;
    // tx1 = maxx + 1;
    // tx2 = n + minx;
    // ty1 = maxy + 1;
    // ty2 = m + miny;
    tx1 = -minx + 1;
    tx2 = n - maxx;
    ty1 = -miny + 1;
    ty2 = m - maxy;
    //cerr << tx1 << ' ' << ty1 << " " << tx2 << ' ' << ty2 << endl;
    if(tx1 > tx2 || ty1 > ty2 || tx1 <= 0 || tx2 <= 0 || ty1 <= 0 || ty2 <= 0 || tx1 >= n + 1 || tx2 >= n + 1 || ty2 >= m + 1 || ty1 >= m + 1)
    {
        if(k == 0)
            cout << n * m << endl;
        else
            cout << 0 << endl;
        return ;
    }
    int res = (tx2 - tx1  + 1) * (ty2 - ty1 + 1);
    int ans = 0;
    // cerr << res << endl;
    //cerr << tx1 << ' ' << ty1 << " " << tx2 << ' ' << ty2 << endl;
    for(int i = 1 ; i <= n ; i++)
    {
        for(int j = 1 ; j <= m ; j++)
        {
            int px1 = tx1 - i + n + 1;
            int px2 = tx2 - i + n + 1;
            int py1 = ty1 - j + m + 1;
            int py2 = ty2 - j + m + 1;
            int tmp = que(px1 , px2 , py1 , py2);
            if(res - tmp == k)
                 ans ++;
        }
    }
    cout << ans << endl;
    
}
//cerr << px1 << " " << py1 << " "  << px2 << " " << py2 << " " << "*"  << " " , cerr << tmp << " " << i << " " << j << endl,
bool mem2;

signed main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #ifdef LOCAL
    cerr << fixed << setprecision(2) << "Memory : " << abs(&mem1 - &mem2) / 1024. / 1024. << "MB\n";
    #endif
    int T; cin >> T;
    while (T -- ) solve();
    #ifdef LOCAL
    cerr << "Time : " << clock() * 1000 / CLOCKS_PER_SEC << "MS\n";
    #endif
    return 0;
}