//单哈希 

typedef unsigned long long int ull;
const int N=1e5+10;
const int M=233;
ull h[N],base[N];
ull query(int l,int r)//获取字符串[l,r]的哈希值
{
    return h[r]-h[l-1]*base[r-l+1];
}
void init(string s)//初始化哈希
{
    int n=s.size();
    s="0"+s;//让其下标从1开始
    base[0]=1;
    for(int i=1;i<=n;i++)
    {
        h[i]=h[i-1]*M+s[i];
        base[i]=base[i-1]*M;// base[i]=M^i
    }
}
ull merge(int l1, int r1, int l2, int r2)
//求[l1,r1],[l2,r2]子串并的哈希值
{
    return query(l1, r1) * base[r2 - l2 + 1] + query(l2, r2);
}


//双哈希
typedef long long int ll;
const int N=1010;
ll h[N][N],base1[N],base2[N];
int a[N][N],n,m;
void init()//构建
{
    base1[0]=base2[0]=1;
    for(int i=1;i<N;i++)
    {
        base1[i]=base1[i-1]*131;
        base2[i]=base2[i-1]*233;
    }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            h[i][j]=h[i][j-1]*131+a[i][j];//行哈希
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            h[i][j]=h[i-1][j]*233+h[i][j];//列哈希
}
ll query(int x1,int y1,int x2,int y2)//查询矩阵的哈希值
{
    return h[x2][y2]-h[x2][y1-1]*base1[y2-y1+1]-h[x1-1][y2]*base2[x2-x1+1]
    +h[x1-1][y1-1]*base1[y2-y1+1]*base2[x2-x1 + 1];
} 
