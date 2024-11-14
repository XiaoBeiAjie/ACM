#include <bits/stdc++.h>
using namespace std;
using ll = long long;
template<const int T>
struct ModInt 
{
    const static int mod=T;
    int x;
    ModInt(int x = 0):x(x%mod){}
    ModInt(long long x):x(int(x%mod)){} 
    int val() {return x;}
    ModInt operator + (const ModInt &a) const {int x0=x+a.x;return ModInt(x0<mod?x0:x0-mod);}
    ModInt operator - (const ModInt &a) const {int x0=x-a.x;return ModInt(x0<0?x0+mod:x0);}
    ModInt operator * (const ModInt &a) const {return ModInt(1ll * x * a.x % mod); }
    ModInt operator / (const ModInt &a) const {return *this*a.inv();}
    bool operator == (const ModInt &a) const {return x==a.x;};
    bool operator != (const ModInt &a) const {return x!=a.x;};
    void operator += (const ModInt &a) {x+=a.x;if(x>=mod) x-=mod;}
    void operator -= (const ModInt &a) {x-=a.x;if(x<0) x+=mod;}
    void operator *= (const ModInt &a) {x=1ll*x*a.x%mod;}
    void operator /= (const ModInt &a) {*this = *this / a; }
    friend ModInt operator + (int y,const ModInt &a){int x0=y+a.x; return ModInt(x0<mod?x0:x0-mod);}
    friend ModInt operator - (int y,const ModInt &a){int x0=y-a.x; return ModInt(x0<0?x0+mod:x0);}
    friend ModInt operator * (int y,const ModInt &a){return ModInt(1ll*y*a.x%mod);}
    friend ModInt operator / (int y,const ModInt &a){return ModInt(y)/a;}
    friend ostream &operator<<(ostream &os,const ModInt &a) {return os<<a.x;}
    friend istream &operator>>(istream &is,ModInt &t){return is>>t.x;}
    ModInt pow(int64_t n) const 
    {
        ModInt res(1),mul(x);
        while(n)
        {
            if(n&1) res*=mul;
            mul*=mul;
            n>>=1;
        }
        return res;
    }
    ModInt inv() const 
    {
        int a=x,b=mod,u=1,v=0;
        while(b) 
        {
            int t=a/b;
            a-=t*b;swap(a,b);
            u-=t*v;swap(u,v);
        }
        if(u<0) u+=mod;
        return u;
    }
};
using mint=ModInt<998244353>;
struct Yanghui
{
	vector<vector<mint>> C;
	Yanghui(int sz)
	{
		C.resize(sz+1);
		for(int i=0;i<=sz;++i) C[i].resize(sz+1);
		C[0][0]=1;
		for(int i=1;i<=sz;++i)
		{
			C[i][0]=C[i][i]=1;
			for(int j=1;j<=i-1;++j)
			{
            	C[i][j]=C[i-1][j-1]+C[i-1][j];
        	}
		}	
	}
};
int main()
{
    Yanghui yan(500);
    cout<<yan.C[4][2]<<'\n';
}