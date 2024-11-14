#include <bits/stdc++.h>
using namespace std;
struct query 
{
	int l,r,id;
	query(int a=0,int b=0,int c=0):l(a),r(b),id(c){}
};
struct Muline
{
	vector<int> aa,cnt,belong;
	int now,siz,bnum;
	Muline(int sz)
	{
		siz=sqrt(sz+10);bnum=ceil((double)(sz+10)/siz);now=0;
		aa.resize(sz+10);cnt.resize(sz+10);belong.resize(sz+10);
		for(int i=1;i<=bnum;++i) 
		{
        	for(int j=(i-1)*siz+1;j<=i*siz;++j) 
        	{
				belong[j]=i;
			}
    	}
	}
	void getans(int m,vector<query>& q)
	{
		vector<int> ans(m);
		sort(q.begin(),q.end(),[&](query a,query b)
		{return (belong[a.l]^belong[b.l])?belong[a.l]<belong[b.l]:((belong[a.l]&1)?a.r<b.r:a.r>b.r);});
		int l=1,r=0;
		for(int i=0;i<m;++i) 
    	{
			int ql=q[i].l,qr=q[i].r;
			while(l<ql) now-=!--cnt[aa[l++]];
			while(l>ql) now+=!cnt[aa[--l]]++;
			while(r<qr) now+=!cnt[aa[++r]]++;
			while(r>qr) now-=!--cnt[aa[r--]];
			ans[q[i].id]=now;
		}
		for(int i=0;i<m;++i) cout<<ans[i]<<' ';//[L,R]有几个不同元素
	}
};
int main() 
{
	int n;cin>>n;Muline mule(n);
	for(int i=1;i<=n;++i) cin>>mule.aa[i];
	int m;cin>>m;vector<query> q(m);
	for(int i=0;i<m;++i) cin>>q[i].l>>q[i].r,q[i].id=i;
	mule.getans(m,q);
}