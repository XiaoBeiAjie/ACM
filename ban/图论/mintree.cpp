#include <bits/stdc++.h>
using namespace std;
struct node 
{
	int x,y,z;
	node(int xx=0,int yy=0,int zz=0):x(xx),y(yy),z(zz){}
};	
struct Mintree
{
	vector<node> edge;
	vector<int> fa,cnt;
	int n;long long sum;
	Mintree(int sz)
	{
		fa.resize(sz+1);edge.clear();
		iota(fa.begin(),fa.end(),0);
        cnt.resize(sz+1,1);n=sz;sum=0;
	}
	int get(int x) {return x==fa[x]?x:fa[x]=get(fa[x]);}
	void build()
	{
		sort(edge.begin(),edge.end(),[](node a,node b){return a.z<b.z;});
		for(auto &it:edge) 
    	{
			int x=get(it.x);
			int y=get(it.y);
			if(x==y) continue;
			cnt[x]+=cnt[y];fa[y]=x;
			sum+=it.z;
		}
		int ans=0;
		for(int i=1;i<=n;++i)if(i==fa[i]) ++ans;
		if(ans>1) cout<<"impossible"<<'\n';
		else cout<<sum<<'\n';
	}
};
int main() 
{
	int n,m;cin>>n>>m;Mintree mte(n);
	for(int i=1,u,v,w;i<=m;++i) 
    {
		cin>>u>>v>>w;
		mte.edge.push_back(node(u,v,w));
	}
	mte.build();
}