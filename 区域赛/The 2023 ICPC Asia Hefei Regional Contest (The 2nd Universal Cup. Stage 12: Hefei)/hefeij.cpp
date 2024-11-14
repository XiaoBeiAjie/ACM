#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;
const int N = 100010;
typedef long long LL;

int T;

int f[N];
    int n ;
    int m;
struct edge
{
    int u, v, w;
    edge(int a, int b, int c)
    {
        u = a;
        v = b;
        w = c;
    }
};
vector<edge> ed;
vector<edge> edd;
vector<pair<int, int> > no[N];
bool st[N];
int find(int x)
{
    return x == f[x] ? x : x = find(f[x]);
}
void merge(int x ,int y)
{
    int fx = find(x);
    int fy = find(y);
    if(fx != fy ) f[fx] = fy;
}
bool cmp(edge a, edge b)
{
    return a.w < b.w;
}
void dfs(int u, int end, int &ans, int maxx ,int now)
{
    if(now > maxx) return  ;
    if(u == end)
    {
        cout << now << endl;
        ans = max(now, ans);
        return ;
    }
    st[u] = 1;
    for(auto i : no[u])
    {
        cout << i.second <<  endl;
        if(st[i.first]) continue;
        dfs(i.first, end, ans, maxx, max(now, i.second));
    }
}
void solve() {
    for(int i = 0; i <= n ; i++)
        f[i] = i;
    cin >> n >> m;
    for(int i = 0; i < m; i ++)
    {
        int x, y, z;
        cin >> x >> y >> z;
        ed.push_back({x, y, z});
    }
    sort(ed.begin(), ed.end(), cmp);
    for(int i = 0; i < m ; i++)
    {
        int f1 = find(1), fn = find(n);
        int u = ed[i].u, v = ed[i].v;
        int w = ed[i].w;
        int fu = find(u), fv = find(v);
        if((fu == f1 && fv == fn))
            edd.push_back({u, v, w});
        else if((fu == fn && fv == f1))
            edd.push_back({v, u, w});
        else no[u].push_back({v, w}), no[v].push_back({u, w}),merge(u,v);
    }
    int fin = 9999999;
    for(auto i: edd)
    {
        int u = i.u;
        int v = i.v;
        int w = i.w;
        int ans = 0;
        for(int i = 0; i <= n ; i++)
            st[i] = 0;
            st[u]  = 1;
            st[v] = 1;
        for(auto j : no[u])
            dfs(j.first, 1, ans, w, j.second);
        if(u == 1) ans = 0;
        for(int i = 0; i <= n ; i++)
            st[i] = 0;
        if(v != n){
            st[v] = 1;
            for(auto j : no[v])
            dfs(j.first, n, ans, w, j.second);
        }
        fin = min(fin, ans +  w);
    }
    cout << fin << endl;
}

int main(void) {
    T = 1;
    while (T -- ) solve();
    system("pause");
    return 0;
}