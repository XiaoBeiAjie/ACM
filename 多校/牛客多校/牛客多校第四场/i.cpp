#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
typedef long long ll;

void solve() {
    int n,m;cin>>n>>m;
    vector<array<int,2>> a(m);
    for(int i=0;i<m;++i)
    {
        cin>>a[i][0]>>a[i][1];
        if(a[i][0]>a[i][1]) swap(a[i][0],a[i][1]);
    }
    sort(a.begin(),a.end());
    ll ans=0;
    vector<int> cnt(n+1,0);
    for(int r=1,l=1,i=0;r<=n;++r)
    {
        vector<int> ll;
        ll.push_back(-2);
        while(i<m&&a[i][1]<r) ++i;
        while(i<m&&a[i][1]==r)
        {
            ll.push_back(a[i][0]);
            ++i;
        }
        ll.push_back(r);
        for(int j=ll.size()-1;;--j)
        {
            if(ll[j-1]+1!=ll[j])
            {
                l=max(ll[j],l);
                break;
            }
        }
        //for(auto &it:ll) cout<<it<<' ';
        //cout<<'\n';
        ans+=r-l+1;
        //cout<<ans<<'\n';
    }
    cout<<ans<<'\n';
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1; 
    while (T -- ) solve();
    system("pause");
    return 0;
}