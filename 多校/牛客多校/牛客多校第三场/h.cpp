#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
typedef long long ll;
using ull=unsigned long long;
void solve() {
    int n,m,k;cin>>n>>m>>k;
    mt19937_64 rnd(0);
    uniform_int_distribution<ll> make(0,(ll)1<<30);
    vector<ll> hsh(k);
    for(int i=0;i<k;++i) hsh[i]=make(rnd);
    vector<vector<ll>> dif(n+2,vector<ll>(m+2,0));
    for(int i=0,x1,y1,x2,y2;i<k;++i)
    {
        cin>>x1>>y1>>x2>>y2;
        dif[x1][y1]+=hsh[i];
        dif[x2+1][y2+1]+=hsh[i];
        dif[x2+1][y1]-=hsh[i];
        dif[x1][y2+1]-=hsh[i];
    }
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=m;++j)
        {
            dif[i][j]+=dif[i-1][j]+dif[i][j-1]-dif[i-1][j-1];
        }
    }
    int ans=2e9,cur;
    vector<vector<bool>> vis(n+1,vector<bool>(m+1,0));
    auto dfs=[&](auto self,int x,int y)->void
    {
        if(x>1&&!vis[x-1][y]&&dif[x-1][y]==dif[x][y]) ++cur,vis[x-1][y]=1,self(self,x-1,y); 
        if(x<n&&!vis[x+1][y]&&dif[x+1][y]==dif[x][y]) ++cur,vis[x+1][y]=1,self(self,x+1,y); 
        if(y>1&&!vis[x][y-1]&&dif[x][y-1]==dif[x][y]) ++cur,vis[x][y-1]=1,self(self,x,y-1); 
        if(y<m&&!vis[x][y+1]&&dif[x][y+1]==dif[x][y]) ++cur,vis[x][y+1]=1,self(self,x,y+1); 
    };
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=m;++j)
        {
            if(!vis[i][j])
            {
                vis[i][j]=1;
                cur=1;
                dfs(dfs,i,j);
                if(dif[i][j]) ans=min(ans,cur);
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
    system("pause");
    return 0;
}