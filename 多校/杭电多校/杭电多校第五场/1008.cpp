#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
typedef long long ll;

void solve() {
    int n,k;cin>>n>>k;
    vector<vector<int>> f(n+1,vector<int>(2,0));
    vector<vector<array<int,3>>> e(n+1);
    vector<int> g(n+1);
    for(int i=1,x;i<=k;++i) cin>>x,g[x]=i;
    for(int i=0;i<2;++i)
    {
        for(int j=0,x,y,z;j<n-1;++j)
        {
            cin>>x>>y>>z;
            e[x].push_back({y,z,i});
            e[y].push_back({x,z,i});
        }
    }
    vector<vector<bool>> vis(n+1,vector<bool>(2,0));
    int ans=0;
    queue<int> qu;qu.push(1);
    vis[1][0]=vis[1][1]=true;
    int pre[2]={0,0};
    while(!qu.empty())
    {
        int x=qu.front();qu.pop();
        for(auto [y,z,tag]:e[x])
        {
            if(vis[y][tag]) continue;
            if(g[x]&&g[y]) 
            {
                pre[tag]+=z;
                //f[y][tag]=max(f[y][tag],f[x][tag]+z);
                pre[tag]=max(pre[tag],pre[!tag]);
                //f[y][tag]=max(f[y][tag],f[x][!tag]);
                //cout<<x<<' '<<y<<' '<<tag<<' '<<f[y][tag]<<'\n';
                ans=max(ans,pre[tag]);
            }
            qu.push(y);
            vis[y][tag]=true;
        }
    }
    cout<<ans<<'\n';
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1; cin >> T;
    while (T -- ) solve();
    system("pause");
    return 0;
}