#include <bits/stdc++.h>
using namespace std;
const int maxn=2e5+5,maxm=5e5+5;
int n,m,cnt,i,a[maxn],op[maxn][4],b[maxn];
int lower(int x)
{
    int l=1,r=cnt,t,mid;
    while(l<=r) 
    {
        if(b[mid=(l+r)>>1]<=x) l=(t=mid)+1;
        else r=mid-1;
    }
    return t;
}
struct node
{
    int val,cnt,sum,p;
    node *l,*r;
    node(){val=sum=cnt=p=0;l=r=nullptr;}
    void up(){sum=l->sum+r->sum+cnt;}
}*blank=new(node),*T[maxm],pool[maxn*10],*cur;
void Rotatel(node *&x){node *y=x->r;x->r=y->l;x->up();y->l=x;y->up();x=y;}
void Rotater(node *&x){node *y=x->l;x->l=y->r;x->up();y->r=x;y->up();x=y;}
void Ins(node *&x,int y,int p)
{
    if(x==blank){x=cur++;x->val=y;x->l=x->r=blank;x->sum=x->cnt=1;x->p=rand();return;}
    x->sum+=p;
    if(y==x->val){x->cnt+=p;return;}
    if(y<x->val)
    {
        Ins(x->l,y,p);
        if(x->l->p>x->p) Rotater(x);
    }
    else
    {
        Ins(x->r,y,p);
        if(x->r->p>x->p) Rotatel(x);
    }
}
int Ask(node *x,int y)
{
    int t=0;
    while(x!=blank)
    {
        if(y<x->val) x=x->l;
        else t+=x->l->sum+x->cnt,x=x->r;
    }
    return t;
}
void add(int v,int i,int p)
{
    int a=1,b=cnt,mid,f=1,x=1;
    while(a<b)
    {
        if(f) Ins(T[x],i,p);
        mid=(a+b)>>1;x<<=1;
        if(v<=mid) f=1,b=mid;
        else f=0,a=mid+1,x|=1;
    }
    Ins(T[x],i,p);
}
int kth(int l,int r,int k)
{
    int x=1,a=1,b=cnt,mid;
    while(a<b)
    {
        mid=(a+b)>>1;x<<=1;
        int t=Ask(T[x],r)-Ask(T[x],l-1);
        if(k<=t) b=mid;
        else k-=t,a=mid+1,x|=1;
    }
    return a;
}
void build(int x,int a,int b)
{
    T[x]=blank;
    if(a==b) return;
    int mid=(a+b)>>1;
    build(x<<1,a,mid),build(x<<1|1,mid+1,b);
}
int main()
{
    blank->l=blank->r=blank;
    cin>>n;cur=pool;
    for(i=1;i<=n;++i) cin>>a[i],b[i]=a[i];
    cnt=n;cin>>m;
    for(i=1;i<=m;++i) 
    {
        cin>>op[i][0]>>op[i][1]>>op[i][2];
        if(op[i][0]==1) b[++cnt]=op[i][2];
        else cin>>op[i][3];
    }
    sort(b+1,b+cnt+1);
    for(i=1;i<=n;++i) a[i]=lower(a[i]);
    for(i=1;i<=m;++i) if(op[i][0]==1) op[i][2]=lower(op[i][2]);
    build(1,1,cnt);
    for(i=1;i<=n;++i) add(a[i],i,1);
    for(i=1;i<=m;++i)
    {
        if(op[i][0]==1) //a[x]=y
        add(a[op[i][1]],op[i][1],-1),add(a[op[i][1]]=op[i][2],op[i][1],1);
        else //[x,y]第k小
        cout<<b[kth(op[i][1],op[i][2],op[i][3])]<<'\n';
    }
}