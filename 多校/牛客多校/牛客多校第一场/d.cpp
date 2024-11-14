#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
typedef long long ll;

void solve() {
    int n;cin>>n;
    int cnt=0;ll ans=0,sum=0;
    stack<int> st;
    for(int i=0,t,v;i<n;++i)
    {
        cin>>t>>v;
        for(int j=0;j<t;++j)
        {
            ans-=1ll*cnt*st.top();
            st.pop();--cnt;
        }
        ++cnt;ans+=1ll*v*cnt;
        st.push(v);
        cout<<ans<<'\n';
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1; //cin >> T;
    while (T -- ) solve();
    system("pause");
    return 0;
}