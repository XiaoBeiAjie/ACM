#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

bool mem1;

const int INF = 0x3f3f3f3f;
const int N = 2e6 + 10;
const int M = 2e7;
int s, t;
int dis[N], pre[N] , preve[N];
int n , m;
bool inq[N];
struct edge
{
    int to, cost , cap, rev;
    edge(int to_ , int cost_ , int c , int rev_)
    {
        to = to_;
        cost = cost_;
        cap = c;
        rev = rev_;
    }
};
vector<edge> e[N];
void addedge(int u , int v , int cost , int cap)
{
    e[u].push_back(edge(v , cost , cap , e[v].size()));
    e[v].push_back(edge(u, -cost , 0 , e[u].size() - 1));
}
bool spfa(int s ,  int t , int cnt)
{
    memset(pre, -1, sizeof(pre));
    for(int i = 0 ; i <= cnt ; i++)
    {
        dis[i] = INF;
        inq[i] = false;
    }
    dis[s] = 0;
    queue<int > q;
    q.push(s);
    inq[s] = true;
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        inq[u] = false;
        for(int i = 0 ; i < e[u].size() ; i++)
        {
            if(e[u][i].cap > 0)
            {
                int v = e[u][i].to;
                int cost = e[u][i].cost;
                if(dis[u] + cost < dis[v])
                {
                    dis[v] = dis[u] + cost;
                    pre[v] = u;
                    preve[v] = i;
                    if(!inq[v])
                        inq[v] = true, q.push(v);
                }
            }
        }
    }
    return dis[t] != INF;
}
int mincost(int s, int t , int cnt)
{
    int cost = 0;
    while(spfa(s,  t ,  cnt))
    {
        // cerr << "*****" << endl;
        int v = t, flow = INF;
        while(pre[v] != -1)
        {
            int u = pre[v] , i = preve[v];
            flow = min(flow , e[u][i].cap);
            v = u;
        }
        v = t;
        while(pre[v] != -1)
        {
            int u = pre[v] , i = preve[v];
            e[u][i].cap -= flow;
            e[v][e[u][i].rev].cap += flow;
            v = u;
        }
        cost += dis[t] * flow;
    }
    return cost;
}
vector<int> v[N];
void solve() {
    cin >> n;
    vector<int > num;
    vector<int > a(n + 1);
    for(int i = 0 ; i < n ; i++)
    {
        int tmp;
        cin >> a[i];
        tmp = a[i];
        num.push_back(tmp);
        for(int j = 1 ; j <= tmp / j ; j++)
        {
            if(tmp % j == 0)
            {
                v[i].push_back(j) , num.push_back(j);
                if(tmp / j != j)
                    v[i].push_back(tmp / j) , num.push_back(tmp / j);
            }
                
        }
    }
    s = 0;
    sort(num.begin() , num.end());
    int cnt = unique(num.begin() , num.end()) - num.begin();
    for(int i = 0 ; i < cnt; i++)
    {
        int tmp = num[i];
        int pos = lower_bound(num.begin() , num.begin() + cnt, tmp) - num.begin();
        pos++;
        for(int j = 1 ; j <= tmp / j ; j++)
        {
            if(tmp % j == 0)
            {
                int pos2 = lower_bound(num.begin() , num.begin() + cnt, j) - num.begin();
                pos2++;
                if(pos != pos2)
                    addedge(pos , pos2 , -1 , 1);
                if(j == tmp / j) continue;
                pos2 = lower_bound(num.begin() , num.begin() + cnt, tmp / j) - num.begin();
                pos2++;
                if(pos != pos2)
                    addedge(pos , pos2 , -1 , 1);
            }
        }
    }
    // for(int i = 0 ; i < cnt ; i ++)
    //     cerr << num[i] << " ";
    // cerr << endl;
    // return ;
    for(int i = 0 ; i < n ; i++)
    {
        int pos = lower_bound(num.begin() , num.begin() + cnt, a[i]) - num.begin();
        pos++;
        addedge(s , pos, 0 , 1);
    }
    t = cnt + 1;
    for(int i = 0 ; i < cnt ; i++)
        addedge(i + 1 , t , 0 , 1);
    cout << -mincost(s , t , t) << endl;
}


bool mem2;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #ifdef LOCAL
    cerr << fixed << setprecision(2) << "Memory : " << abs(&mem1 - &mem2) / 1024. / 1024. << "MB\n";
    #endif
    int T; T = 1;
    while (T -- ) solve();
    #ifdef LOCAL
    cerr << "Time : " << clock() * 1000 / CLOCKS_PER_SEC << "MS\n";
    #endif
    return 0;
}