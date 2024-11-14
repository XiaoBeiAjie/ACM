#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int ksm(ll a,ll n,ll p)
{
	ll res=1;a%=p;
	while(n)
	{
		if(n&1) res=res*a%p;
		n>>=1;
		a=a*a%p;
	}
	return res;
}
struct node
{
	ll l,r;
	mutable ll v;
	node(ll a,ll b,ll c):l(a),r(b),v(c){;}
	bool operator<(const node &ope) const{return l<ope.l;}
};
struct odt
{
    set<node> tree;
    set<node>::iterator split(ll pos)
    {
	    auto it=tree.lower_bound(node(pos,0,0));
	    if(it!=tree.end()&&it->l==pos) return it;
	    --it;
	    ll l=it->l,r=it->r,v=it->v;
	    tree.erase(it);
	    tree.insert(node(l,pos-1,v));
	    return tree.insert(node(pos,r,v)).first;
    }
    void assign(ll l,ll r,ll v)
    {
	    auto ed=split(r+1),bn=split(l);
	    tree.erase(bn,ed);
	    tree.insert(node(l,r,v));
    }
    void add(ll l,ll r,ll v)
    {
	    auto ed=split(r+1);
	    for(auto it=split(l);it!=ed;++it) it->v+=v;
    }
    ll kth(ll l,ll r,ll k)
    {
	    auto ed=split(r+1);
	    vector<pair<ll,ll>> ve;
	    for(auto it=split(l);it!=ed;++it) ve.push_back({it->v,it->r-it->l+1});
	    sort(ve.begin(),ve.end());
	    for(auto &p:ve)
	    {
		    k-=p.second;
		    if(k<=0) return p.first;
	    }
	    return -1;
    }
    ll sop(ll l,ll r,ll x,ll y)
    {
	    ll res=0;
	    auto ed=split(r+1);
	    for(auto it=split(l);it!=ed;++it)
	    res=(res+ksm(it->v,x,y)*(it->r-it->l+1))%y;
	    return res;
    }
};
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	auto solve=[&]()->void
    {
        const static int mod=1e9+7;
        int n,m,vmax;ll seed;
        cin>>n>>m>>seed>>vmax;
        auto rnd=[&]()
        {
            int res=seed;
            seed=(seed*7+13)%mod;
            return res;
        };
        odt test;
        for(int i=1,op;i<=n;++i)
        {
            op=rnd();
		    test.tree.insert(node(i,i,op%vmax+1));
        }
        for(int i=1,op,ll,rr,x,y;i<=m;++i)
	    {
		    op=rnd()%4+1;ll=rnd()%n+1;rr=rnd()%n+1;
		    if(ll>rr) swap(ll,rr);
		    if(op==3) x=rnd()%(rr-ll+1)+1;
		    else x=rnd()%vmax+1;
		    if(op==4) y=rnd()%vmax+1;
		    if(op==1) test.add(ll,rr,x);//区间加x
		    else if(op==2) test.assign(ll,rr,x);//区间赋值x
		    else if(op==3) cout<<test.kth(ll,rr,x)<<'\n';//区间第x小
		    else cout<<test.sop(ll,rr,x,y)<<'\n';//区间x次幂和模y
            
	    }
    };
    solve();
}