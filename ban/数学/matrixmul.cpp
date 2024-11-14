#include <bits/stdc++.h>
using namespace std;
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
struct Mat
{
    vector<vector<mint>> mat;
    int n;
    Mat(int nt)
    {
        n=nt;mat.resize(nt);
        for(int i=0;i<nt;++i) mat[i].resize(nt,0);
    }
    void init(){for(int i=0;i<n;++i) mat[i][i]=1;}
    Mat operator*(Mat b)
    {
        Mat c(n);
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<n;++j)
            {
                c.mat[i][j]=0;
                for(int k=0;k<n;++k)
                {
                    c.mat[i][j]=c.mat[i][j]+mat[i][k]*b.mat[k][j];
                }
            }
        }
        return c;
    }      
    Mat operator+(Mat b)
    {
        Mat c(n);
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<n;++j)
            {
                c.mat[i][j]=mat[i][j]+b.mat[i][j];
            }
        }
        return c;   
    }
    Mat quickpow(int m)
    {
        Mat res1(n),a(n);
        res1.init();a.mat=mat;
        while(m)
        {
            if(m&1) res1=res1*a;
            a=a*a;m>>=1;
        }
        return res1;
    }
};
int main()
{
    int n;cin>>n;Mat p(2);
    p.mat[0][0]=p.mat[1][0]=p.mat[0][1]=1;p.mat[1][1]=0;
    for(int i=0,x;i<n;++i)
    {
        cin>>x;Mat q=p.quickpow(x);
        cout<<q.mat[0][0]<<'\n';//乘上x个(1,1\n1,0)的结果,也是斐波那契第x+1项的值
    }
}