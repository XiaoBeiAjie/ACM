#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;
const int N = 100010;
typedef long long ll;
#define pb push_back
vector<int > v[N];
int T;
ll n;
ll dp[N][2];
ll cnt;
ll q[N];
ll child[N];
ll a[N];
bool st[N];
void dfs(int u)
{
    st[u] = 1;
    child[u] = 1;
    for(auto i : v[u])
    {
        if(st[i]) continue;
        dfs(i);
        child[u] += child[i];
    }
    cnt = 0;
    dp[u][1] = a[u];
    int tt = 1;
    for(auto i : v[u])
    {
        q[cnt++] = abs(dp[i][0] - dp[i][1]);
        if(max(dp[i][0], dp[i][1]) == dp[i][0])
        {
            if(child[i])
        }
    }

}

void solve() {
    cin >> n;
    for(int i = 1; i <= n ; i++)
        cin >> a[i];
    for(int i = 0; i < n ; i++)
    {
        int x, y;
        cin >> x >> y;
        v[x].pb(y);
        v[y].pb(x);
    }
    dfs(1);
}

int main(void) {
    scanf("%d", &T);
    while (T -- ) solve();
    system("pause");
    return 0;
}