#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
typedef  long long ll;
void solve() {
    string s,p;cin>>s>>p;
    s+=s;
    mt19937_64 rnd(0);
    uniform_int_distribution<ll> make(0,(ll)1<<62);
    vector<ll> has(26);
    for(int i=0;i<26;++i) has[i]=make(rnd);
    //for(int i=0;i<26;++i) cout<<has[i]<<" \n"[i==25];
    set<ll> res;
    vector<ll> ha((int)s.size()+1),hp((int)p.size()+1);
    ha[0]=hp[0]=0;
    for(int i=1;i<=(int)s.size();++i)
    {
        ha[i]=ha[i-1]^has[s[i-1]-'A'];
        if(i>=(int)s.size()/2) 
        {
            //cout<<i<<'\n';
            res.insert(ha[i]^ha[i-(int)s.size()/2]);
        }
    }
    int ans=0;
    for(int i=1;i<=(int)p.size();++i)
    {
        hp[i]=hp[i-1]^has[p[i-1]-'A'];
        if(i>=(int)s.size()/2) 
        {
            if(res.count(hp[i]^hp[i-(int)s.size()/2])) ++ans;
        }
    }
    cout<<ans<<'\n';
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T; cin >> T;
    while (T -- ) solve();
    system("pause");
    return 0;
}