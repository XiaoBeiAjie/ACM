#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    int n,m;cin>>n>>m;
    int sum=1;
    for(int i=1;i<=n;++i) sum*=10;
    vector<array<int,2>> q(m);
    for(int i=0;i<m;++i)
    {
        string s;cin>>s>>q[i][1];
        int t=0;
        for(auto &it:s) t=t*10+it-'0';
        q[i][0]=t;
    }
    vector<int> f(sum,0);
    for(int i=0;i<sum;++i)
    {
        for(int j=0;j<m;++j)
        {
            bool tjj=0;
            auto check=[&]()
            {
                vector<int> d(n+1,0);
                for(int k=n,t=i;k;--k) d[k]=t%10,t/=10;
                int mx=0,cnt=0,mn=0;
                for(int k=n,t=q[j][0];k;--k) 
                {
                    d[k]-=t%10,t/=10;
                    mn=min(mn,d[k]);
                    mx=max(mx,d[k]);
                }
                while(mx!=0)
                {
                    int po=-1;mx=0;
                    for(int k=1;k<=n;++k) if(d[k]>0) if(po==-1||d[po]>d[k]) po=k;
                    for(int k=po+1;k<=n&&d[k]>0;++k) d[k]-=d[po];
                    for(int k=po-1;k&&d[k]>0;--k) d[k]-=d[po];
                    cnt+=min(d[po],10-d[po]);d[po]=0;
                    for(int k=1;k<=n;++k) mx=max(d[k],mx);
                }
                while(mn!=0)
                {
                    int po=-1;mn=0;
                    for(int k=1;k<=n;++k) if(d[k]<0) if(po==-1||d[po]<d[k]) po=k;
                    for(int k=po+1;k<=n&&d[k]<0;++k) d[k]-=d[po];
                    for(int k=po-1;k&&d[k]<0;--k) d[k]-=d[po];
                    cnt-=max(d[po],-10-d[po]);d[po]=0;
                    for(int k=1;k<=n;++k) mn=min(d[k],mn);
                }
                if(n==1)
                {
                    if(cnt<=q[j][1]&&(q[j][1]-cnt)%2==0) ++f[i],tjj=1;
                } 
                else if(cnt==0)
                {
                    if(q[j][1]>1) ++f[i],tjj=1;
                }
                else 
                {
                    if(cnt<=q[j][1]) ++f[i],tjj=1;
                }
            };
            check();
            auto check1=[&]()
            {
                vector<int> d(n+1,0);
                for(int k=n,t=i;k;--k) d[k]=t%10,t/=10;
                int mx=0,cnt=0,mn=0;
                for(int k=n,t=q[j][0];k;--k) 
                {
                    d[k]-=t%10,t/=10;d[k]=-d[k];
                    mn=min(mn,d[k]);
                    mx=max(mx,d[k]);
                }
                while(mx!=0)
                {
                    int po=-1;mx=0;
                    for(int k=1;k<=n;++k) if(d[k]>0) if(po==-1||d[po]>d[k]) po=k;
                    for(int k=po+1;k<=n&&d[k]>0;++k) d[k]-=d[po];
                    for(int k=po-1;k&&d[k]>0;--k) d[k]-=d[po];
                    cnt+=min(d[po],10-d[po]);d[po]=0;
                    for(int k=1;k<=n;++k) mx=max(d[k],mx);
                }
                while(mn!=0)
                {
                    int po=-1;mn=0;
                    for(int k=1;k<=n;++k) if(d[k]<0) if(po==-1||d[po]<d[k]) po=k;
                    for(int k=po+1;k<=n&&d[k]<0;++k) d[k]-=d[po];
                    for(int k=po-1;k&&d[k]<0;--k) d[k]-=d[po];
                    cnt-=max(d[po],-10-d[po]);d[po]=0;
                    for(int k=1;k<=n;++k) mn=min(d[k],mn);
                }
                if(n==1)
                {
                    if(cnt<=q[j][1]&&(q[j][1]-cnt)%2==0) ++f[i],tjj=1;
                } 
                else if(cnt==0)
                {
                    if(q[j][1]>1) ++f[i],tjj=1;
                }
                else 
                {
                    if(cnt<=q[j][1]) ++f[i],tjj=1;
                }
            };
            if(!tjj) check1();
        }
    }
    vector<int> ans;
    for(int i=0;i<sum;++i) if(f[i]==m) 
    {
        //cout<<i<<'\n';
        ans.push_back(i);
    }
    if(ans.empty()) cout<<"IMPOSSIBLE\n";
    else if((int)ans.size()>1) cout<<"MANY\n";
    else 
    {
        string res="";
        for(int i=1,t=ans[0];i<=n;++i) 
        {
            char ch=t%10+'0';
            t/=10;res+=ch;
        } 
        reverse(res.begin(),res.end());
        cout<<res<<'\n';
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T; cin >> T;
    while (T -- ) solve();
    return 0;
}