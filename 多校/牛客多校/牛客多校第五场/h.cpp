#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
typedef long long ll;

void solve() {
    int n,m;cin>>n>>m;
    vector<vector<int>> nex(n+1);
    for(int i=0,x,y;i<m;++i) 
    {
        cin>>x>>y;
        if(x==y) continue;
        nex[x].push_back(y);
        nex[y].push_back(x);
    }
    vector<vector<int>> dep(n+1,vector<int>(n+1,0));
    vector<vector<vector<bool>>> f(n+1,vector<vector<bool>>(n+1,vector<bool>(n+1,0)));
    int kk,ans=1;
    auto dfs=[&](auto self,int x,vector<bool> vis)->void
    {
        //cout<<x<<'\n';
        ans=max(ans,dep[kk][x]);
        //f[kk][x]=vis1;
        for(int i=1;i<=n;++i) f[kk][x][i]=vis[i];
        if(dep[kk][x]>=20) return;
        vector<bool> vis1=vis;
        for(auto &it:nex[x]) vis1[it]=true;
        for(auto &it:nex[x])
        {
            if(!vis[it])
            {
                dep[kk][it]=dep[kk][x]+1;
                self(self,it,vis1);
            }
        }
    };
    vector<bool> vt(n+1);
    for(int i=1;i<=n;++i)
    {
        kk=i;
        for(int j=1;j<=n;++j) vt[j]=0;
        dep[kk][i]=1;vt[i]=1;
        dfs(dfs,i,vt);
    }
    //for(int i=1;i<=40;++i) cout<<f[1][19][i]<<" \n"[i==40];
    //for(int i=1;i<=40;++i) cout<<f[20][39][i]<<" \n"[i==40];
    for(int i=1;i<=n;++i)
    {
        for(auto &j:nex[i])
        {
            for(int t=1;t<=n;++t)
            {
                if(!dep[t][i]) continue;
                for(int k=1;k<=n;++k)
                {
                    if(f[t][i][k]) continue;
                    if(!dep[j][k]) continue;
                    bool gg=true;
                    for(int tt=1;tt<=n&&gg;++tt)
                    {
                        if(!f[j][k][tt]) continue;
                        else if(tt!=i&&f[t][i][tt]) gg=false;
                    }
                    if(gg) 
                    {
                        //if(t==1&&i==19&&j==20&&k==39)
                        //cout<<t<<' '<<i<<'*'<<' '<<j<<' '<<k<<'\n';
                        ans=max(ans,dep[t][i]+dep[j][k]);
                    }
                }
            }
        }
    }
    cout<<ans<<'\n';
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1; //cin >> T;
    while (T -- ) solve();
    //system("pause");
    return 0;
}