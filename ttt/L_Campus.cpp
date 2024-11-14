#include<bits/stdc++.h>
using namespace std;
const int inf = 1e9;
const int N = 2e5 + 10;
int n , m;
int k , T;
int dis[20][N];
vector<pair<int , int > > e[N];
map<int , int > mp;
bool st[N];
int a[N];
array<int , 3> p[20];
void dij(int s)
{
    int p = mp[s];
    for(int i = 1 ; i <=  n ; i++)
        dis[p][i] = inf , st[i] = 0;
    priority_queue<pair< int , int >  > q;
    dis[p][s] = 0;
    q.push({0 , s});
    while(!q.empty())
    {
        int u = q.top().second;
        q.pop();
        if(st[u]) continue;
        st[u] = 1;
        for(auto tt : e[u])
        {
            int v = tt.first;
            int w = tt.second;
            if(v == u) continue;
            if(dis[p][v] > dis[p][u] + w)
            {
                dis[p][v] = dis[p][u] + w;
                q.push({-dis[p][v] , v});
            }
        }
    } 
}
void solve()
{
    cin >> n >> m >> k >> T;
    for(int i = 1 ; i <= n; i++)
        cin >> a[i];
    for(int i = 0 ; i < k ; i++)
        cin >> p[i][0] >> p[i][1] >> p[i][2];
    for(int i = 0 ;  i < m ; i++)
    {
        int x , y  ,z;
        cin >> x >> y >> z;
        e[x].push_back({y , z});
        e[y].push_back({x , z});
    }
    for(int i = 0 ; i < k ; i ++)
    {
        mp[p[i][0]] = i;
        dij(p[i][0]);
    }
    for(int i = 1 ; i <= n ; i++)
    {
        vector<pair<int , int > > v;
        for(int j = 0  ; j < k ; j ++)
            v.push_back({dis[j][i] , j});
        sort(v.begin() , v.end());
        vector<pair<int , int > > qujian;
        for(auto tmp : v)
        {
            int t = tmp.second;
            int l1 = p[t][1];
            int r1 = p[t][2];
            for(auto j : qujian)
            {
                int l2 = j.first;
                int r2 = j.second;
                if(l1 >=)
            }
            qujian.push_back({p[t][1] , p[t][2]});
        }
    }
}
int main()
{
    solve();
}