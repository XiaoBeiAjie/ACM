#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
const int INF = 0x3f3f3f3f;
typedef long long LL;

int n , m ;
int k ;
vector<int> e[N];
map<pair<int , int> , int> mp;
int dep[N];
bool st[N];
int maxx;
void bfs()
{
    for(int i = 1; i <= n ; i++) dep[i] = INF;
    queue<int> q;
    q.push(1);
    dep[1] = 0;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        bool flag = 0;
        for(int i : e[u]){
            if(dep[i] != INF)  continue;
            flag = 1;
            dep[i] = dep[u] + 1;
            if(u <= i)mp[{u, i}] = 1;
            else mp[{i, u}] = 1;
            q.push(i);
        }
        if(!flag) st[u] = 1;
    }
}
void solve() {
    cin >> n >> m >> k;
    int x , y;
    for(int i = 0;i < m ; i++){
        cin >> x >> y;
        if(x > y) swap(x, y);
        mp[{x, y}] = 0;
        e[x].push_back(y);
        e[y].push_back(x);
    }
    bfs();
    if (st[1] == 1) return cout << 1 << endl, void();
    int ans = 0;
    for(auto &i : mp){
        if(i.second == 1) continue;
        int u = i.first.first;
        int v = i.first.second;
        ans += max(0, k - dep[u]);
        ans += max(0, k - dep[v]);
        st[u] = st[v] = 0;
    }
    for(int i = 1; i <= n ; i++){
        if(dep[i] <= k) ans ++;
        if(st[i]) ans += max(0, k - dep[i]);
    }
    cout << ans << endl;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T; T = 1;
    while (T -- ) solve();
    system("pause");
    return 0;
}