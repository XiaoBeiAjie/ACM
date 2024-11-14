#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
typedef long long LL;

void solve() {
    int n,x,y;cin>>n>>x>>y;
    map<array<int,2>,queue<int>> f;
    int xx=0,yy=0;
    vector<array<int,2>> g(n);
    string s;cin>>s;
    for(int i=0;i<n;++i)
    {
        if(s[i]=='A') --xx;
        else if(s[i]=='D') ++xx;
        else if(s[i]=='W') ++yy;
        else --yy;
        f[{xx,yy}].push(i);
        g[i]={xx,yy};
    }
    LL ans=0;
    for(int i=0;i<n;++i)
    {
        xx=g[i][0]+x;yy=g[i][1]+y;
        if(f.find({xx,yy})!=f.end())
        {
            ans+=n-f[{xx,yy}].front();
        }
        f[g[i]].pop();
    }
    cout<<ans<<'\n';
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1; //cin >> T;
    while (T -- ) solve();
    system("pause");
    return 0;
}