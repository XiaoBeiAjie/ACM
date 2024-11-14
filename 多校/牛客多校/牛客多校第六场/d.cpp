#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
typedef long long ll;
vector<array<int,2>> res;
struct Tarjan
{
	vector<vector<int>> e,e1,ans;//旧图,新图,存储强连通块
	vector<int> col,dfn,low,stk,in;
	int cnt,top,_cnt;//_cnt为强连通数量
    vector<vector<int>> ss;
	Tarjan(int sz)
	{
		e.resize(sz+1);e1.resize(sz+1);
		ans.resize(sz+1);col.resize(sz+1);
		dfn.resize(sz+1);low.resize(sz+1);
		stk.resize(sz+1);in.resize(sz+1);
        ss.resize(sz+1);
		cnt=top=_cnt=0;
	}
	void tarjan(int u)
	{	
		dfn[u]=low[u]=++cnt;
		stk[++top]=u;
		for(auto v:e[u])
    	{
			if(!dfn[v]) tarjan(v),low[u]=min(low[u],low[v]);
			else if(!col[v]) low[u]=min(low[u],dfn[v]);
		}
		if(low[u]==dfn[u])
    	{
			col[u]=++_cnt;
			ans[_cnt].push_back(u);
			while(stk[top]!=u) ans[_cnt].push_back(stk[top]),col[stk[top--]]=_cnt;
			--top;
		}
	}
	void getans(int m)//所有强连通分量
	{
		for(int i=1;i<=m;++i) if(!dfn[i]) tarjan(i);
		for(int i=1;i<=m;++i)
		{
            ss[col[i]].push_back(i);
			if(!ans[col[i]].empty())
			{
                if(2<(int)ans[col[i]].size())
                {
                    res.push_back({ans[col[i]][0],ans[col[i]][ans[col[i]].size()-1]});
                    for(int j=1;j<(int)ans[col[i]].size();++j) res.push_back({ans[col[i]][j-1],ans[col[i]][j]});
                }
				//for(auto &t:ans[col[i]]) cout<<t<<' ';
				//cout<<'\n';
				ans[col[i]].clear();
			}
		}
	}
};
void solve() {
    int n,m;cin>>n>>m;
    string s;
    Tarjan tarj(n); 
    vector<vector<int>> nex(n+1);
	for(int i=0,x,y;i<m;++i)
	{
		cin>>x>>y>>s;
        if(s[0]=='L') tarj.e[x].push_back(y),tarj.e[y].push_back(x);
        else nex[x].push_back(y),nex[y].push_back(x);
	}
	tarj.getans(n);
    auto dfs=[&](auto self,int x)->void
    {
        for(auto &it:nex[x])
        {
            if(tarj.col[it]!=tarj.col[1])
            {
                for(auto &it1:tarj.ss[tarj.col[it]]) tarj.col[it1]=tarj.col[1];
                res.push_back({x,it});
                self(self,it);
            }
        }
    };
	for(int i=1;i<=n;++i)
    {
        if(tarj.col[i]==tarj.col[1])
        {
            dfs(dfs,i);
        }
    }
    vector<bool> vis(n+1,0);
    for(auto [x,y]:res) vis[x]=vis[y]=true;
    for(int i=1;i<=n;++i) if(!vis[i]) return cout<<"NO\n",void();
    cout<<"YES\n"<<res.size()<<'\n';
    for(auto [x,y]:res) cout<<x<<' '<<y<<'\n';
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1; //cin >> T;
    while (T -- ) solve();
    system("pause");
    return 0;
}