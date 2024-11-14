#include <bits/stdc++.h>

using namespace std;
const int N = 100010;
typedef long long LL;

int T;

void solve() {
    int n,x;cin>>n>>x;
    vector<int> b(n,n);
    vector<int> f(n);
    set<int> pos[n];
    for(int i=0;i<n;++i) cin>>f[i],f[i]=(f[i]+i)%n;
    pos[1].insert(f[0]);b[f[0]]=1;
    for(int i=1;i<n;++i)
    {
        //cout<<i+1<<' ';
        for(auto &it:pos[i])
        {
            if(b[f[it]]>b[it]+1)
            {
                if(b[f[it]]!=n) pos[b[f[it]]].erase(f[it]);
                b[f[it]]=b[it]+1;
                pos[b[f[it]]].insert(f[it]);
                //cout<<f[it]<<' ';
            }
            if(b[(it+1)%n]>b[it]+1)
            {
                if(b[(it+1)%n]!=n) pos[b[(it+1)%n]].erase((it+1)%n);
                b[(it+1)%n]=b[it]+1;
                pos[b[(it+1)%n]].insert((it+1)%n);
                //cout<<(it+1)%n<<' ';
            }
        }
        //cout<<'\n';
    }
    
    cout<<b[x]<<'\n';
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    T=1;
    while (T -- ) solve();
    //system("pause");
    return 0;
}
/*
8 7
4 0 5 0 0 5 0 0
8 7
4 0 5 0 0 0 4 0
*/