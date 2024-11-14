#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
typedef long long LL;
#define endl "\n"
int n , m, q;
map<pair<int , int > , int > mp;
int f[N];
int a[N];
struct edge
{
    int x ,y, v;
};
int cnt;
edge e[N];
vector<edge> ee;
int find(int x)
{
    return x == f[x] ? x : f[x] = find(f[x]);
}
void merge(int x ,int y)
{
    int fx = find(x);
    int fy = find(y);
    if(fx != fy) f[fx] = fy;
}
bool cmp(edge a , edge b)
{
    return a.v < b.v;
}
void solve() {
    cin >> n >> m >> q;
    for(int i = 0; i < m; i++)
    {
        int x, y , v;
        cin >> x >> y >> v;
        if(x > y) swap(x , y);
        ee.push_back({x, y, v});

        if(mp.count({x, y})) mp[{x, y}] = min(mp[{x, y}], v);
        else mp[{x, y}] = v;
    }
    sort(ee.begin(), ee.end(), cmp);
    for(int i = 0; i < q; i++)
    {
        set<int > se;
        int k;
        cin >> k;
        for(int i = 0 ; i < k; i++)
            cin >> a[i] , se.insert(a[i]);
        sort(a,  a + k);
        LL ans = 0;
        if(k < 1e3)
        {
            for(int i = 0 ; i < k ; i++)
                f[a[i]] = a[i];
            cnt = 0;
            for(int i = 0; i < k; i++)
                for(int j = i + 1; j < k; j++)
                {
                    if(mp.count({a[i], a[j]})) {
                        e[cnt++] = {a[i], a[j], mp[{a[i], a[j]}]};
                    }
                }
            sort(e ,e + cnt, cmp);
            int ct = 0;
            for(int i = 0 ;i < cnt ; i++)
            {
                int x = e[i].x , y = e[i].y;
                int v = e[i].v;
                if(find(x) != find(y)) {
                    merge(x, y);
                    ct++;
                    ans += v;
                    if(ct == k - 1) break;
                }
            }
            if(ct != k - 1) ans = -1;
            cout << ans << endl;
        }
        else 
        {
            int ct = 0;
            LL ans = 0;
            for(int i = 0; i < k; i++) f[a[i]] = a[i];
            for(int i = 0 ; i < m; i++)
            {
                int x = ee[i].x , y = ee[i].y;
                int v = ee[i].v;
                if(!se.count(x) || !se.count(y)) continue;
                if(find(x) != find(y)) {
                    merge(x, y);
                    ct++;
                    ans += v;
                    if(ct == k - 1) break;
                }
            }
            if(ct != k - 1) ans = -1;
            cout << ans << endl;
        }
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T = 1;
    while (T -- ) solve();
    system("pause");
    return 0;
}