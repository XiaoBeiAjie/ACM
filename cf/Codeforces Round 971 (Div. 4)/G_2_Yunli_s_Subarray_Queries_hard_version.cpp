#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n,k,q;
    cin>>n>>k>>q;
    vector<int> a(n+1);
    for (int i=1;i<=n;++i){
        cin>>a[i];
        a[i]-=i;
    }
    map<int,int> cnt;
    multiset<int> st;
    vector<int> f(n+1);
    auto cg=[&](int a,int b){
        if (st.find(cnt[a])!=st.end())
            st.erase(st.find(cnt[a]));
        cnt[a]+=b;
        st.insert(cnt[a]);
    };
    for (int i=1;i<=n;++i){
        cg(a[i],1);
        if (i>k){
            cg(a[i-k],-1);
            f[i-k]=k-*st.rbegin();
        }
    }
    
    while (q--){
        int l,r;
        cin>>l>>r;
        cout<<f[l]<<endl;
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin>>t;
    while (t--)
        solve();
}