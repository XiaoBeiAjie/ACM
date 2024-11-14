#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
typedef long long ll;
vector<bool> a((int)1e5+1,0);
void solve() {
    int n;cin>>n;
    int mx;
    for(int i=0;i<n;++i) cin>>mx,a[mx]=1;
    int cnt=0;
    for(int i=mx-1;i;--i)
    {
        if(a[i]) continue;
        int gd=-1;
        for(int j=i;j<=mx&&gd!=1;j+=i)
        {
            if(a[j])
            {
                if(gd==-1) gd=j/i;
                else gd=__gcd(gd,j/i);
            }
        }
        if(gd==1) ++cnt,a[i]=1;
    }
    for(int i=1;i<=mx;++i) a[i]=0;
    if(cnt&1) cout<<"dXqwq\n";
    else cout<<"Haitang\n";
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T; cin >> T;
    while (T -- ) solve();
    system("pause");
    return 0;
}