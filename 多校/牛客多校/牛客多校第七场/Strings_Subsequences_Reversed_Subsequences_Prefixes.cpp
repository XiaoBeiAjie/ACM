#include <bits/stdc++.h>
using namespace std;
const int N = 1000100;
typedef long long ll;
const int mod = 1e9 + 7;
int ct[N];
struct Mana
{
    string s;
    vector<int> f,g;
    Mana(string ss)
    {
        s=ss;f.resize(2*ss.size()+3);
        g.resize(2*ss.size()+3);f[0]=0;
    }
    void Manacher(ll &res) 
    {
        int tot=s.length();
        string ps="$";ps+='#';
        for(auto &it:s) ps+=it,ps+='#';
        ps+='@';
        int i,r,p,m=ps.size();
        for(r=p=0,f[1]=1,i=2;i<m;++i)
        {
            for(f[i]=r>i?min(r-i,f[2*p-i]):1;ps[i-f[i]]==ps[i+f[i]];f[i]++);
            if(i+f[i]>r) r=i+f[i],p=i;
        }
        for(i=0;i<m;++i) g[i]=0;
        for(i=2;i<m;++i) g[i-f[i]+1]=max(g[i-f[i]+1],i+1);
        for(i=1;i<=m;++i) g[i]=max(g[i],g[i-1]);
        //for(i=2;i<m-1;i+=2) cout<<g[i]-i<<' ';//以i开头maxlen
        for(i=2;i<m-1;i+=2)
        {
            if(g[i]-i==tot) res=(res+1)%mod;
            if(g[i]-i==tot) 
            {
                ct[tot]++;
            }
            --tot;
        }
    }
};
void solve()
{
    int n, m;
    cin >> n >> m;
    string s, p;
    cin >> s >> p;
    int l = -1, cur = 0;
    for (int i = 0; i < n; ++i)
    {
        if (s[i] == p[cur])
            ++cur;
        if (cur == m)
        {
            l = i;
            break;
        }
    }
    if (l == -1)
        return cout << 0 << '\n', void();
    int r = -1;
    cur = 0;
    for (int i = n - 1; ~i; --i)
    {
        if (s[i] == p[cur])
            ++cur;
        if (cur == m)
        {
            r = i;
            break;
        }
    }
    if (r == -1)
        return cout << 0 << '\n', void();
    ll ans=0;
    if (r >= l+1)
    {
        ++l;--r;
        string pp = "*";
        for (int i = l; i <= r; ++i)
            pp += s[i];
        int nn=r-l+1;
        vector<ll> dp(nn+1);
        dp[0]=1;
        vector<int> have(26,0);
        for (int i = 1; i <= nn; i++)
        {
            int t=pp[i]-'a';
            if(have[t]>0) dp[i]=(((dp[i - 1] * 2) - (dp[have[t] - 1])) % mod + mod) % mod;
            else dp[i] = (dp[i - 1] * 2) % mod;
            have[t] = i;
        }
        //cout<<dp[nn]<<'\n';
        ans=dp[nn];
        --l;++r;
    }
    if(r>=l+1)
    {
        Mana man(p);
        man.Manacher(ans);
    }
    else
    {
        Mana man(p);
        man.Manacher(ans);
        int c = 0;
        for(int i = l ; i >= r; i--)
            if(s[i] == p[m - c - 1]) c++;
        int cnt = 0;
        for(int i = 0 ; i < c; i++)
            cnt += ct[i];
        ans = (ans + mod - cnt) % mod;
    }
    cout<<ans<<'\n';
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T = 1; // cin >> T;
    while (T--)
        solve();
    //system("pause");
    return 0;
}