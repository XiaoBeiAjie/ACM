#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
typedef long long ll;

void solve() {
    int a,b,c;cin>>a>>b>>c;
    if(a+b==c) return cout<<"-1\n",void();
    if(a+b<c) return cout<<"0\n",void();
    int d=a+b-c,ans=0;
    vector<int> aa(32,0);
    for(int k=1;k*k<=d;++k)
    {
        if(d%k) continue;
        int ta=a,tb=b;
        ll t=1,cur=0;
        if(k!=1)
        {
            for(int i=0;i<32&&(ta||tb);++i)
            {
                aa[i]=ta%k+tb%k;
                ta/=k;tb/=k;aa[i]%=k;
                if(aa[i]) cur+=t*aa[i],aa[i]=0;
                t*=k;
            }
            if(cur==c) ++ans;
        }
        if(k*k==d) continue;
        k=d/k;
        if(k!=1)
        {
            t=1,cur=0;ta=a;tb=b;
            for(int i=0;i<30&&(ta||tb);++i)
            {
                aa[i]=ta%k+tb%k;
                ta/=k;tb/=k;aa[i]%=k;
                if(aa[i]) cur+=t*aa[i],aa[i]=0;
                t*=k;
            }
            if(cur==c) ++ans;
        }
        k=d/k;
    }
    cout<<ans<<'\n';
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T; cin >> T;
    while (T -- ) solve();
    system("pause");
    return 0;
}