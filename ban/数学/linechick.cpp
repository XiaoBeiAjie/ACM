#include <bits/stdc++.h>
using ull =unsigned long long;
using namespace std;
struct Linechick
{
    vector<ull> p;
    int rank;
    Linechick(){p.resize(64,0);rank=0;}
    void insert(ull x) 
    {
        for(int i=63;~i;--i) 
        {
            if(!(x>>i)) continue;
            if(!p[i]) {p[i]=x;++rank;break;}
            x^=p[i];
        }
    }
    ull getmax(ull ans=0)
    {
        for(int i=63;~i;--i) ans=max(ans,ans^p[i]);
        return ans;
    }
    int check(ull x,int tot=0)
    {
        for(int i=63;~i;--i)
        {
            if(x>>i&1ll) x^=p[i];
            if(p[i]) ++tot;
        }
        return x?-1:tot;
    }
};
int main() 
{
    int n,m;cin>>n;ull a;Linechick lck;m=n;
    while(n--) cin>>a,lck.insert(a);
    cout<<lck.getmax()<<'\n';
    cin>>n;
    while(n--)
    {
        cin>>a;int t=lck.check(a);
        if(t==-1) cout<<-1<<'\n';
        else cout<<((ull)1<<(m-t))<<'\n';//构造方案数
    }
}