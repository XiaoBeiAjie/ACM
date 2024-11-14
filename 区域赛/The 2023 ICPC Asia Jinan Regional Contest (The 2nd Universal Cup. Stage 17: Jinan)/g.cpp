#include <bits/stdc++.h>
using namespace std;
template<const int T>
struct ModInt 
{
    const static int mod=T;
    int x;
    ModInt(int x=0):x(x%mod){}
    ModInt(long long x):x(int(x%mod)){} 
    int val() {return x;}
    ModInt operator + (const ModInt &a) const {int x0=x+a.x;return ModInt(x0<mod?x0:x0-mod);}
    ModInt operator - (const ModInt &a) const {int x0=x-a.x;return ModInt(x0<0?x0+mod:x0);}
    ModInt operator * (const ModInt &a) const {return ModInt(1ll*x*a.x%mod);}
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
using mint=ModInt<(int)1e9+7>;
struct TwoSat 
{
    int n;
    vector<vector<int>> e;
    vector<bool> ans;
    TwoSat(int n):n(n),e(2*n),ans(n){}
    //加析取条件(u,v),f,g代表x,y是否为非,f=1代表x为非
    void addClause(int u,bool f,int v,bool g) 
    {
        e[2*u+!f].push_back(2*v+g);
        e[2*v+!g].push_back(2*u+f);
    }
    //找是否有合法解
    bool satisfiable() 
    {
        vector<int> id(2*n,-1),dfn(2*n,-1),low(2*n,-1);
        vector<int> stk;
        int now=0,cnt=0;
        function<void(int)> tarjan = [&](int u) 
        {
            stk.push_back(u);
            dfn[u]=low[u]=now++;
            for(auto v:e[u]) 
            {
                if(dfn[v]==-1) 
                {
                    tarjan(v);
                    low[u]=min(low[u],low[v]);
                } 
                else if(id[v]==-1) 
                {
                    low[u]=min(low[u],dfn[v]);
                }
            }
            if(dfn[u]==low[u]) 
            {
                int v;
                do 
                {
                    v=stk.back();
                    stk.pop_back();
                    id[v]=cnt;
                }while(v!=u);
                ++cnt;
            }
        };
        for(int i=0;i<2*n;++i) if(dfn[i]==-1) tarjan(i);
        for (int i=0;i<n;++i) 
        {
            if(id[2*i]==id[2*i+1]) return false;
            ans[i]=id[2*i]>id[2*i+1];
        }
        return true;
    }
    //返回一种 (x1,...,xn) 的合法解
    vector<bool> answer() {return ans;}
};
int main()
{
    ios::sync_with_stdio(false);cin.tie(0),cout.tie(0);
    auto solve=[&]()->void
    {
        int n,m;cin>>n>>m;
        vector<string> s(n);
        vector<vector<int>> pos(m);
        for(int i=0;i<n;++i) cin>>s[i];
        TwoSat st(n);
        vector<vector<int>> nex(n);
        mint res=1;
        for(int j=0;j<m;++j)
        {
            for(int i=0;i<n;++i) if(s[i][j]=='1') pos[j].push_back(i);
            if(2<(int)pos[j].size()) return cout<<"0\n",void();
            if(2==(int)pos[j].size()) 
            {
                //cout<<"**"<<pos[j][0]<<' '<<pos[j][1]<<'\n';
                nex[pos[j][0]].push_back(pos[j][1]);
                nex[pos[j][1]].push_back(pos[j][0]);
                st.addClause(pos[j][0],1,pos[j][1],1);
                st.addClause(pos[j][0],0,pos[j][1],0);
            }
        }
        for(int j=0,k=m-1;j<=k;++j,--k)
        {
            for(auto &x:pos[j])
            {
                for(auto &y:pos[k])
                {
                    if(x==y) continue;
                    if(j==k) return cout<<"0\n",void();
                    //cout<<"^^"<<x<<' '<<y<<'\n';
                    nex[x].push_back(y);
                    nex[y].push_back(x);
                    st.addClause(x,0,y,1);
                    st.addClause(x,1,y,0);
                }
            }
        }
        if(!st.satisfiable()) return cout<<"0\n",void();
        vector<bool> f(n,0);
        auto dfs=[&](auto self,int x)->void
        {
            for(auto &it:nex[x])
            {
                if(!f[it])
                {
                    f[it]=true;
                    self(self,it);
                }
            }
        };
        for(int i=0;i<n;++i)
        {
            if(!f[i])
            {
                res*=2;
                f[i]=true;
                dfs(dfs,i);
            }
        }
        cout<<res<<'\n';
        /*
        int n;cin>>n;TwoSat st(n+1);
        vector<vector<int>> a(2,vector<int>(n));
        for(int i=0;i<2;++i) for(int j=0;j<n;++j) cin>>a[i][j];
        for(int i=0,x;i<n;++i)
        {
            cin>>x;
            st.addClause(abs(a[0][i]),a[0][i]>0,abs(a[1][i]),a[1][i]>0);
            st.addClause(abs(a[0][i]),a[0][i]>0,abs(x),x>0);
            st.addClause(abs(a[1][i]),a[1][i]>0,abs(a[0][i]),a[0][i]>0);
            st.addClause(abs(a[1][i]),a[1][i]>0,abs(x),x>0);
            st.addClause(abs(x),x>0,abs(a[0][i]),a[0][i]>0);
            st.addClause(abs(x),x>0,abs(a[1][i]),a[1][i]>0);
        }
        if(!st.satisfiable()) cout<<"NO\n";
        else cout<<"YES\n";
        */
    };
    int T=1;cin>>T;
    while(T--) solve();
}
/*
1
4 5
10000
00001
01000
00010
*/