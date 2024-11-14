#include <bits/stdc++.h>
using namespace std;
struct Hier
{
    vector<vector<int>> edge;
    vector<vector<bool>> vis;
    int n,m;stack<int> ans;
    Hier(int nn,int mm):n(nn),m(mm)
    {
        edge.resize(n+1);
        vis.resize(n+1);
    }
    void dfs(int x)
    {
        for(int i=0;i<(int)edge[x].size();++i)
        {
            if(vis[x][i]) continue;
            vis[x][i]=true;
            int j=lower_bound(edge[edge[x][i]].begin(),edge[edge[x][i]].end(),x)-edge[edge[x][i]].begin();
            vis[edge[x][i]][j]=true;
            dfs(edge[x][i]);
        }
        ans.push(x);
    }
};
int main()
{
    int n,m;cin>>n>>m;
    Hier he(n,m);
    for(int i=0,x,y;i<m;++i)
    {
        cin>>x>>y;
        he.edge[x].push_back(y);
        he.vis[x].push_back(0);
        if(x!=y)
        {
            he.edge[y].push_back(x);
            he.vis[y].push_back(0);
        }
    }
    he.dfs(1);
    if(m+1!=(int)he.ans.size()) cout<<-1<<'\n';
    else
    {
        set<pair<int,int>> vis;
        vector<int> ans;
        while(!he.ans.empty()) ans.push_back(he.ans.top()),he.ans.pop();
        for(int i=1;i<=m;++i)
        {
            if(vis.count({min(ans[i-1],ans[i]),max(ans[i-1],ans[i])})) 
            {
                return cout<<-1<<'\n',0;
            }
            vis.insert({min(ans[i-1],ans[i]),max(ans[i-1],ans[i])});
        }
        for(auto &it:ans) cout<<it<<' ';//输出欧拉通路
    }
}

