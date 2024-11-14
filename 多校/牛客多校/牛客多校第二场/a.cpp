#include <bits/stdc++.h>
using namespace std;
const int N = 2e3;
typedef long long LL;
#define endl "\n"
void solve() {
    int n , m , k;
    cin >> n >> m >> k;
    int px, py;
    char pc;
    cin >> px >> py >> pc;
    vector<string> ans(n+1,"");
    bool tag=true;
    for(int i = 1; i <= m; i++) ans[1]+='A';
    k-=m+1;
    if(k<0) tag=false;
    for(int i=2;i<=n&&tag;++i)
    {
        int t=k-(n-i);
        if(t<=0) tag=false;
        else
        {
            if(t>=(m+1)/2)
            {
                k-=(m+1)/2;
                for(int j=1;j<=m;++j)
                {
                    if(j&1) ans[i]+='A';
                    else ans[i]+='B';
                }
            }
            else if(t==1)
            {
                for(int j=1;j<=m;++j) ans[i]+='A';
                --k;
            }
            else
            {
                k-=t;
                for(int j=1;j<=t;++j)
                {
                    ans[i]+='A';
                    ans[i]+='B';
                }
                for(int j=2*t+1;j<=m;++j)
                {
                    ans[i]+='B';
                }
            }
        }
    }
    if(k) tag=false;
    if(tag)
    {
        cout<<"Yes\n";
        if(ans[px][py]!=pc)
        {
            for(int j=1;j<=m;++j)
            {
                if(ans[px][j]=='A') ans[px][j]='B';
                else ans[px][j]='A';
            }
        }
        for(int i=1;i<=n;++i) cout<<ans[i]<<"\n";
    }
    else cout<<"No\n";
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T; cin >> T;
    while (T -- ) solve();
    system("pause");
    return 0;
}