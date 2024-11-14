#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
int fa[N];
int pre[N];
int dis[N];
int ans[N];
int find(int x)
{
    if(fa[x] == x)
        return x;
    fa[x] = find(fa[x]);
    dis[x] = pre[x] == x ? 0 : dis[pre[x]] + 1;
    // cout << x << " " << dis[x] << "\n";
    return fa[x];
}
void solve() {
    int n;cin>>n;
    for(int i = 0; i <= n ; i++)
        fa[i] = i;
    for(int i = 0 ; i <= n ; i++)
        dis[i] = 0 , ans[i] = 0;
    for(int i=1,x,y,z;i<n;++i)
    {
        cin>>x>>y>>z;
        pre[y] = x;
        int f = find(x);
        fa[y] = x;
        dis[y] = max(dis[x] + 1, dis[y]);
        ans[f] = max(ans[f], ans[y] + dis[y]);
        cout << ans[z] << " ";
    }
     cout << "\n";
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T; cin >> T;
    while (T -- ) solve();
    system("pause");
    return 0;
}