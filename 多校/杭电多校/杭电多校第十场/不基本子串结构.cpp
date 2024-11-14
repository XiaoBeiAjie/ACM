#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
using ull=unsigned long long;
int len;
struct Kmp
{
    string s,p;
    vector<int> nxt;
    Kmp(string ss,string pp)
    {
        s=ss;p=pp;
        nxt.resize(s.size());
    }
    void kmp1()
    {
        int i,j,n=s.size(),m=p.size();
        for(nxt[0]=j=-1,i=1;i<n;nxt[i++]=j)
        {
            while(~j&&s[j+1]!=s[i]) j=nxt[j];
            if(s[j+1]==s[i]) ++j;
        }
        int cnt=0;
        for(j=-1,i=0;i<m;++i)
        {
            while(~j&&s[j+1]!=p[i]) j=nxt[j];
            if(s[j+1]==p[i]) ++j;
            if(j==n-1) 
            {
                ++cnt;//pre=i;
                j=nxt[j];//匹配成功位置(末尾)
            }
        }
        if(cnt>1) len=-1;
        if(cnt==1) len=max(n,m);
    }
    
};
void solve() {
    string s,p;cin>>s>>p;
    int n=s.length(),m=p.length();
    len=0;
    if(n<=m) {Kmp f(s,p);f.kmp1();}
    else {Kmp f(p,s);f.kmp1();}
    if(len) return cout<<len<<'\n',void();
    mt19937_64 rnd(time(NULL));
    uniform_int_distribution<ull> make(0,(ull)1<<63);
    vector<ull> hsh(26);
    for(int i=0;i<26;++i) hsh[i]=make(rnd);
    vector<ull> s1(n+1),s2(m+1);
    s1[0]=s2[0]=0;
    for(int i=0;i<n;++i) s1[i+1]=s1[i]^hsh[s[i]-'a'];
    for(int i=0;i<m;++i) s2[i+1]=s2[i]^hsh[p[i]-'a'];
    for(int i=1;i<=min(n,m);++i)
    {
        bool t=1;
        if(s1[i]!=(s2[m]^s2[m-i])) t=0;
        
        int d=sqrt(i);
        if(s[0]!=p[m-i]) t=0;
        for(int j=1;j<=i&&t;j+=d)
        {
            if(s[j-1]!=p[m-i+j-1]) t=0;
            //if((s1[j])!=(s2[m-i]^s2[m-i+j])) t=0;
        }
        
        if(t) len=i;
    }
    for(int i=len;i<=min(n,m);++i)
    {
        bool t=1;
        if(s2[i]!=(s1[n]^s1[n-i])) t=0;
        
        int d=sqrt(i);
        if(p[0]!=s[n-i]) t=0;
        for(int j=1;j<=i&&t;j+=d)
        {
            if(p[j-1]!=s[n-i+j-1]) t=0;
            //if((s2[j])!=(s1[n-i]^s1[n-i+j])) t=0;
        }
        if(t) len=i;
    }
    cout<<n+m-len<<'\n';
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("std.in","r",stdin);
    int T; cin >> T;
    while (T -- ) solve();
    return 0;
}