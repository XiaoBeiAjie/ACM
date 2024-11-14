#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
typedef long long ll;

void solve() {
    int n;cin>>n;
    vector<vector<int>> e(n+1);
    vector<array<int,2>> ans(n+1);
    for(int i=2,x;i<=n;++i) cin>>x,e[x].push_back(i);
    vector<int> fa(n+1);iota(fa.begin(),fa.end(),0);
    auto dfs1=[&](auto self,int x,int pre)->void
    {
        for(auto &it:e[x])
        {
            if(it==pre) continue;
            self(self,it,x);
            fa[x]=min(fa[x],fa[it]);
        }
    };
    dfs1(dfs1,1,-1);
    //for(int i=1;i<=n;++i) cout<<fa[i]<<" \n"[i==n];
    int tot;
    auto dfs=[&](auto self,int tp,int x,int pre)->void
    {
        for(auto &it:e[x])
        {
            if(it!=pre) self(self,tp,it,x);
        }
        ans[x][tp]=++tot;
    };
    tot=0;
    for(int i=1;i<=n;++i) 
    {
        sort(e[i].begin(),e[i].end(),[&](int t1,int t2){return fa[t1]<fa[t2];});
        //for(auto &it:e[i]) cout<<it<<' ';
        //cout<<'\n';
    }
    dfs(dfs,0,1,-1);
    tot=0;
    for(int i=1;i<=n;++i) reverse(e[i].begin(),e[i].end());
    dfs(dfs,1,1,-1);
    for(int i=1;i<=n;++i) cout<<ans[i][0]<<' '<<ans[i][1]<<" \n"[i==n];
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T; cin >> T;
    while (T -- ) solve();
    //system("pause");
    return 0;
}