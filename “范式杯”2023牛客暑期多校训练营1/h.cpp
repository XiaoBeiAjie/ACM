#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    auto solve=[]()->void
    {
        int n;cin>>n;
        vector<array<int,2>> f(n); 
        vector<array<int,2>> s,t;
        ll sum=0;
        for(int i=0;i<n;++i) cin>>f[i][0];
        for(int i=0;i<n;++i) 
        {
            cin>>f[i][1];
            if(f[i][1]<f[i][0]) 
            {
                swap(f[i][0],f[i][1]);
                s.push_back(f[i]);
            }
            else t.push_back(f[i]);
            sum+=f[i][1]-f[i][0];
        }
        if(n==1) return cout<<sum<<'\n',void();
        sort(s.begin(),s.end());
        sort(t.begin(),t.end());
        int mx=0,p=0,mr=0;
        for(auto [x,y]:s)
        {
            while(p<(int)t.size()&&t[p][0]<=x) mr=max(mr,t[p++][1]);
            mx=max(mx,min(mr,y)-x);
        }
        p=0;mr=0;
        for(auto [x,y]:t)
        {
            while(p<(int)s.size()&&s[p][0]<=x) mr=max(mr,s[p++][1]);
            mx=max(mx,min(mr,y)-x);
        }
        cout<<sum-2*mx<<'\n';
    };
    solve();
}