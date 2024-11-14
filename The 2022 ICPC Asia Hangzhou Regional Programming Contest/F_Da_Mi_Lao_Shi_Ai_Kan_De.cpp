#include <bits/stdc++.h>
using namespace std;
using ll = long long;
struct DoubleHash 
{
    const int n;
    const ll Base1=131,MOD1=1e9+7;
    const ll Base2=13131,MOD2=998244353;
    vector<ll>ha1,ha2,pow1,pow2;
    vector<ll> rha1,rha2;
    DoubleHash(string s,int n1):n(n1),ha1(n+1),ha2(n+1),pow1(n+1),pow2(n+1),rha1(n+1),rha2(n+1) 
    {
        pow1[0]=pow2[0]=1;
        for(int i=1;i<=n;++i) 
        {
            pow1[i]=pow1[i-1]*Base1%MOD1;
            pow2[i]=pow2[i-1]*Base2%MOD2;
        }
        s='^'+s;
        ha1[0]=ha2[0]=rha1[0]=rha2[0]=0;
        for(int i=1;i<=n;++i) 
        {
            ha1[i]=(ha1[i-1]*Base1+s[i])%MOD1;
            ha2[i]=(ha2[i-1]*Base2+s[i])%MOD2;
            rha1[i]=(rha1[i-1]*Base1+s[n-i+1])%MOD1;
            rha2[i]=(rha2[i-1]*Base2+s[n-i+1])%MOD2;
        }
    }
    pair<ll,ll> get(int l,int r) 
    {
        ll res1=((ha1[r]-ha1[l-1]*pow1[r-l+1])%MOD1+MOD1)%MOD1;
        ll res2=((ha2[r]-ha2[l-1]*pow2[r-l+1])%MOD2+MOD2)%MOD2;
        return {res1,res2};
    }
    //反哈希
    pair<ll,ll> get_rhash(int l,int r) 
    {
        ll res1=((rha1[n-l+1]-rha1[n-r]*pow1[r-l+1])%MOD1+MOD1)%MOD1;
        ll res2=((rha2[n-l+1]-rha2[n-r]*pow2[r-l+1])%MOD2+MOD2)%MOD2;
        return {res1,res2};
    }
    //判断s[l, r]是否为回文串
    bool is_palindrome(int l,int r) 
    {
        return get(l,r)==get_rhash(l,r);
    }
    pair<ll,ll> add(pair<ll,ll> aa,pair<ll,ll> bb) 
    {
        ll res1=(aa.first+bb.first)%MOD1;
        ll res2=(aa.second+bb.second)%MOD2;
        return {res1,res2};
    }
    //aa *= Base的k次方
    pair<ll,ll> mul(pair<ll,ll> aa,ll kk) 
    {
        ll res1=aa.first*pow1[kk]%MOD1;
        ll res2=aa.second*pow2[kk]%MOD2;
        return {res1,res2};
    }
    //拼接字符串 r1 < l2  s = s1 + s2
    pair<ll,ll> link(int l1,int r1,int l2,int r2)
    {
        return add(mul(get(l2,r2),r1-l1+1),get(l1,r1));
    }
};
void solve() {
    int n;cin>>n;
    set<pair<ll,ll>> se;
    for(int i=0,m;i<n;++i)
    {
        cin>>m;
        bool t=0;
        while(m--)
        {
            string s;cin>>s;
            bool tt=0;
            for(int i=2;i<(int)s.length()&&!tt;++i)
            {
                if(s[i]=='e'&&s[i-1]=='i'&&s[i-2]=='b') tt=1;
            }
            if(tt)
            {
                DoubleHash hsh(s,s.length());
                auto cur=hsh.get(1,(int)s.length());
                if(se.count(cur)) continue;
                t=1;se.insert(cur);
                cout<<s<<'\n';
            }
        }
        if(!t) cout<<"Time to play Genshin Impact, Teacher Rice!\n";
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T=1; //cin >> T;
    while (T -- ) solve();
    return 0;
}