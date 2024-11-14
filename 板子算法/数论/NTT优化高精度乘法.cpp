#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long LL;
const int TT=998244353;
int r[263000];char n[100005];
inline int read()
{
	int ret=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-f;ch=getchar();}
	while(ch>='0'&&ch<='9'){ret=ret*10+ch-'0';ch=getchar();}
	return ret*f;
}
inline int QP(int a,int b)
{
	int ret=1,w=a;
	while(b)
	{
		if(b&1) ret=(LL)ret*w%TT;
		w=(LL)w*w%TT;b>>=1;
	}
	return ret;
}
inline void NTT(int* A,int limit,int type)
{
	for(int i=0;i<limit;i++)
		if(i<r[i])
			swap(A[i],A[r[i]]);
	for(int mid=1;mid<limit;mid<<=1)
	{
		int gn=QP(3,(TT-1)/(mid<<1));
		if(type<0) gn=QP(gn,TT-2);
		for(int j=0;j<limit;j+=mid<<1)
		{
			int g=1;
			for(int k=0;k<mid;k++,g=(LL)g*gn%TT)
			{
				int x=A[j+k],y=(LL)g*A[j+k+mid]%TT;
				A[j+k]=(x+y)%TT;
				A[j+k+mid]=(x-y+TT)%TT;
			}
		}
	}
	if(type<0)
	{
		int inv=QP(limit,TT-2);
		for(int i=0;i<=limit;i++) A[i]=(LL)A[i]*inv%TT;
	}
}
struct BigInteger
{
	int len,a[263000];
	BigInteger(){len=0;memset(a,0,sizeof(a));}
	BigInteger(char* S)
	{
		len=0;memset(a,0,sizeof(a));
		int n=strlen(S+1);
		reverse(S+1,S+1+n);
		len=(n+1)/2;
		for(int i=1;i<=n;i++) S[i]-='0';
		for(int i=1;i<=len;i++)
			a[i]=S[i*2-1]+S[i*2]*10;
	}
	BigInteger operator * (BigInteger b)
	{
		BigInteger a=*this,c;
		c.len=a.len+b.len;
		int limit=1,l=0;
		while(limit<=c.len){limit<<=1;l++;}
		for(int i=0;i<limit;i++)
			r[i]=(r[i>>1]>>1)|((i&1)<<(l-1));
		NTT(a.a+1,limit,1);
		NTT(b.a+1,limit,1);
		for(int i=1;i<=limit;i++)
			c.a[i]=(LL)a.a[i]*b.a[i]%TT;
		NTT(c.a+1,limit,-1);
		for(int i=1;i<=c.len;i++)
		{
			c.a[i+1]+=c.a[i]/100;
			c.a[i]%=100;
		}
		if(!c.a[c.len]) c.len--;
		return c;
	}
	void operator /= (int b)
	{
		for(int i=len;i;i--)
		{
			a[i-1]+=(a[i]%b)*100;
			a[i]/=b;
		}
		a[0]=0;
		if(!a[len]) len--;
	}
	inline void Inc()
	{
		a[1]++;
		for(int i=1;i<=len;i++)
		{
			if(a[i]<100) break;
			a[i+1]+=a[i]/100;
			a[i]%=100;
		}
		if(a[len+1]) len++;
	}
	void Print()
	{
		printf("%d",a[len]);
		for(int i=len-1;i>0;i--)
			printf("%02d",a[i]);
		putchar('\n');
	}
}A,B,C,D,ans;
int main()
{
	scanf("%s",n+1);
	A=n;A.Inc();
	B=A;B.Inc();
	C=B;C.Inc();
	D=C;C.Inc();
	ans=A*B*C*D;
	ans/=24;
	ans.Print();
	return 0;
}
