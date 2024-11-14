//����ϣ 

typedef unsigned long long int ull;
const int N=1e5+10;
const int M=233;
ull h[N],base[N];
ull query(int l,int r)//��ȡ�ַ���[l,r]�Ĺ�ϣֵ
{
    return h[r]-h[l-1]*base[r-l+1];
}
void init(string s)//��ʼ����ϣ
{
    int n=s.size();
    s="0"+s;//�����±��1��ʼ
    base[0]=1;
    for(int i=1;i<=n;i++)
    {
        h[i]=h[i-1]*M+s[i];
        base[i]=base[i-1]*M;// base[i]=M^i
    }
}
ull merge(int l1, int r1, int l2, int r2)
//��[l1,r1],[l2,r2]�Ӵ����Ĺ�ϣֵ
{
    return query(l1, r1) * base[r2 - l2 + 1] + query(l2, r2);
}


//˫��ϣ
typedef long long int ll;
const int N=1010;
ll h[N][N],base1[N],base2[N];
int a[N][N],n,m;
void init()//����
{
    base1[0]=base2[0]=1;
    for(int i=1;i<N;i++)
    {
        base1[i]=base1[i-1]*131;
        base2[i]=base2[i-1]*233;
    }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            h[i][j]=h[i][j-1]*131+a[i][j];//�й�ϣ
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            h[i][j]=h[i-1][j]*233+h[i][j];//�й�ϣ
}
ll query(int x1,int y1,int x2,int y2)//��ѯ����Ĺ�ϣֵ
{
    return h[x2][y2]-h[x2][y1-1]*base1[y2-y1+1]-h[x1-1][y2]*base2[x2-x1+1]
    +h[x1-1][y1-1]*base1[y2-y1+1]*base2[x2-x1 + 1];
} 
