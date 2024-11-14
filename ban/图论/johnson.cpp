#include <bits/stdc++.h>
using namespace std;
struct Edge 
{
    int u,v,w;
    Edge(int x=0,int y=0,int z=0):u(x),v(y),w(z){}
};
struct Johnson
{
    vector<Edge> edges;
    vector<vector<Edge>> adj;
    vector<int> dist;
    Johnson(){}
    bool BellmanFord(vector<Edge> &ed,int n,int s) 
    {
        dist.resize(n+1,INT_MAX);dist[s]=0;
        bool negtiveCycle;
        for(int i=1;i<=n;++i) 
        {
            negtiveCycle=false;
            for(auto e:ed) 
            {
                if(dist[e.u]<INT_MAX&&dist[e.v]>dist[e.u]+e.w)
                {
                    dist[e.v]=dist[e.u]+e.w;
                    negtiveCycle=true;
                }
            }
            if(!negtiveCycle) break;
        }
        return negtiveCycle;
    }
    vector<int> Dijkstra(int n,int s) 
    {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        vector<int> dist(n+1,INT_MAX);
        vector<bool> vis(n+1,false);
        dist[s]=0;pq.push({0,s});
        while(!pq.empty()) 
        {
            auto node=pq.top();pq.pop();
            int u=node.second;
            if(vis[u]) continue;
            vis[u]=true;
            for(auto e:adj[u]) 
            {
                int v=e.v,w=e.w;
                if(dist[u]<INT_MAX &&dist[v]>dist[u]+w) 
                {
                    dist[v]=dist[u]+w;
                    pq.push({dist[v],v});
                }
            }
        }
        return dist;
    }
    void getans(int n)
    {
        vector<Edge> edges_new=edges;
        for(int v=1;v<=n;++v) edges_new.push_back({0,v,0});
        bool hasCycle=BellmanFord(edges_new,n,0);
        if(hasCycle) 
        {
            cout<<"-1"<<'\n';
            return ;
        }
        for(auto &e:edges_new) e.w=e.w+dist[e.u]-dist[e.v];
        adj.resize(n+1);
        for(auto const e:edges_new) adj[e.u].push_back(e);
        vector<vector<int>> dist_all(n+1,vector<int>(n+1,0));
        for(int i=1;i<=n;++i) 
        {
            auto d=Dijkstra(n,i);
            for(int j=1;j<=n;++j) 
            {
                if(d[j]==INT_MAX) continue;
                dist_all[i][j]=d[j]+dist[j]-dist[i];
            }
        }
        for(int i=1;i<=n;++i)
        {
            for(int j=1;j<=n;++j)
            {
                cout<<i<<' '<<j<<' '<<dist_all[i][j]<<'\n';//i到j的最短距离
            }
        }
    }
};
int main() 
{
    int n,m;cin>>n>>m;Johnson john;
    for(int i=0,x,y,z;i<m;++i)
    {
        cin>>x>>y>>z;
        john.edges.push_back({x,y,z});
        john.edges.push_back({y,x,z});
    }
    john.getans(n);
}