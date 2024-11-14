#define lz 2*u,l,mid
#define rz 2*u+1,mid+1,r

int a[N];
int flag[4*N];
 
struct node
{
    int lm0, rm0, sm0;
    int lm1, rm1, sm1;
    int sum0, sum1;
} tree[4*N];
 
void Xor(int u)
{
    swap(tree[u].sum1,tree[u].sum0);
    swap(tree[u].lm1,tree[u].lm0);
    swap(tree[u].rm1,tree[u].rm0);
    swap(tree[u].sm1,tree[u].sm0);
 
    if(flag[u]==0) flag[u]=3;
    else if(flag[u]==1) flag[u]=2;
    else if(flag[u]==2) flag[u]=1;
    else if(flag[u]==3) flag[u]=0;
}
 
void push_up(int u, int l, int r)
{
    tree[u].sum1=tree[2*u].sum1+tree[2*u+1].sum1;
    tree[u].sum0=tree[2*u].sum0+tree[2*u+1].sum0;
    tree[u].lm0=tree[2*u].lm0;
    tree[u].lm1=tree[2*u].lm1;
    tree[u].rm0=tree[2*u+1].rm0;
    tree[u].rm1=tree[2*u+1].rm1;
    tree[u].sm0=max(tree[2*u].sm0,tree[2*u+1].sm0);
    tree[u].sm1=max(tree[2*u].sm1,tree[2*u+1].sm1);
    int mid=(l+r)>>1;
 
    if(tree[2*u].lm1==mid-l+1) tree[u].lm1+=tree[2*u+1].lm1;
    if(tree[2*u+1].rm1==r-mid) tree[u].rm1+=tree[2*u].rm1;
    int t=tree[2*u].rm1+tree[2*u+1].lm1;
    if(t>tree[u].sm1) tree[u].sm1=t;
 
    if(tree[2*u].lm0==mid-l+1) tree[u].lm0+=tree[2*u+1].lm0;
    if(tree[2*u+1].rm0==r-mid) tree[u].rm0+=tree[2*u].rm0;
    int h=tree[2*u].rm0+tree[2*u+1].lm0;
    if(h>tree[u].sm0) tree[u].sm0=h;
}
 
void push_down(int u, int l, int r)
{
    if(flag[u])
    {
        int mid=(l+r)>>1;
        if(flag[u]==1)
        {
            tree[2*u].sum1=tree[2*u].lm1=tree[2*u].rm1=tree[2*u].sm1=0;
            tree[2*u].sum0=tree[2*u].lm0=tree[2*u].rm0=tree[2*u].sm0=mid-l+1;
 
            tree[2*u+1].sum1=tree[2*u+1].lm1=tree[2*u+1].rm1=tree[2*u+1].sm1=0;
            tree[2*u+1].sum0=tree[2*u+1].lm0=tree[2*u+1].rm0=tree[2*u+1].sm0=r-mid;
            flag[2*u]=flag[2*u+1]=1;
        }
        else if(flag[u]==2)
        {
            tree[2*u].sum1=tree[2*u].lm1=tree[2*u].rm1=tree[2*u].sm1=mid-l+1;
            tree[2*u].sum0=tree[2*u].lm0=tree[2*u].rm0=tree[2*u].sm0=0;
 
            tree[2*u+1].sum1=tree[2*u+1].lm1=tree[2*u+1].rm1=tree[2*u+1].sm1=r-mid;
            tree[2*u+1].sum0=tree[2*u+1].lm0=tree[2*u+1].rm0=tree[2*u+1].sm0=0;
            flag[2*u]=flag[2*u+1]=2;
        }
        else
        {
            Xor(2*u);
            Xor(2*u+1);
        }
        flag[u]=0;
    }
}
 
void build(int u, int l, int r)
{
    flag[u]=0;
    if(l==r)
    {
        tree[u].sum1=tree[u].lm1=tree[u].rm1=tree[u].sm1=a[l]?1:0;
        tree[u].sum0=tree[u].lm0=tree[u].rm0=tree[u].sm0=a[l]?0:1;
        return ;
    }
    int mid=(l+r)>>1;
    build(lz);
    build(rz);
    push_up(u,l,r);
}
 
void Update(int u, int l, int r, int tl, int tr, int c)
{
    if(tl<=l&&r<=tr)
    {
        if(c==1)
        {
            tree[u].sum1=tree[u].lm1=tree[u].rm1=tree[u].sm1=0;
            tree[u].sum0=tree[u].lm0=tree[u].rm0=tree[u].sm0=r-l+1;
            flag[u]=1;
        }
        else if(c==2)
        {
            tree[u].sum1=tree[u].lm1=tree[u].rm1=tree[u].sm1=r-l+1;
            tree[u].sum0=tree[u].lm0=tree[u].rm0=tree[u].sm0=0;
            flag[u]=2;
        }
        else    /// 这里要特别注意，对于异或操作不能把此前的标记给覆盖掉，必须进行相应的更新才能保证向下延迟标记不出错，这里错了好久
        {
            Xor(u);
        }
        return ;
    }
    push_down(u,l,r);
    int mid=(l+r)>>1;
    if(tr<=mid) Update(lz,tl,tr,c);
    else if(tl>mid) Update(rz,tl,tr,c);
    else
    {
        Update(lz,tl,mid,c);
        Update(rz,mid+1,tr,c);
    }
    push_up(u,l,r);
}
 
int Query1(int u,int l, int r, int tl, int tr)
{
    if(tl<=l&&r<=tr)
    {
        return tree[u].sum1;
    }
    push_down(u,l,r);
    int mid=(l+r)>>1;
    if(tr<=mid) return Query1(lz,tl,tr);
    else if(tl>mid) return Query1(rz,tl,tr);
    else
    {
        int t1=Query1(lz,tl,mid);
        int t2=Query1(rz,mid+1,tr);
        return t1+t2;
    }
}
 
int Query2(int u, int l, int r, int tl, int tr)
{
    if(tl<=l&&r<=tr)
    {
        return tree[u].sm1;
    }
    push_down(u,l,r);
    int mid=(l+r)>>1;
    if(tr<=mid) return Query2(lz,tl,tr);
    else if(tl>mid) return Query2(rz,tl,tr);
    else
    {
        int t1=Query2(lz,tl,mid);
        int t2=Query2(rz,mid+1,tr);
        int  t=max(t1,t2);
        t1=min(tree[2*u].rm1,mid-tl+1);
        t2=min(tree[2*u+1].lm1,tr-mid);
        t1+=t2;
        return max(t,t1);
    }
}

/*

1）“0 a b”，表示将区间[a,b]范围内的数全部置0；
（2）“1 a b”，表示将区间[a,b]内的数全部置1；
（3）"2 a b"，表示将区间[a,b]内的数0变成1，1变成0；
（4）"3 a b"，表示查询[a,b]范围内1的数；
（5）"4 a b"，表示查询[a,b]范围内最长的连续的1；

*/ 



