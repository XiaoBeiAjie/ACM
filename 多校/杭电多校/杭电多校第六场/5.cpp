#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
typedef long long ll;

void solve() {
    int n,m,M;cin>>n>>m>>M;
    int t=3;for(int i=1;i<m;++i) t*=3;
    vector<bool> vis(t,0);
    vector<ll> dp(t,0);
    dp[0]=1%M;vis[0]=1;
    auto get=[&](int x)->string
    {
        string res="";
        for(int i=0;i<m;++i)
        {
            res+='A'+x%3;
            x/=3;
        }
        reverse(res.begin(),res.end());
        return res;
    };
    for(int i=0;i<n;++i)
    {
        string s;cin>>s;
        vector<ll> dp1(t,0);
        vector<bool> vis1(t,0);
        for(int k=0;k<t;++k)
        {
            ll it=dp[k];
            if(!vis[k]) continue;
            string p=get(k);
            for(int j=0;j<m;++j) 
            {
                if(s[j]=='0') continue;
                if(s[j]=='-')
                {
                    if(p[j]=='A') p[j]='C';
                    else --p[j];
                }
                else
                {
                    if(p[j]=='C') p[j]='A';
                    else ++p[j];
                }
            }
            int cur=0;
            for(int j=0;j<m;++j) cur=cur*3+p[j]-'A';
            dp1[cur]+=it;vis1[cur]=true;
        }
        for(int k=0;k<t;++k) 
        {
            dp[k]+=dp1[k],dp[k]%=M;
            if(vis1[k]) vis[k]=1;
        }
    }
    for(int i=0;i<t;++i) 
    {
        if(vis[i]) cout<<get(i)<<' '<<dp[i]<<'\n';
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T; cin >> T;
    while (T -- ) solve();
    system("pause");
    return 0;
}