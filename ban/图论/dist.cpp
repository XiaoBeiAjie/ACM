#include <bits/stdc++.h>
using namespace std;
const int maxn=1e4+4;
struct edge 
{
    int v,w;
    edge(int x=0,int y=0):v(x),w(y){}
};
struct node 
{
    int dis,u;
    node(int x=0,int y=0):dis(x),u(y){}
    bool operator>(const node& a)const{ return dis>a.dis;}
};
struct Dist
{
    vector<vector<edge>> e;
    vector<int> dis;
    vector<bool> vis;
    priority_queue<node,vector<node>,greater<node>> qu;
    int s;
    Dist(int ss,int sz)
    {
        s=ss;e.resize(sz+1);
        dis.resize(sz+1,2e9);vis.resize(sz+1,0);
    }
    void dijkstra()
    {
        dis[s]=0;qu.push({0,s});
        while(!qu.empty()) 
        {
            int u=qu.top().u;qu.pop();
            if(vis[u]) continue;
            vis[u]=1;
            for(auto ed:e[u]) 
            {
                int v=ed.v,w=ed.w;
                if(dis[v]>dis[u]+w) 
                {
                    dis[v]=dis[u]+w;
                    qu.push({dis[v],v});
                }
            }
        }
    }
};
int main()
{
    int n,m;cin>>n>>m;Dist dist(1,n);
    for(int i=0,x,y,z;i<m;++i)
    {
        cin>>x>>y>>z;
        dist.e[x].push_back({y,z});
        dist.e[y].push_back({x,z});
    }
    dist.dijkstra();
    for(int i=1;i<=n;++i) cout<<dist.dis[i]<<' ';//源点到i的最短距离
    return 0;
}