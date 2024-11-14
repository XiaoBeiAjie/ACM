#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    int n,k;cin>>n>>k;
    vector<int> a(n),b(n),laz(n);
    priority_queue<array<int,3>> qu;
    for(int i=0;i<n;++i)
    {
        cin>>a[i]>>b[i];
        a[i]+=k*b[i];
        qu.push({a[i],-b[i],i});
    }
    ll sum=0;
    while(k--)
    {
        
    }
    cout<<sum<<'\n';
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T; cin >> T;
    while (T -- ) solve();
    return 0;
}