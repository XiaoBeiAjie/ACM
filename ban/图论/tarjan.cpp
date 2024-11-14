#include <bits/stdc++.h>
using namespace std;
struct Tarjan
{
	vector<vector<int>> e,e1,ans;//旧图,新图,存储强连通块
	vector<int> col,dfn,low,stk,in;
	int cnt,top,_cnt;//_cnt为强连通数量
	Tarjan(int sz)
	{
		e.resize(sz+1);e1.resize(sz+1);
		ans.resize(sz+1);col.resize(sz+1);
		dfn.resize(sz+1);low.resize(sz+1);
		stk.resize(sz+1);in.resize(sz+1);
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
	void topo()
	{
		int res=0;
		queue<int> qu;
		for(int i=1;i<=_cnt;++i) if(!in[i]) qu.push(i);
		while(!qu.empty())
		{
			++res;
			int t=qu.front();qu.pop();
			for(auto &c:e1[t])
			{
				--in[c];
				if(in[c]==0) qu.push(c);
			}
		}
		cout<<res<<'\n';
	}
	void getans(int m)//所有强连通分量
	{
		for(int i=1;i<=m;++i) if(!dfn[i]) tarjan(i);
		for(int i=1;i<=m;++i)
		{
			if(!ans[col[i]].empty())
			{
				for(auto &t:ans[col[i]]) cout<<t<<' ';
				cout<<'\n';
				ans[col[i]].clear();
			}
		}
	}
	void build(int m)//建立新图
	{
		for(int i=1;i<=m;++i)
		{
			for(auto &c:e[i])
			{
				if(col[i]!=col[c])
				{
					e1[col[i]].push_back(col[c]);
					++in[col[c]];
				}
			}
		}
		topo();//获取新图所有非环点数量
	}
};
int main()
{
	int n,m;cin>>n>>m;Tarjan tarj(n); 
	for(int i=0,x,y;i<m;++i)
	{
		cin>>x>>y;
		tarj.e[x].push_back(y);
	}
	tarj.getans(n);
	tarj.build(n);
}