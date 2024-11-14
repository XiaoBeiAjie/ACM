#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
typedef long long ll;

void solve() {
    int n,l,r,cnt=0;
    ll sum=0;
    cin>>n>>l>>r;
    vector<ll> f;
    for(int i=0;i<n;++i)
    {
        int x;cin>>x;
        if(x>2) 
        {
            ++cnt;
            sum+=(x-1)/2;
            f.push_back((x-1)/2);
        }
    }
    if(n<=r) cout<<"Yes\n";
    else
    {
        if(cnt<l) return cout<<"No\n",void();
        sort(f.begin(),f.end());
        reverse(f.begin(),f.end());
        int ned=(n-r+r-l-1)/(r-l);
        priority_queue<ll,vector<ll>,greater<ll>> cur;
        for(int i=0;i<l-1;++i) cur.push(f[i]);
        ll pre=0,ss=0;
        for(int i=l-1;i<cnt;++i)
        {
            cur.push(pre+f[i]);
            ll st=cur.top();cur.pop();
            if(st>=pre)
            {
                ss+=st-pre;
                pre=st;
            }
            //pre+=f[i];
            cout<<ss<<'\n';
            if(ss>=ned) 
            {
                cout<<"Yes\n";
                //return cout<<"Yes\n",void();
            }
        }
        cout<<"No\n";
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