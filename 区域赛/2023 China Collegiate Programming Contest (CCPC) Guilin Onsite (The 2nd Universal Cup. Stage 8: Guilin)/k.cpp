#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n,m;cin>>n>>m;
    auto solve1=[&]()
    {
        vector<vector<int>> g(m,vector<int>(n));
        for(int i=0;i<m;++i) for(int j=0;j<n;++j) cin>>g[i][j]; 
        set<vector<int>> f;
        for(int i=0;i<m;++i)
        {
            set<vector<int>> ff;
            for(auto it:f)
            {
                vector<int> a=it;
                vector<int> b=g[i];
                vector<int> c(n);
                for(int i=0;i<n;++i) c[i]=a[b[i]-1];
                ff.insert(c);
            }
            for(auto &it:ff) f.insert(it);
            f.insert(g[i]);
        }
        cout<<f.size()<<'\n';
    };
    auto solve2=[&]()
    {
        vector<vector<int>> g(m,vector<int>(n));
        for(int i=0;i<m;++i) for(int j=0;j<n;++j) cin>>g[i][j]; 
        set<vector<int>> ans;
        for(int i=1;i<(1<<m);++i)
        {
            vector<int> a;
            vector<int> b;
            vector<int> c(n);
            for(int j=0;j<m;++j)
            {
                if((i>>j)&1)
                {
                    if(a.empty()) a=g[j];
                    else
                    {
                        b=g[j];
                        for(int i=0;i<n;++i) c[i]=(a[b[i]-1]);
                        a=c;
                    }
                }
            }
            ans.insert(a);
        }
        cout<<ans.size()<<'\n';
    };
    if(n<10) solve1();
    else solve2();
}