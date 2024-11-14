#include <bits/stdc++.h>
using namespace std;
const int N = 500010;
#define endl "\n"
typedef long long ll;
int a[N/2];
int b[N];
void solve() {
    int n,q;
    cin >> n >> q;
    int p=1;
    ll ans=0;
    for(int i = 0; i < n; i++)
        cin >> a[i],ans+=a[i];
    for(int i = 0 ; i < n ; i++)
        cin >> b[i],b[i+n]=b[i];
    for(int j = 0,k; j < q; j++)
    {
        cin>>k;
        for(int kk=0;kk<8e2;++kk)
        {
            p=p*7+rand();p%=n;
            int t=p;
            if(a[t]<b[t+k])
            {
                ans-=a[t];
                ans+=a[t]=b[t+k];
            }
        }
        cout<<ans<<'\n';
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T; cin >> T;
    while (T -- ) solve();
    //system("pause");
    return 0;
}